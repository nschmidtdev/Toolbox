#include <saucer/app.hpp>
#include "toolboxWindow.h"
#include "tray.h"
#include "resource.h"

ToolboxWindow*          g_toolboxWindow = nullptr;

void on_toggle(struct tray_menu *item) {
    item->checked = !item->checked;
}

void on_quit(struct tray_menu *item) {
    tray_exit();
}

void on_click(struct tray_menu *item) {
    if (g_toolboxWindow->m_bShow)
        g_toolboxWindow->hide();
    else
        g_toolboxWindow->show();
}


int main(int argc, char** argv) {

    // Neue Anwendung erstellen
    auto app = saucer::application::acquire({
                                                    .id = "toolbox",
                                            });

    // Toolbox-Fenster erstellen und initialisieren
    ToolboxWindow toolboxWindow(app);
    toolboxWindow.initialize();

    g_toolboxWindow = &toolboxWindow;
    toolboxWindow.show();

    HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));

    struct tray_menu tray_menu_items[] = {
            {"Öffnen", 0, 0, NULL, on_click, 0},
            {"Option umschalten", 0, 0, NULL, on_toggle, 0},
            {"-", 0, 0, NULL, nullptr, 0},
            {"Beenden", 0, 0, NULL, on_quit, 0},
            {nullptr, 0, 0, NULL, nullptr, 0}
    };

    struct tray tray = {
            .icon = (char*)"toolbox.ico",
            .menu = tray_menu_items
    };

    if (tray_init(&tray) != 0) {
        fprintf(stderr, "Fehler beim Initialisieren des Tray-Icons\n");
        return 1;
    }

    //toolboxWindow.show();

/*    while (tray_loop(1) == 0) {
    }*/

    // Anwendung ausführen
    app->run();

    return 0;
}
