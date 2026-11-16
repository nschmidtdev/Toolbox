#include "lua/luaRunner.h"

#include <cassert>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <future>

namespace {

bool runScript(LuaRunner& runner, const std::string& taskId, const std::filesystem::path& path) {
    std::promise<bool> completion;
    auto result = completion.get_future();
    const auto started = runner.run(taskId, path, 5, [&completion](bool success) {
        completion.set_value(success);
    });
    assert(started.started);
    assert(result.wait_for(std::chrono::seconds(10)) == std::future_status::ready);
    return result.get();
}

} // namespace

int main() {
    const auto stamp = std::chrono::steady_clock::now().time_since_epoch().count();
    const auto root = std::filesystem::temp_directory_path() /
        std::filesystem::u8path("toolbox-unicode-工具-" + std::to_string(stamp));
    std::filesystem::create_directories(root);

    const auto validScript = root / std::filesystem::u8path("gültig.lua");
    const auto invalidScript = root / std::filesystem::u8path("fehler.lua");
    const auto longRunningScript = root / std::filesystem::u8path("langlaufend.lua");
    const auto singleInstanceScript = root / std::filesystem::u8path("einzelinstanz.lua");
    std::ofstream(validScript, std::ios::binary) << "local answer = 21 * 2\nassert(answer == 42)\n";
    std::ofstream(invalidScript, std::ios::binary) << "error('expected failure')\n";
    std::ofstream(longRunningScript, std::ios::binary) << "while true do end\n";
    std::ofstream(singleInstanceScript, std::ios::binary)
        << "-- toolbox: single-instance\r\nwhile true do end\r\n";

    LuaRunner runner;
    assert(runScript(runner, "valid-tool", validScript));
    assert(!runScript(runner, "invalid-tool", invalidScript));

    std::promise<bool> longRunningCompletion;
    auto longRunningResult = longRunningCompletion.get_future();
    runner.run("C:/tools/first", longRunningScript, 0, [&longRunningCompletion](bool success) {
        longRunningCompletion.set_value(success);
    });
    assert(runScript(runner, "C:/tools/second", validScript));
    assert(longRunningResult.wait_for(std::chrono::milliseconds(50)) == std::future_status::timeout);
    runner.cancel("C:/tools/first");
    assert(longRunningResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    assert(!longRunningResult.get());

    std::promise<bool> singleCompletion;
    auto singleResult = singleCompletion.get_future();
    const auto idleSingleStatus = runner.status("C:/tools/single", singleInstanceScript);
    assert(idleSingleStatus.singleInstance);
    assert(!idleSingleStatus.running);
    const auto firstSingle = runner.run(
        "C:/tools/single", singleInstanceScript, 0,
        [&singleCompletion](bool success) { singleCompletion.set_value(success); });
    const auto duplicateSingle = runner.run(
        "C:/tools/single", singleInstanceScript, 0, [](bool) {});
    assert(firstSingle.started);
    assert(firstSingle.singleInstance);
    assert(!duplicateSingle.started);
    assert(duplicateSingle.singleInstance);
    const auto runningSingleStatus = runner.status("C:/tools/single", singleInstanceScript);
    assert(runningSingleStatus.singleInstance);
    assert(runningSingleStatus.running);
    runner.cancel("C:/tools/single");
    assert(singleResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    assert(!singleResult.get());
    const auto completedSingleStatus = runner.status("C:/tools/single", singleInstanceScript);
    assert(completedSingleStatus.singleInstance);
    assert(!completedSingleStatus.running);

    std::promise<bool> firstParallelCompletion;
    std::promise<bool> secondParallelCompletion;
    auto firstParallelResult = firstParallelCompletion.get_future();
    auto secondParallelResult = secondParallelCompletion.get_future();
    const auto firstParallel = runner.run(
        "C:/tools/parallel", longRunningScript, 0,
        [&firstParallelCompletion](bool success) { firstParallelCompletion.set_value(success); });
    const auto secondParallel = runner.run(
        "C:/tools/parallel", longRunningScript, 0,
        [&secondParallelCompletion](bool success) { secondParallelCompletion.set_value(success); });
    assert(firstParallel.started);
    assert(!firstParallel.singleInstance);
    assert(secondParallel.started);
    assert(!secondParallel.singleInstance);
    assert(firstParallelResult.wait_for(std::chrono::milliseconds(50)) == std::future_status::timeout);
    assert(secondParallelResult.wait_for(std::chrono::milliseconds(50)) == std::future_status::timeout);
    runner.cancel("C:/tools/parallel");
    assert(firstParallelResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    assert(secondParallelResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    assert(!firstParallelResult.get());
    assert(!secondParallelResult.get());

    const auto quickSingleScript = root / std::filesystem::u8path("kurze-einzelinstanz.lua");
    std::ofstream(quickSingleScript, std::ios::binary)
        << "-- toolbox: single-instance\r\nreturn true\r\n";
    std::promise<void> callbackEntered;
    auto callbackEnteredResult = callbackEntered.get_future();
    std::promise<void> releaseCallback;
    auto releaseCallbackResult = releaseCallback.get_future().share();
    std::promise<bool> quickSingleCompletion;
    auto quickSingleResult = quickSingleCompletion.get_future();
    const auto quickSingle = runner.run(
        "C:/tools/quick-single", quickSingleScript, 0,
        [&callbackEntered, releaseCallbackResult, &quickSingleCompletion](bool success) {
            callbackEntered.set_value();
            releaseCallbackResult.wait();
            quickSingleCompletion.set_value(success);
        });
    assert(quickSingle.started);
    assert(callbackEnteredResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    const auto statusDuringCallback = runner.status("C:/tools/quick-single", quickSingleScript);
    auto duplicateDuringCallback = std::async(std::launch::async, [&runner, &quickSingleScript] {
        return runner.run("C:/tools/quick-single", quickSingleScript, 0, [](bool) {});
    });
    const auto duplicateWait = duplicateDuringCallback.wait_for(std::chrono::milliseconds(100));
    releaseCallback.set_value();
    assert(duplicateDuringCallback.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    const auto duplicateDuringCallbackResult = duplicateDuringCallback.get();
    assert(statusDuringCallback.singleInstance);
    assert(!statusDuringCallback.running);
    assert(duplicateWait == std::future_status::ready);
    assert(!duplicateDuringCallbackResult.started);
    assert(duplicateDuringCallbackResult.singleInstance);
    assert(quickSingleResult.wait_for(std::chrono::seconds(5)) == std::future_status::ready);
    assert(quickSingleResult.get());
    runner.shutdown();

    std::filesystem::remove_all(root);
    return 0;
}
