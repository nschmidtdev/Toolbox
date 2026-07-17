#pragma once

#include <filesystem>
#include <string>
#include <string_view>

struct ToolTemplateDraft {
    std::string name;
    std::string description;
    std::string luaScript;
    std::string templateType;
    std::string templateTarget;
};

struct ToolTemplateResult {
    bool success = false;
    std::string message;
    ToolTemplateDraft draft;
};

class ToolTemplates {
public:
    static std::string defaultLuaScript(std::string_view toolName);
    static ToolTemplateResult programLauncher(const std::filesystem::path& executable);
    static ToolTemplateResult folderLauncher(const std::filesystem::path& folder);
    static ToolTemplateResult websiteLauncher(const std::string& url);
};
