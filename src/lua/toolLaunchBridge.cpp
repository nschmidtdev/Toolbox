#include "lua/toolLaunchBridge.h"

#include <sol/sol.hpp>

#include <cstdint>
#include <string>
#include <tuple>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#endif

namespace {

#ifdef _WIN32
std::wstring utf8ToWide(const std::string& value) {
    if (value.empty()) {
        return {};
    }
    const int length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(),
                                           static_cast<int>(value.size()), nullptr, 0);
    if (length <= 0) {
        return {};
    }
    std::wstring result(static_cast<std::size_t>(length), L'\0');
    if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, value.data(),
                            static_cast<int>(value.size()), result.data(), length) <= 0) {
        return {};
    }
    return result;
}

std::tuple<bool, std::string> openNativeTarget(const std::string& target) {
    const std::wstring wideTarget = utf8ToWide(target);
    if (wideTarget.empty()) {
        return {false, "Das Ziel ist leer oder nicht gueltiges UTF-8."};
    }
    const auto result = reinterpret_cast<std::intptr_t>(
        ShellExecuteW(nullptr, L"open", wideTarget.c_str(), nullptr, nullptr, SW_SHOWNORMAL));
    if (result <= 32) {
        return {false, "Windows konnte das Ziel nicht oeffnen (Fehler " +
                       std::to_string(static_cast<long long>(result)) + ")."};
    }
    return {true, {}};
}
#else
std::tuple<bool, std::string> openNativeTarget(const std::string&) {
    return {false, "Native Vorlagenstarts werden auf diesem System nicht unterstuetzt."};
}
#endif

} // namespace

void ToolLaunchBridge::registerFunctions(sol::state& lua) {
    auto toolbox = lua.create_named_table("toolbox");
    toolbox.set_function("open_program", &openNativeTarget);
    toolbox.set_function("open_folder", &openNativeTarget);
    toolbox.set_function("open_url", &openNativeTarget);
}
