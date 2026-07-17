#include "toolRegistry.h"
#include "toolTemplates.h"

#include <cppcodec/base64_rfc4648.hpp>
#include <nlohmann/json.hpp>

#include <chrono>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <ranges>
#include <sstream>
#include <stdexcept>
#include <string_view>
#include <unordered_set>

#ifdef _WIN32
#include <windows.h>
#endif

namespace {

std::string trim(std::string value) {
    const auto isNotSpace = [](unsigned char character) { return !std::isspace(character); };
    value.erase(value.begin(), std::find_if(value.begin(), value.end(), isNotSpace));
    value.erase(std::find_if(value.rbegin(), value.rend(), isNotSpace).base(), value.end());
    return value;
}

bool isValidToolName(const std::string& name) {
    if (name.empty() || name.size() > 80 || name == "." || name == ".." ||
        name.back() == '.' || name.back() == ' ') {
        return false;
    }

    constexpr std::string_view invalidCharacters = "<>:\"/\\|?*";
    if (std::ranges::any_of(name, [](unsigned char character) {
            return character < 32;
        }) || name.find_first_of(invalidCharacters) != std::string::npos) {
        return false;
    }

    std::string deviceName = name.substr(0, name.find('.'));
    std::ranges::transform(deviceName, deviceName.begin(), [](unsigned char character) {
        return static_cast<char>(std::toupper(character));
    });
    static const std::unordered_set<std::string> reservedNames = {
        "CON", "PRN", "AUX", "NUL",
        "COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9",
        "LPT1", "LPT2", "LPT3", "LPT4", "LPT5", "LPT6", "LPT7", "LPT8", "LPT9",
    };
    return !reservedNames.contains(deviceName);
}

bool isTemplateType(const std::string& type) {
    return type == "lua" || type == "program" || type == "folder" || type == "website";
}

bool writeTextFile(const std::filesystem::path& path, const std::string& content) {
    std::ofstream output(path, std::ios::binary);
    output.write(content.data(), static_cast<std::streamsize>(content.size()));
    return output.good();
}

std::string readTextFile(const std::filesystem::path& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        return {};
    }
    return {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
}

std::string pathUtf8(const std::filesystem::path& path) {
    const auto value = path.u8string();
    return {reinterpret_cast<const char*>(value.data()), value.size()};
}

bool isInternalEntryName(const std::string& name) {
    return name.starts_with(".toolbox-update-") ||
           name.starts_with(".toolbox-backup-") ||
           name.starts_with(".toolbox-transaction-");
}

bool isReparsePoint(const std::filesystem::path& path) {
#ifdef _WIN32
    const DWORD attributes = GetFileAttributesW(path.c_str());
    return attributes != INVALID_FILE_ATTRIBUTES &&
           (attributes & FILE_ATTRIBUTE_REPARSE_POINT) != 0;
#else
    std::error_code error;
    return std::filesystem::is_symlink(std::filesystem::symlink_status(path, error));
#endif
}

bool isDirectToolPath(const std::filesystem::path& userPath,
                      const std::filesystem::path& toolPath) {
    const auto toolboxRoot = userPath / ".Toolbox";
    if (isReparsePoint(toolboxRoot) || isReparsePoint(toolPath)) {
        return false;
    }
    std::error_code error;
    const auto root = std::filesystem::weakly_canonical(toolboxRoot, error);
    if (error) {
        return false;
    }
    const auto parent = std::filesystem::weakly_canonical(toolPath.parent_path(), error);
    if (error || parent != root || isInternalEntryName(pathUtf8(toolPath.filename()))) {
        return false;
    }
    constexpr std::array<std::string_view, 5> managedFiles = {
        "description.txt", "start.lua", "config.ini", "tool.json", "icon.png"
    };
    return std::ranges::none_of(managedFiles, [&toolPath](std::string_view name) {
        return isReparsePoint(toolPath / name);
    });
}

bool isPng(const std::vector<unsigned char>& bytes) {
    constexpr std::array<unsigned char, 8> signature = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};
    return bytes.size() >= signature.size() &&
        std::equal(signature.begin(), signature.end(), bytes.begin());
}

void writeIcon(const std::filesystem::path& path, const std::string& base64) {
    const auto bytes = cppcodec::base64_rfc4648::decode<std::vector<unsigned char>>(base64);
    if (!isPng(bytes)) {
        throw std::runtime_error("Das ausgewaehlte Icon ist keine gueltige PNG-Datei.");
    }
    std::ofstream output(path, std::ios::binary);
    output.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
    if (!output.good()) {
        throw std::runtime_error("Das Icon konnte nicht geschrieben werden.");
    }
}

struct ResolvedScript {
    bool success = false;
    std::string message;
    std::string script;
    std::string type;
    std::string target;
};

ResolvedScript resolveScript(std::string type, const std::string& target,
                             const std::string& luaScript, const std::string& name) {
    type = trim(std::move(type));
    if (type.empty() || type == "lua") {
        return {
            true,
            {},
            luaScript.empty() ? ToolTemplates::defaultLuaScript("Hallo aus " + name) : luaScript,
            "lua",
            {},
        };
    }

    ToolTemplateResult generated;
    if (type == "program") {
        generated = ToolTemplates::programLauncher(std::filesystem::u8path(target));
    } else if (type == "folder") {
        generated = ToolTemplates::folderLauncher(std::filesystem::u8path(target));
    } else if (type == "website") {
        generated = ToolTemplates::websiteLauncher(target);
    } else {
        return {false, "Der Starttyp ist ungueltig."};
    }

    if (!generated.success) {
        return {false, generated.message};
    }
    return {true, {}, generated.draft.luaScript, type, generated.draft.templateTarget};
}

std::string metadataJson(const std::string& type, const std::string& target) {
    return nlohmann::json{{"version", 1}, {"type", type}, {"target", target}}.dump(2) + "\n";
}

int readTimeout(const std::filesystem::path& path) {
    std::istringstream input(readTextFile(path));
    std::string line;
    while (std::getline(input, line)) {
        constexpr std::string_view prefix = "lua_timeout_seconds=";
        if (!line.starts_with(prefix)) {
            continue;
        }
        try {
            return std::clamp(std::stoi(line.substr(prefix.size())), 0, 86400);
        } catch (...) {
            return 30;
        }
    }
    return 30;
}

std::string configWithTimeout(const std::filesystem::path& path, int seconds) {
    std::istringstream input(readTextFile(path));
    std::vector<std::string> lines;
    std::string line;
    bool replaced = false;
    while (std::getline(input, line)) {
        if (line.starts_with("lua_timeout_seconds=")) {
            line = "lua_timeout_seconds=" + std::to_string(std::clamp(seconds, 0, 86400));
            replaced = true;
        }
        lines.push_back(std::move(line));
    }
    if (!replaced) {
        lines.push_back("lua_timeout_seconds=" + std::to_string(std::clamp(seconds, 0, 86400)));
    }
    std::string result;
    for (const auto& configLine : lines) {
        result += configLine + "\n";
    }
    return result;
}

std::string readIconBase64(const std::filesystem::path& path) {
    std::ifstream input(path, std::ios::binary | std::ios::ate);
    if (!input) {
        return {};
    }
    const auto size = input.tellg();
    input.seekg(0, std::ios::beg);
    std::vector<unsigned char> bytes(static_cast<std::size_t>(size));
    if (!input.read(reinterpret_cast<char*>(bytes.data()), size)) {
        return {};
    }
    return cppcodec::base64_rfc4648::encode(bytes);
}

bool recoverTransaction(const std::filesystem::path& root,
                        const std::filesystem::path& journalPath) {
    try {
        const auto journal = nlohmann::json::parse(readTextFile(journalPath));
        const std::string id = journal.at("id").get<std::string>();
        const std::string originalName = journal.at("originalName").get<std::string>();
        const std::string targetName = journal.at("targetName").get<std::string>();
        const std::string expectedJournalName = ".toolbox-transaction-" + id + ".json";
        if (id.empty() ||
            std::ranges::any_of(id, [](unsigned char character) { return !std::isdigit(character); }) ||
            pathUtf8(journalPath.filename()) != expectedJournalName ||
            !isValidToolName(originalName) || !isValidToolName(targetName)) {
            return false;
        }

        const auto stagePath = root / (".toolbox-update-" + id);
        const auto backupPath = root / (".toolbox-backup-" + id);
        const auto originalPath = root / std::filesystem::u8path(originalName);
        const auto targetPath = root / std::filesystem::u8path(targetName);
        std::error_code error;

        if (std::filesystem::exists(backupPath)) {
            if (std::filesystem::exists(targetPath) && !std::filesystem::exists(stagePath)) {
                std::filesystem::remove_all(backupPath, error);
            } else if (!std::filesystem::exists(originalPath)) {
                std::filesystem::rename(backupPath, originalPath, error);
            } else {
                std::filesystem::remove_all(backupPath, error);
            }
            if (error) {
                return false;
            }
        }

        std::filesystem::remove_all(stagePath, error);
        if (error) {
            return false;
        }
        std::filesystem::remove(journalPath, error);
        return !error;
    } catch (...) {
        return false;
    }
}

void recoverTransactions(const std::filesystem::path& root) {
    std::vector<std::filesystem::path> journals;
    for (const auto& entry : std::filesystem::directory_iterator(root)) {
        const std::string name = pathUtf8(entry.path().filename());
        if (entry.is_regular_file() && name.starts_with(".toolbox-transaction-") &&
            entry.path().extension() == ".json") {
            journals.push_back(entry.path());
        }
    }
    for (const auto& journal : journals) {
        recoverTransaction(root, journal);
    }
    for (const auto& entry : std::filesystem::directory_iterator(root)) {
        const std::string name = pathUtf8(entry.path().filename());
        if (entry.is_directory() && name.starts_with(".toolbox-update-")) {
            std::error_code ignored;
            std::filesystem::remove_all(entry.path(), ignored);
        }
    }
}

} // namespace

std::filesystem::path ToolRegistry::toolboxDirectory(const std::filesystem::path& userPath) {
    return userPath / ".Toolbox";
}

bool ToolRegistry::ensureToolboxDirectory(const std::filesystem::path& userPath) {
    const std::filesystem::path toolboxPath = toolboxDirectory(userPath);
    if (std::filesystem::exists(toolboxPath)) {
        return std::filesystem::is_directory(toolboxPath) && !isReparsePoint(toolboxPath);
    }

    try {
        if (std::filesystem::create_directory(toolboxPath)) {
            return true;
        }

        std::cerr << "Fehler beim Erstellen des .Toolbox Verzeichnisses." << std::endl;
        return false;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem-Fehler: " << e.what() << std::endl;
        return false;
    }
}

std::vector<ToolboxItem> ToolRegistry::loadTools(const std::filesystem::path& userPath) {
    std::vector<ToolboxItem> items;
    const std::filesystem::path toolboxDir = toolboxDirectory(userPath);

    if (!std::filesystem::exists(toolboxDir) || !std::filesystem::is_directory(toolboxDir) ||
        isReparsePoint(toolboxDir)) {
        std::cerr << "Fehler: Das Verzeichnis .Toolbox existiert nicht." << std::endl;
        return items;
    }

    recoverTransactions(toolboxDir);

    int id = 0;
    for (const auto& entry : std::filesystem::directory_iterator(toolboxDir)) {
        if (!entry.is_directory()) {
            continue;
        }
        const std::string entryName = pathUtf8(entry.path().filename());
        if (isInternalEntryName(entryName)) {
            continue;
        }
        if (!isDirectToolPath(userPath, entry.path())) {
            continue;
        }

        ToolboxItem item;
        item.id = std::to_string(id++);
        item.name = entryName;
        item.path = pathUtf8(entry.path());

        encodeIcon(entry.path() / "icon.png", item);

        const std::filesystem::path descriptionFile = entry.path() / "description.txt";
        if (std::filesystem::exists(descriptionFile)) {
            std::ifstream descFile(descriptionFile);
            item.description.assign(std::istreambuf_iterator<char>(descFile), std::istreambuf_iterator<char>());
        }

        const std::filesystem::path luaScript = entry.path() / "start.lua";
        if (std::filesystem::exists(luaScript)) {
            item.lua_script_path_string = pathUtf8(luaScript);
        }

        items.push_back(std::move(item));
    }

    return items;
}

ToolCreationResult ToolRegistry::createTool(const std::filesystem::path& userPath, const ToolDraft& draft) {
    const std::string name = trim(draft.name);
    if (!isValidToolName(name)) {
        return {false, "Der Tool-Name ist leer oder enthaelt ungueltige Zeichen."};
    }
    if (draft.description.size() > 8 * 1024 || draft.luaScript.size() > 1024 * 1024 ||
        draft.iconBase64.size() > 3 * 1024 * 1024) {
        return {false, "Mindestens eine Eingabe ist zu gross."};
    }
    if (!ensureToolboxDirectory(userPath)) {
        return {false, "Das .Toolbox-Verzeichnis konnte nicht erstellt werden."};
    }

    const std::filesystem::path toolPath = toolboxDirectory(userPath) / std::filesystem::u8path(name);
    const auto resolved = resolveScript(draft.templateType, draft.templateTarget, draft.luaScript, name);
    if (!resolved.success) {
        return {false, resolved.message};
    }

    try {
        if (!std::filesystem::create_directory(toolPath)) {
            return {false, "Ein Tool mit diesem Namen existiert bereits."};
        }
        if (!writeTextFile(toolPath / "description.txt", draft.description) ||
            !writeTextFile(toolPath / "start.lua", resolved.script) ||
            !writeTextFile(toolPath / "config.ini",
                           "lua_timeout_seconds=" + std::to_string(std::clamp(draft.timeoutSeconds, 0, 86400)) + "\n") ||
            !writeTextFile(toolPath / "tool.json", metadataJson(resolved.type, resolved.target))) {
            throw std::runtime_error("Tool-Dateien konnten nicht geschrieben werden.");
        }

        if (!draft.iconBase64.empty()) {
            writeIcon(toolPath / "icon.png", draft.iconBase64);
        }
    } catch (const std::exception& error) {
        std::error_code cleanupError;
        std::filesystem::remove_all(toolPath, cleanupError);
        return {false, error.what()};
    }

    return {true, "Tool wurde erstellt."};
}

ToolDetailsResult ToolRegistry::getToolDetails(const std::filesystem::path& userPath,
                                               const std::filesystem::path& toolPath) {
    if (!isDirectToolPath(userPath, toolPath) || !std::filesystem::is_directory(toolPath)) {
        return {false, "Das Tool-Verzeichnis wurde nicht gefunden."};
    }

    ToolDetails details{
        .path = toolPath,
        .name = pathUtf8(toolPath.filename()),
        .description = readTextFile(toolPath / "description.txt"),
        .luaScript = readTextFile(toolPath / "start.lua"),
        .iconBase64 = readIconBase64(toolPath / "icon.png"),
        .timeoutSeconds = readTimeout(toolPath / "config.ini"),
    };

    const auto metadataPath = toolPath / "tool.json";
    if (std::filesystem::exists(metadataPath)) {
        try {
            const auto metadata = nlohmann::json::parse(readTextFile(metadataPath));
            details.templateType = metadata.value("type", "lua");
            details.templateTarget = metadata.value("target", "");
            if (!isTemplateType(details.templateType)) {
                details.templateType = "lua";
                details.templateTarget.clear();
            }
        } catch (...) {
            details.templateType = "lua";
            details.templateTarget.clear();
        }
    }

    return {true, {}, std::move(details)};
}

ToolUpdateResult ToolRegistry::updateTool(const std::filesystem::path& userPath,
                                          const std::filesystem::path& toolPath,
                                          const ToolUpdateDraft& draft) {
    const std::string name = trim(draft.name);
    if (!isDirectToolPath(userPath, toolPath) || !std::filesystem::is_directory(toolPath)) {
        return {false, "Das Tool-Verzeichnis wurde nicht gefunden."};
    }
    if (!isValidToolName(name)) {
        return {false, "Der Tool-Name ist leer oder enthaelt ungueltige Zeichen."};
    }
    if (draft.description.size() > 8 * 1024 || draft.luaScript.size() > 1024 * 1024 ||
        (draft.iconBase64 && draft.iconBase64->size() > 3 * 1024 * 1024)) {
        return {false, "Mindestens eine Eingabe ist zu gross."};
    }

    const auto resolved = resolveScript(draft.templateType, draft.templateTarget,
                                        draft.luaScript, name);
    if (!resolved.success) {
        return {false, resolved.message};
    }

    const auto parent = toolPath.parent_path();
    const auto targetPath = parent / std::filesystem::u8path(name);
    if (targetPath != toolPath && std::filesystem::exists(targetPath)) {
        return {false, "Ein Tool mit diesem Namen existiert bereits."};
    }

    const auto suffix = std::to_string(static_cast<std::uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count()));
    const auto stagePath = parent / (".toolbox-update-" + suffix);
    const auto backupPath = parent / (".toolbox-backup-" + suffix);
    const auto journalPath = parent / (".toolbox-transaction-" + suffix + ".json");

    try {
        std::filesystem::copy(toolPath, stagePath, std::filesystem::copy_options::recursive);
        if (!writeTextFile(stagePath / "description.txt", draft.description) ||
            !writeTextFile(stagePath / "start.lua", resolved.script) ||
            !writeTextFile(stagePath / "config.ini",
                           configWithTimeout(stagePath / "config.ini", draft.timeoutSeconds)) ||
            !writeTextFile(stagePath / "tool.json", metadataJson(resolved.type, resolved.target))) {
            throw std::runtime_error("Tool-Dateien konnten nicht geschrieben werden.");
        }

        if (draft.iconBase64) {
            if (draft.iconBase64->empty()) {
                std::filesystem::remove(stagePath / "icon.png");
            } else {
                writeIcon(stagePath / "icon.png", *draft.iconBase64);
            }
        }

        const std::string journal = nlohmann::json{
            {"version", 1},
            {"id", suffix},
            {"originalName", pathUtf8(toolPath.filename())},
            {"targetName", name},
        }.dump(2) + "\n";
        if (!writeTextFile(journalPath, journal)) {
            throw std::runtime_error("Das Update-Journal konnte nicht geschrieben werden.");
        }

        std::filesystem::rename(toolPath, backupPath);
        std::filesystem::rename(stagePath, targetPath);
        std::error_code cleanupError;
        std::filesystem::remove_all(backupPath, cleanupError);
        if (!cleanupError) {
            std::filesystem::remove(journalPath, cleanupError);
        }
    } catch (const std::exception& error) {
        if (!recoverTransaction(parent, journalPath)) {
            std::error_code ignored;
            std::filesystem::remove_all(stagePath, ignored);
            if (std::filesystem::exists(backupPath) && !std::filesystem::exists(toolPath)) {
                std::filesystem::rename(backupPath, toolPath, ignored);
            }
        }
        return {false, error.what()};
    }

    return {true, "Tool wurde gespeichert.", targetPath};
}

ToolDeletionResult ToolRegistry::deleteTool(const std::filesystem::path& userPath,
                                             const std::filesystem::path& toolPath) {
    if (!isDirectToolPath(userPath, toolPath) || !std::filesystem::is_directory(toolPath)) {
        return {false, "Das Tool-Verzeichnis wurde nicht gefunden."};
    }
    std::error_code error;
    std::filesystem::remove_all(toolPath, error);
    if (error) {
        return {false, "Das Tool konnte nicht geloescht werden."};
    }
    return {true, "Tool wurde geloescht."};
}

void ToolRegistry::encodeIcon(const std::filesystem::path& imagePath, ToolboxItem& item) {
    if (!std::filesystem::exists(imagePath)) {
        return;
    }

    std::ifstream file(imagePath, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Fehler beim Oeffnen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    const std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> fileData(fileSize);
    if (!file.read(reinterpret_cast<char*>(fileData.data()), fileSize)) {
        std::cerr << "Fehler beim Lesen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    item.icon = "data:image/png;base64," + cppcodec::base64_rfc4648::encode(fileData);
}
