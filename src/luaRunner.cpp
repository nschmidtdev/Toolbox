#include "luaRunner.h"

#include <chrono>
#include <iostream>
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
    auto* hookCtx = *reinterpret_cast<LuaHookContext**>(lua_getextraspace(hookState));
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

} // namespace

void LuaRunner::run(int id, const std::filesystem::path& scriptPath, int timeoutSeconds, CompletionCallback onComplete) {
    auto cancelFlag = std::make_shared<std::atomic_bool>(false);
    auto state = m_state;
    {
        std::lock_guard<std::mutex> lock(state->tasksMutex);
        state->tasks[id] = LuaTask{cancelFlag};
    }

    std::thread([state, id, scriptPath, timeoutSeconds, cancelFlag, onComplete = std::move(onComplete)]() mutable {
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

        LuaHookContext ctx{
            cancelFlag,
            deadlineFromTimeout(timeoutSeconds)
        };

        lua_State* L = lua.lua_state();
        *reinterpret_cast<LuaHookContext**>(lua_getextraspace(L)) = &ctx;
        lua_sethook(L, luaCancelHook, LUA_MASKCOUNT, hookInstructionCount);

        try {
            std::cout << "Running Lua script: " << scriptPath.string() << std::endl;
            lua.script_file(scriptPath.string());
        } catch (const sol::error& e) {
            std::cerr << "Lua error: " << e.what() << std::endl;
        }

        {
            std::lock_guard<std::mutex> lock(state->tasksMutex);
            state->tasks.erase(id);
        }

        if (onComplete) {
            onComplete();
        }
    }).detach();

    std::cout << "Lua-Skript wurde gestartet." << std::endl;
}

void LuaRunner::cancel(int id) {
    auto state = m_state;
    std::lock_guard<std::mutex> lock(state->tasksMutex);
    auto it = state->tasks.find(id);
    if (it != state->tasks.end() && it->second.cancel) {
        it->second.cancel->store(true, std::memory_order_relaxed);
    }
}
