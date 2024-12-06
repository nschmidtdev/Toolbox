#include "toolboxWindow.h"
#include <saucer/app.hpp>

int main(int argc, char** argv) {
    // Initialisiere die Saucer-Anwendung
    auto app = saucer::application::acquire({
            .id = "toolbox",
    });

    // Erstelle und initialisiere das Toolbox-Fenster
    ToolboxWindow toolboxWindow(app);
    toolboxWindow.initialize();

    // Zeige das Fenster an
    toolboxWindow.show();

    // Starte die Saucer-Anwendung
    app->run();

    return 0;
}