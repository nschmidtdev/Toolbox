#pragma once

#include <atomic>
#include <filesystem>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

class LuaRunner {
public:
    using CompletionCallback = std::function<void(bool)>;

    struct RunResult {
        bool started = false;
        bool singleInstance = false;
    };

    struct TaskStatus {
        bool singleInstance = false;
        bool running = false;
    };

    RunResult run(const std::string& taskId, const std::filesystem::path& scriptPath,
                  int timeoutSeconds, CompletionCallback onComplete);
    TaskStatus status(const std::string& taskId, const std::filesystem::path& scriptPath) const;
    void cancel(const std::string& taskId) const;
    void shutdown() const;

    ~LuaRunner();

private:
    struct LuaTask {
        std::shared_ptr<std::atomic_bool> cancel;
        std::shared_ptr<std::atomic_bool> executionFinished;
        std::shared_ptr<std::atomic_bool> callbackFinished;
        bool singleInstance = false;
        std::jthread worker;

        LuaTask(std::shared_ptr<std::atomic_bool> cancelFlag,
                std::shared_ptr<std::atomic_bool> executionFinishedFlag,
                std::shared_ptr<std::atomic_bool> callbackFinishedFlag,
                bool isSingleInstance)
            : cancel(std::move(cancelFlag)),
              executionFinished(std::move(executionFinishedFlag)),
              callbackFinished(std::move(callbackFinishedFlag)),
              singleInstance(isSingleInstance) {}
    };

    struct State {
        std::mutex tasksMutex;
        std::unordered_map<std::string, std::vector<LuaTask>> tasks;
    };

    std::shared_ptr<State> m_state = std::make_shared<State>();
};
