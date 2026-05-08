#pragma once

#include <atomic>
#include <filesystem>
#include <functional>
#include <memory>
#include <mutex>
#include <unordered_map>

class LuaRunner {
public:
    using CompletionCallback = std::function<void()>;

    void run(int id, const std::filesystem::path& scriptPath, int timeoutSeconds, CompletionCallback onComplete);
    void cancel(int id);

private:
    struct LuaTask {
        std::shared_ptr<std::atomic_bool> cancel;
    };

    struct State {
        std::mutex tasksMutex;
        std::unordered_map<int, LuaTask> tasks;
    };

    std::shared_ptr<State> m_state = std::make_shared<State>();
};
