#include "platform/fileDialog.h"

#include <cassert>

int main() {
    const auto program = FileDialog::programSelectionRequest();
    assert(program.title == "Programm für das Toolbox-Tool auswählen");
    assert(!program.selectFolder);
    assert(program.filters.size() == 2);
    assert(program.filters[0].label == "Windows-Programme");
    assert(program.filters[0].patterns == "*.exe");
    assert(program.filters[1].label == "Alle Dateien");
    assert(program.filters[1].patterns == "*");

    const auto folder = FileDialog::folderSelectionRequest();
    assert(folder.title == "Ordner für das Toolbox-Tool auswählen");
    assert(folder.selectFolder);
    assert(folder.filters.empty());

    return 0;
}
