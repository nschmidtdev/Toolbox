#include "platform/fileDialog.h"

#include <portable-file-dialogs.h>

namespace {

std::vector<std::string> portableFilters(const FileDialogRequest& request) {
    std::vector<std::string> filters;
    filters.reserve(request.filters.size() * 2);
    for (const auto& filter : request.filters) {
        filters.push_back(filter.label);
        filters.push_back(filter.patterns);
    }
    return filters;
}

} // namespace

FileDialogRequest FileDialog::programSelectionRequest() {
    return {
        .title = "Programm für das Toolbox-Tool auswählen",
        .selectFolder = false,
        .filters = {
            {"Windows-Programme", "*.exe"},
            {"Alle Dateien", "*"},
        },
    };
}

FileDialogRequest FileDialog::folderSelectionRequest() {
    return {
        .title = "Ordner für das Toolbox-Tool auswählen",
        .selectFolder = true,
    };
}

FileDialogSelection FileDialog::select(const FileDialogRequest& request) {
    if (request.selectFolder) {
        const std::string selection = pfd::select_folder(request.title).result();
        if (selection.empty()) {
            return {{}, true, {}};
        }
        return {std::filesystem::path(selection), false, {}};
    }

    const std::vector<std::string> selections =
        pfd::open_file(request.title, {}, portableFilters(request)).result();
    if (selections.empty()) {
        return {{}, true, {}};
    }
    return {std::filesystem::path(selections.front()), false, {}};
}
