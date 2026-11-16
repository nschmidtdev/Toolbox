#pragma once

#include <filesystem>
#include <string>
#include <vector>

struct FileDialogFilter {
    std::string label;
    std::string patterns;
};

struct FileDialogRequest {
    std::string title;
    bool selectFolder = false;
    std::vector<FileDialogFilter> filters;
};

struct FileDialogSelection {
    std::filesystem::path path;
    bool cancelled = false;
    std::string error;
};

class FileDialog {
public:
    [[nodiscard]] static FileDialogRequest programSelectionRequest();
    [[nodiscard]] static FileDialogRequest folderSelectionRequest();
    [[nodiscard]] static FileDialogSelection select(const FileDialogRequest& request);
};
