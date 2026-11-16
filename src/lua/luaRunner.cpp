#include "lua/luaRunner.h"
#include "lua/toolLaunchBridge.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <thread>


#include <sol/sol.hpp>

extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

namespace {

constexpr int hookInstructionCount = 10000;

struct LuaHookContext {
    std::shared_ptr<std::atomic_bool> cancel;
    std::chrono::steady_clock::time_point deadline;
};

void luaCancelHook(lua_State* hookState, lua_Debug*) {
    auto* hookCtx = *static_cast<LuaHookContext**>(lua_getextraspace(hookState));
    if (!hookCtx) {
        return;
    }

    if (hookCtx->cancel->load(std::memory_order_relaxed)) {
        luaL_error(hookState, "Lua script cancelled");
    }

    if (hookCtx->deadline != (std::chrono::steady_clock::time_point::max)() &&
        std::chrono::steady_clock::now() > hookCtx->deadline) {
        luaL_error(hookState, "Lua script cancelled or timed out");
    }
}

std::chrono::steady_clock::time_point deadlineFromTimeout(int timeoutSeconds) {
    if (timeoutSeconds <= 0) {
        return (std::chrono::steady_clock::time_point::max)();
    }
    return std::chrono::steady_clock::now() + std::chrono::seconds(timeoutSeconds);
}

std::string pathUtf8(const std::filesystem::path& path) {
    const auto encoded = path.u8string();
    return {reinterpret_cast<const char*>(encoded.data()), encoded.size()};
}

std::string readScript(const std::filesystem::path& scriptPath) {
    std::ifstream input(scriptPath, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Das Lua-Skript konnte nicht geoeffnet werden: " + pathUtf8(scriptPath));
    }
    return {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
}

bool requestsSingleInstance(std::string_view script) {
    std::istringstream lines{std::string(script)};
    std::string line;
    while (std::getline(lines, line)) {
        const auto first = line.find_first_not_of(" \t\r");
        const auto last = line.find_last_not_of(" \t\r");
        if (first != std::string::npos &&
            line.substr(first, last - first + 1) == "-- toolbox: single-instance") {
            return true;
        }
    }
    return false;
}

} // namespace

LuaRunner::~LuaRunner() {
    shutdown();
}

LuaRunner::RunResult LuaRunner::run(const std::string& taskId,
                                    const std::filesystem::path& scriptPath,
                                    int timeoutSeconds, CompletionCallback onComplete) {
    const std::string script = readScript(scriptPath);
    const bool singleInstance = requestsSingleInstance(script);

    auto state = m_state;
    auto cancelFlag = std::make_shared<std::atomic_bool>(false);
    auto executionFinishedFlag = std::make_shared<std::atomic_bool>(false);
    auto callbackFinishedFlag = std::make_shared<std::atomic_bool>(false);
    std::vector<LuaTask> completedTasks;
    {
        std::lock_guard<std::mutex> lock(state->tasksMutex);
        auto& tasks = state->tasks[taskId];
        for (auto task = tasks.begin(); task != tasks.end();) {
            if (task->callbackFinished->load(std::memory_order_acquire)) {
                completedTasks.push_back(std::move(*task));
                task = tasks.erase(task);
            } else {
                ++task;
            }
        }
        const bool activeSingleInstance = std::ranges::any_of(tasks, &LuaTask::singleInstance);
        if (!tasks.empty() && (singleInstance || activeSingleInstance)) {
            return {false, true};
        }

        tasks.emplace_back(cancelFlag, executionFinishedFlag, callbackFinishedFlag, singleInstance);
        tasks.back().worker = std::jthread([
            scriptPath, script, timeoutSeconds, cancelFlag, executionFinishedFlag,
            callbackFinishedFlag, onComplete = std::move(onComplete)
        ](std::stop_token stopToken) mutable {
        sol::state lua;
        lua.open_libraries(sol::lib::base,
                           sol::lib::os,
                           sol::lib::string,
                           sol::lib::coroutine,
                           sol::lib::package,
                           sol::lib::table,
                           sol::lib::math,
                           sol::lib::utf8,
                           sol::lib::io);

        ToolLaunchBridge::registerFunctions(lua);

        LuaHookContext ctx{cancelFlag, deadlineFromTimeout(timeoutSeconds)};

        lua_State* L = lua.lua_state();
        *static_cast<LuaHookContext**>(lua_getextraspace(L)) = &ctx;
        lua_sethook(L, luaCancelHook, LUA_MASKCOUNT, hookInstructionCount);

        bool succeeded = false;
        try {
            if (stopToken.stop_requested()) {
                cancelFlag->store(true, std::memory_order_relaxed);
            }
            std::cout << "Running Lua script: " << pathUtf8(scriptPath) << std::endl;
            const sol::protected_function_result result =
                lua.safe_script(script, sol::script_pass_on_error);
            if (!result.valid()) {
                const sol::error error = result;
                throw error;
            }
            succeeded = true;
        } catch (const std::exception& e) {
            std::cerr << "Lua error: " << e.what() << std::endl;
        }

        executionFinishedFlag->store(true, std::memory_order_release);
        if (onComplete) {
            onComplete(succeeded);
        }
        callbackFinishedFlag->store(true, std::memory_order_release);
        });
    }

    std::cout << "Lua-Skript wurde gestartet." << std::endl;
    return {true, singleInstance};
}

LuaRunner::TaskStatus LuaRunner::status(const std::string& taskId,
                                        const std::filesystem::path& scriptPath) const {
    const bool scriptRequestsSingleInstance = requestsSingleInstance(readScript(scriptPath));
    std::lock_guard<std::mutex> lock(m_state->tasksMutex);
    const auto existing = m_state->tasks.find(taskId);
    if (existing == m_state->tasks.end()) {
        return {scriptRequestsSingleInstance, false};
    }

    bool running = false;
    bool activeSingleInstance = false;
    for (const auto& task : existing->second) {
        if (!task.executionFinished->load(std::memory_order_acquire)) {
            running = true;
            activeSingleInstance = activeSingleInstance || task.singleInstance;
        }
    }
    return {scriptRequestsSingleInstance || activeSingleInstance, running};
}

void LuaRunner::cancel(const std::string& taskId) const
{
    auto state = m_state;
    std::lock_guard<std::mutex> lock(state->tasksMutex);
    auto it = state->tasks.find(taskId);
    if (it != state->tasks.end()) {
        for (auto& task : it->second) {
            task.cancel->store(true, std::memory_order_relaxed);
            task.worker.request_stop();
        }
    }
}

void LuaRunner::shutdown() const
{
    std::unordered_map<std::string, std::vector<LuaTask>> tasks;
    {
        std::lock_guard<std::mutex> lock(m_state->tasksMutex);
        tasks.swap(m_state->tasks);
    }

    for (auto& instances : tasks | std::views::values) {
        for (auto& task : instances) {
            task.cancel->store(true, std::memory_order_relaxed);
            task.worker.request_stop();
        }
    }

    for (auto& instances : tasks | std::views::values) {
        for (auto& task : instances) {
            if (task.worker.joinable()) {
                task.worker.join();
            }
        }
    }
}
