#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

struct ToolboxItem {
    std::string id;
    std::string name;
    std::string path;
    std::string icon;
    std::string lua_script_path_string;
    std::string description;
    std::string category;
    std::string version;
    std::string author;
    std::string url;
    std::string license;
};

struct ToolDraft {
    std::string name;
    std::string description;
    std::string luaScript;
    std::string iconBase64;
    int timeoutSeconds = 30;
    std::string templateType = "lua";
    std::string templateTarget;
};

struct ToolDetails {
    std::filesystem::path path;
    std::string name;
    std::string description;
    std::string luaScript;
    std::string iconBase64;
    int timeoutSeconds = 30;
    std::string templateType = "lua";
    std::string templateTarget;
};

struct ToolDetailsResult {
    bool success = false;
    std::string message;
    ToolDetails details;
};

struct ToolUpdateDraft {
    std::string name;
    std::string description;
    std::string luaScript;
    std::optional<std::string> iconBase64;
    int timeoutSeconds = 30;
    std::string templateType = "lua";
    std::string templateTarget;
};

struct ToolUpdateResult {
    bool success = false;
    std::string message;
    std::filesystem::path toolPath;
};

struct ToolCreationResult {
    bool success = false;
    std::string message;
};

struct ToolDeletionResult {
    bool success = false;
    std::string message;
};

class ToolRegistry {
public:
    static std::filesystem::path toolboxDirectory(const std::filesystem::path& userPath);
    static bool ensureToolboxDirectory(const std::filesystem::path& userPath);
    static std::vector<ToolboxItem> loadTools(const std::filesystem::path& userPath);
    static ToolCreationResult createTool(const std::filesystem::path& userPath,
                                         const ToolDraft& draft);
    static ToolDetailsResult getToolDetails(const std::filesystem::path& userPath,
                                            const std::filesystem::path& toolPath);
    static ToolUpdateResult updateTool(const std::filesystem::path& userPath,
                                       const std::filesystem::path& toolPath,
                                       const ToolUpdateDraft& draft);
    static ToolDeletionResult deleteTool(const std::filesystem::path& userPath,
                                         const std::filesystem::path& toolPath);

private:
    static void encodeIcon(const std::filesystem::path& imagePath, ToolboxItem& item);
};
