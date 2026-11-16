#include "core/toolConfig.h"

#include <fstream>
#include <sstream>
#include <vector>

bool ToolConfigStore::ensureExists(const std::filesystem::path &path) const {
    if (path.empty()) {
        return false;
    }
    if (std::filesystem::exists(path)) {
        return true;
    }
    std::ofstream out(path);
    if (!out) {
        return false;
    }
    out << "lua_timeout_seconds=30\n";
    return true;
}

static bool parse_key_value(const std::string &line, std::string &key, std::string &value) {
    const auto pos = line.find('=');
    if (pos == std::string::npos) {
        return false;
    }
    key = line.substr(0, pos);
    value = line.substr(pos + 1);
    return true;
}

int ToolConfigStore::getInt(const std::filesystem::path &path, const std::string &key, int fallback) const {
    if (!std::filesystem::exists(path)) {
        return fallback;
    }
    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        std::string k, v;
        if (!parse_key_value(line, k, v)) {
            continue;
        }
        if (k == key) {
            try {
                return std::max(0, std::stoi(v));
            } catch (...) {
                return fallback;
            }
        }
    }
    return fallback;
}

void ToolConfigStore::setInt(const std::filesystem::path &path, const std::string &key, int value) const {
    std::vector<std::string> lines;
    if (std::filesystem::exists(path)) {
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            lines.push_back(line);
        }
    }

    bool updated = false;
    for (auto &line : lines) {
        std::string k, v;
        if (parse_key_value(line, k, v) && k == key) {
            line = k + "=" + std::to_string(std::max(0, value));
            updated = true;
            break;
        }
    }

    if (!updated) {
        lines.push_back(key + "=" + std::to_string(std::max(0, value)));
    }

    std::ofstream out(path);
    for (const auto &line : lines) {
        out << line << "\n";
    }
}

std::string ToolConfigStore::readAll(const std::filesystem::path &path) const {
    if (path.empty() || !std::filesystem::exists(path)) {
        return {};
    }
    std::ifstream in(path);
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

void ToolConfigStore::writeAll(const std::filesystem::path &path, const std::string &content) const {
    if (path.empty()) {
        return;
    }
    std::ofstream out(path);
    out << content;
}
