#pragma once

#include <filesystem>
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

class ToolRegistry {
public:
    static std::filesystem::path toolboxDirectory(const std::filesystem::path& userPath);
    static bool ensureToolboxDirectory(const std::filesystem::path& userPath);
    static std::vector<ToolboxItem> loadTools(const std::filesystem::path& userPath);

private:
    static void encodeIcon(const std::filesystem::path& imagePath, ToolboxItem& item);
};
