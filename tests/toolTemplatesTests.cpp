#include "toolTemplates.h"

#include <sol/sol.hpp>

#include <cassert>
#include <filesystem>
#include <string>
#include <tuple>

namespace {

std::tuple<std::string, std::string> capturedLaunch(const std::string& script) {
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::string);
    std::string operation;
    std::string target;
    auto toolbox = lua.create_named_table("toolbox");
    for (const std::string name : {"open_program", "open_folder", "open_url"}) {
        toolbox.set_function(name, [&, name](const std::string& value) {
            operation = name;
            target = value;
            return std::tuple{true, std::string{}};
        });
    }
    const sol::protected_function_result result = lua.safe_script(script, sol::script_pass_on_error);
    assert(result.valid());
    return {operation, target};
}

std::string capturedPrint(const std::string& script) {
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::string);
    std::string output;
    lua.set_function("print", [&output](const std::string& value) { output = value; });
    const sol::protected_function_result result = lua.safe_script(script, sol::script_pass_on_error);
    assert(result.valid());
    return output;
}

} // namespace

int main() {
    const std::string syntaxSensitiveName = "x'); error('injected\n\t\\\"";
    assert(capturedPrint(ToolTemplates::defaultLuaScript(syntaxSensitiveName)) == syntaxSensitiveName);

    const std::filesystem::path programPath(R"(C:\Program Files\Acme\Acme.exe)");
    const auto program = ToolTemplates::programLauncher(programPath);
    assert(program.success);
    assert(program.draft.name == "Acme");
    assert(program.draft.description == "Startet Acme.");
    assert(program.draft.luaScript.find(R"(C:\\Program Files\\Acme\\Acme.exe)") != std::string::npos);
    assert(program.draft.luaScript.find("os.execute") == std::string::npos);
    assert((capturedLaunch(program.draft.luaScript) ==
            std::tuple{std::string("open_program"), program.draft.templateTarget}));

    const std::filesystem::path folderPath(R"(C:\Users\User\Projects)");
    const auto folder = ToolTemplates::folderLauncher(folderPath);
    assert(folder.success);
    assert(folder.draft.name == "Projects öffnen");
    assert(folder.draft.description == "Öffnet den Ordner Projects.");
    assert(folder.draft.luaScript.find(R"(C:\\Users\\User\\Projects)") != std::string::npos);
    assert(folder.draft.luaScript.find("os.execute") == std::string::npos);
    assert((capturedLaunch(folder.draft.luaScript) ==
            std::tuple{std::string("open_folder"), folder.draft.templateTarget}));

    const auto website = ToolTemplates::websiteLauncher("https://www.example.com/docs");
    assert(website.success);
    assert(website.draft.name == "example.com öffnen");
    assert(website.draft.description == "Öffnet https://www.example.com/docs.");
    assert(website.draft.luaScript.find("https://www.example.com/docs") != std::string::npos);
    assert(website.draft.luaScript.find("os.execute") == std::string::npos);
    assert((capturedLaunch(website.draft.luaScript) ==
            std::tuple{std::string("open_url"), std::string("https://www.example.com/docs")}));

    const std::string shellSensitiveUrl = "https://example.com/%TEMP%?a=1&b=(two)";
    const auto shellSensitiveWebsite = ToolTemplates::websiteLauncher(shellSensitiveUrl);
    assert(shellSensitiveWebsite.success);
    assert((capturedLaunch(shellSensitiveWebsite.draft.luaScript) ==
            std::tuple{std::string("open_url"), shellSensitiveUrl}));

    const auto invalidWebsite = ToolTemplates::websiteLauncher("javascript:alert(1)");
    assert(!invalidWebsite.success);

    const auto invalidProgram = ToolTemplates::programLauncher(
        std::filesystem::path(R"(C:\Temp\notes.txt)"));
    assert(!invalidProgram.success);

    const auto unicodeProgram = ToolTemplates::programLauncher(
        std::filesystem::path(LR"(C:\Programme\工具.exe)"));
    assert(unicodeProgram.success);
    assert(unicodeProgram.draft.name == "工具");
    assert(unicodeProgram.draft.luaScript.find("工具.exe") != std::string::npos);

    return 0;
}
