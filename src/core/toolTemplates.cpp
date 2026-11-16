#include "core/toolTemplates.h"

#include <algorithm>
#include <cctype>
#include <string_view>

namespace {

std::string luaStringLiteral(std::string_view value) {
    std::string result;
    result.reserve(value.size() + 2);
    result.push_back('"');
    for (const char character : value) {
        switch (character) {
            case '\\': result += "\\\\"; break;
            case '"': result += "\\\""; break;
            case '\n': result += "\\n"; break;
            case '\r': result += "\\r"; break;
            case '\t': result += "\\t"; break;
            default: result.push_back(character); break;
        }
    }
    result.push_back('"');
    return result;
}

bool validName(const std::string& name) {
    return !name.empty() && name.size() <= 80;
}

std::string pathUtf8(const std::filesystem::path& path) {
    const auto encoded = path.u8string();
    return {reinterpret_cast<const char*>(encoded.data()), encoded.size()};
}

std::string launcherScript(std::string_view operation,
                           std::string_view functionName,
                           const std::string& value) {
    return "local target = " + luaStringLiteral(value) + "\n"
           "local ok, message = toolbox." + std::string(functionName) + "(target)\n"
           "if not ok then\n"
           "    error('" + std::string(operation) + " fehlgeschlagen: ' .. tostring(message))\n"
           "end\n";
}

std::string lower(std::string value) {
    std::ranges::transform(value, value.begin(), [](unsigned char character) {
        return static_cast<char>(std::tolower(character));
    });
    return value;
}

} // namespace

std::string ToolTemplates::defaultLuaScript(std::string_view toolName) {
    return "print(" + luaStringLiteral(toolName) + ")\n";
}

ToolTemplateResult ToolTemplates::programLauncher(const std::filesystem::path& executable) {
    const std::string name = pathUtf8(executable.stem());
    if (!validName(name) || lower(pathUtf8(executable.extension())) != ".exe") {
        return {false, "Bitte eine gültige Windows-Programmdatei (.exe) auswählen.", {}};
    }

    return {
        true,
        {},
        {
            name,
            "Startet " + name + ".",
            launcherScript("Programmstart", "open_program", pathUtf8(executable)),
            "program",
            pathUtf8(executable),
        }
    };
}

ToolTemplateResult ToolTemplates::folderLauncher(const std::filesystem::path& folder) {
    const std::string name = pathUtf8(folder.filename());
    if (!validName(name)) {
        return {false, "Bitte einen gültigen Ordner auswählen.", {}};
    }

    return {
        true,
        {},
        {
            name + " öffnen",
            "Öffnet den Ordner " + name + ".",
            launcherScript("Öffnen des Ordners", "open_folder", pathUtf8(folder)),
            "folder",
            pathUtf8(folder),
        }
    };
}

ToolTemplateResult ToolTemplates::websiteLauncher(const std::string& url) {
    const std::size_t schemeLength = url.starts_with("https://") ? 8
        : url.starts_with("http://") ? 7 : 0;
    if (schemeLength == 0 || url.size() > 2048 ||
        std::ranges::any_of(url, [](unsigned char character) {
            return character <= 32 || character == '\\' || character == '"';
        })) {
        return {false, "Bitte eine gültige HTTP- oder HTTPS-URL eingeben.", {}};
    }

    const std::size_t hostEnd = url.find_first_of("/?#", schemeLength);
    std::string host = url.substr(schemeLength, hostEnd - schemeLength);
    if (host.find('@') != std::string::npos) {
        return {false, "URLs mit eingebetteten Anmeldedaten werden nicht unterstützt.", {}};
    }
    if (host.starts_with("www.")) {
        host.erase(0, 4);
    }
    if (!validName(host)) {
        return {false, "Die URL enthält keinen gültigen Hostnamen.", {}};
    }

    return {
        true,
        {},
        {
            host + " öffnen",
            "Öffnet " + url + ".",
            launcherScript("Öffnen der Website", "open_url", url),
            "website",
            url,
        }
    };
}
