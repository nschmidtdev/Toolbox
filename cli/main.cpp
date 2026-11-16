#include "cli/toolboxCli.h"
#include "core/toolConfig.h"
#include "lua/toolLaunchBridge.h"
#include "core/toolRegistry.h"

#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>
#include <rang.hpp>
#include <sol/sol.hpp>

extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <ranges>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace {

using json = nlohmann::json;

struct LuaHookContext {
    std::chrono::steady_clock::time_point deadline;
};

void timeoutHook(lua_State* state, lua_Debug*) {
    const auto* context = *static_cast<LuaHookContext**>(lua_getextraspace(state));
    if (context && context->deadline != (std::chrono::steady_clock::time_point::max)() &&
        std::chrono::steady_clock::now() > context->deadline) {
        luaL_error(state, "Lua script timed out");
    }
}

std::filesystem::path defaultHome() {
#ifdef _WIN32
    for (const wchar_t* variable : {L"USERPROFILE", L"HOME"}) {
        const DWORD required = GetEnvironmentVariableW(variable, nullptr, 0);
        if (required <= 1) {
            continue;
        }
        std::wstring value(required, L'\0');
        const DWORD written = GetEnvironmentVariableW(variable, value.data(), required);
        if (written > 0 && written < required) {
            value.resize(written);
            return std::filesystem::path(value);
        }
    }
#else
    if (const char* profile = std::getenv("USERPROFILE")) {
        return profile;
    }
    if (const char* home = std::getenv("HOME")) {
        return home;
    }
#endif
    return std::filesystem::current_path();
}

#ifdef _WIN32
std::string wideToUtf8(std::wstring_view value) {
    if (value.empty()) {
        return {};
    }
    const int length = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(),
                                           static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    if (length <= 0) {
        throw std::runtime_error("Command line contains invalid Unicode.");
    }
    std::string result(static_cast<std::size_t>(length), '\0');
    if (WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(),
                            static_cast<int>(value.size()), result.data(), length, nullptr, nullptr) <= 0) {
        throw std::runtime_error("Command line contains invalid Unicode.");
    }
    return result;
}
#endif

void printJson(const json& value) {
    std::cout << value.dump() << '\n';
}

int fail(std::string message, int code = 2) {
    printJson({{"ok", false}, {"error", std::move(message)}});
    return code;
}

std::optional<std::string> optionValue(const std::vector<std::string>& args, std::string_view option) {
    const auto it = std::ranges::find(args, option);
    if (it == args.end() || std::next(it) == args.end()) {
        return std::nullopt;
    }
    return *std::next(it);
}

std::optional<int> parseInt(const std::optional<std::string>& value) {
    if (!value) {
        return std::nullopt;
    }
    try {
        std::size_t consumed = 0;
        const int result = std::stoi(*value, &consumed);
        if (consumed != value->size()) {
            return std::nullopt;
        }
        return result;
    } catch (...) {
        return std::nullopt;
    }
}

std::optional<std::string> readTextFile(const std::filesystem::path& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        return std::nullopt;
    }
    std::ostringstream content;
    content << input.rdbuf();
    return content.str();
}

const ToolboxItem* findTool(const std::vector<ToolboxItem>& tools, const std::string& name) {
    const auto it = std::ranges::find(tools, name, &ToolboxItem::name);
    return it == tools.end() ? nullptr : &*it;
}

int listTools(const std::filesystem::path& home) {
    json tools = json::array();
    for (const auto& tool : ToolRegistry::loadTools(home)) {
        tools.push_back({{"name", tool.name}, {"description", tool.description}});
    }
    printJson({{"ok", true}, {"tools", std::move(tools)}});
    return 0;
}

int createTool(const std::filesystem::path& home, const std::vector<std::string>& args) {
    const auto name = optionValue(args, "--name");
    if (!name) {
        return fail("create requires --name <name>");
    }

    ToolDraft draft;
    draft.name = *name;
    draft.description = optionValue(args, "--description").value_or("");
    draft.luaScript = optionValue(args, "--script").value_or("");

    if (const auto scriptFile = optionValue(args, "--script-file")) {
        const auto script = readTextFile(std::filesystem::u8path(*scriptFile));
        if (!script) {
            return fail("Script file could not be read: " + *scriptFile);
        }
        draft.luaScript = *script;
    }

    if (const auto timeoutValue = optionValue(args, "--timeout")) {
        const auto timeout = parseInt(timeoutValue);
        if (!timeout) {
            return fail("--timeout must be an integer");
        }
        draft.timeoutSeconds = *timeout;
    }

    const auto result = ToolRegistry::createTool(home, draft);
    if (!result.success) {
        return fail(result.message);
    }

    printJson({{"ok", true}, {"message", result.message}, {"tool", draft.name}});
    return 0;
}

json executeLua(const std::filesystem::path& scriptPath, int timeoutSeconds) {
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

    std::string output;
    sol::function tostring = lua["tostring"];
    lua.set_function("print", [&output, tostring](sol::variadic_args values) mutable {
        bool first = true;
        for (const auto value : values) {
            if (!first) {
                output.push_back('\t');
            }
            first = false;
            const sol::protected_function_result converted = tostring(value);
            if (converted.valid()) {
                output += converted.get<std::string>();
            }
        }
        output.push_back('\n');
    });

    LuaHookContext context{
        timeoutSeconds <= 0
            ? (std::chrono::steady_clock::time_point::max)()
            : std::chrono::steady_clock::now() + std::chrono::seconds(timeoutSeconds),
    };
    lua_State* state = lua.lua_state();
    *static_cast<LuaHookContext**>(lua_getextraspace(state)) = &context;
    lua_sethook(state, timeoutHook, LUA_MASKCOUNT, 10000);

    const auto script = readTextFile(scriptPath);
    if (!script) {
        return {{"ok", false}, {"error", "Lua script could not be read."}};
    }
    sol::protected_function_result result = lua.safe_script(*script, sol::script_pass_on_error);
    if (!result.valid()) {
        const sol::error error = result;
        return {{"ok", false}, {"error", error.what()}};
    }
    return {{"ok", true}, {"output", std::move(output)}};
}

int runTool(const std::filesystem::path& home, const std::vector<std::string>& args) {
    if (args.empty()) {
        return fail("run requires a tool name");
    }

    const auto tools = ToolRegistry::loadTools(home);
    const ToolboxItem* tool = findTool(tools, args.front());
    if (!tool) {
        return fail("Tool not found: " + args.front());
    }
    if (tool->lua_script_path_string.empty()) {
        return fail("Tool has no start.lua: " + tool->name);
    }

    const ToolConfigStore config;
    const auto toolPath = std::filesystem::u8path(tool->path);
    const int timeout = std::clamp(
        config.getInt(toolPath / "config.ini", "lua_timeout_seconds", 30), 0, 86400);
    json result = executeLua(std::filesystem::u8path(tool->lua_script_path_string), timeout);
    result["tool"] = tool->name;
    printJson(result);
    return result["ok"].get<bool>() ? 0 : 1;
}

void configureColor(std::string_view mode) {
    if (mode == "always") {
        rang::setControlMode(rang::control::Force);
        rang::setWinTermMode(rang::winTerm::Ansi);
    } else if (mode == "never") {
        rang::setControlMode(rang::control::Off);
    } else {
        rang::setControlMode(rang::control::Auto);
        rang::setWinTermMode(rang::winTerm::Auto);
    }
}

void printHelp() {
    std::cout
        << rang::style::bold << rang::fgB::cyan
        << "  TOOLBOX CLI" << rang::style::reset << rang::fg::reset << '\n'
        << rang::fg::gray << "  Lokale Lua-Werkzeuge verwalten und ausfuehren."
        << rang::fg::reset << "\n\n"
        << rang::style::bold << rang::fgB::yellow << "VERWENDUNG"
        << rang::style::reset << rang::fg::reset << '\n'
        << "  toolbox-cli [--home <pfad>] [--color <modus>] <befehl> [optionen]\n\n"
        << rang::style::bold << rang::fgB::yellow << "BEFEHLE"
        << rang::style::reset << rang::fg::reset << '\n'
        << rang::fgB::green << "  list" << rang::fg::reset
        << "      Alle Werkzeuge als JSON auflisten.\n"
        << rang::fgB::green << "  create" << rang::fg::reset
        << "    Ein neues Werkzeug erstellen.\n"
        << rang::fgB::green << "  run" << rang::fg::reset
        << "       Ein Werkzeug ausfuehren.\n\n"
        << rang::style::bold << rang::fgB::yellow << "OPTIONEN"
        << rang::style::reset << rang::fg::reset << '\n'
        << "  -h, --help             Diese Hilfe anzeigen.\n"
        << "  --home <pfad>           Alternatives Toolbox-Benutzerverzeichnis.\n"
        << "  --color <modus>         auto, always oder never (Standard: auto).\n\n"
        << rang::style::bold << rang::fgB::yellow << "BEISPIELE"
        << rang::style::reset << rang::fg::reset << '\n'
        << rang::fg::cyan << "  toolbox-cli list\n"
        << "  toolbox-cli create --name \"Mein Tool\" --script-file start.lua\n"
        << "  toolbox-cli run \"Mein Tool\"" << rang::fg::reset << "\n\n"
        << rang::fg::gray
        << "  list, create und run liefern weiterhin genau ein JSON-Objekt."
        << rang::fg::reset << '\n';
}

} // namespace

int runCli(std::vector<std::string> args) {
    CLI::App app{"Lokale Lua-Werkzeuge verwalten und ausfuehren.", "toolbox-cli"};
    app.set_help_flag("-h,--help", "Diese Hilfe anzeigen.");
    app.require_subcommand(1);
    app.fallthrough();

    std::string homeValue;
    std::string colorMode = "auto";
    app.add_option("--home", homeValue, "Alternatives Toolbox-Benutzerverzeichnis.");
    app.add_option("--color", colorMode, "Farbmodus: auto, always oder never.")
        ->check(CLI::IsMember({"auto", "always", "never"}));

    auto* listCommand = app.add_subcommand("list", "Alle Werkzeuge als JSON auflisten.");
    auto* helpCommand = app.add_subcommand("help", "Diese Hilfe anzeigen.");

    std::string createName;
    std::string createDescription;
    std::string createScript;
    std::string createScriptFile;
    int createTimeout = 0;
    auto* createCommand = app.add_subcommand("create", "Ein neues Werkzeug erstellen.");
    createCommand->add_option("--name", createName, "Name des Werkzeugs.")->required();
    auto* descriptionOption = createCommand->add_option(
        "--description", createDescription, "Beschreibung des Werkzeugs.");
    auto* scriptOption = createCommand->add_option("--script", createScript, "Lua-Quelltext.");
    auto* scriptFileOption = createCommand->add_option(
        "--script-file", createScriptFile, "Lua-Datei einlesen.");
    auto* timeoutOption = createCommand->add_option(
        "--timeout", createTimeout, "Zeitlimit in Sekunden.");

    std::string runName;
    auto* runCommand = app.add_subcommand("run", "Ein Werkzeug ausfuehren.");
    runCommand->add_option("name", runName, "Name des Werkzeugs.")->required();

    if (args.empty()) {
        configureColor(colorMode);
        printHelp();
        return 0;
    }

    if (const auto requestedColor = optionValue(args, "--color")) {
        configureColor(*requestedColor);
    }
    std::ranges::reverse(args);
    try {
        app.parse(args);
    } catch (const CLI::CallForHelp&) {
        printHelp();
        return 0;
    } catch (const CLI::ParseError& error) {
        return fail(error.what());
    }

    configureColor(colorMode);
    const std::filesystem::path home = homeValue.empty()
        ? defaultHome()
        : std::filesystem::u8path(homeValue);
    if (*helpCommand) {
        printHelp();
        return 0;
    }
    if (*listCommand) {
        return listTools(home);
    }
    if (*createCommand) {
        std::vector<std::string> createArgs{"--name", createName};
        if (descriptionOption->count() > 0) {
            createArgs.insert(createArgs.end(), {"--description", createDescription});
        }
        if (scriptOption->count() > 0) {
            createArgs.insert(createArgs.end(), {"--script", createScript});
        }
        if (scriptFileOption->count() > 0) {
            createArgs.insert(createArgs.end(), {"--script-file", createScriptFile});
        }
        if (timeoutOption->count() > 0) {
            createArgs.insert(createArgs.end(), {"--timeout", std::to_string(createTimeout)});
        }
        return createTool(home, createArgs);
    }
    if (*runCommand) {
        return runTool(home, {runName});
    }
    return fail("No command selected.");
}

// runCli is called from main.cpp when CLI arguments are detected.
// No entry point here.
