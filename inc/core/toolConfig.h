#pragma once

#include <filesystem>
#include <string>

class ToolConfigStore {
public:
    bool ensureExists(const std::filesystem::path &path) const;
    int getInt(const std::filesystem::path &path, const std::string &key, int fallback) const;
    void setInt(const std::filesystem::path &path, const std::string &key, int value) const;
    std::string readAll(const std::filesystem::path &path) const;
    void writeAll(const std::filesystem::path &path, const std::string &content) const;
};
