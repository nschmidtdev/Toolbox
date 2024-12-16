#include <saucer/app.hpp>
#include "toolboxWindow.h"
#include "toolboxTray.h"
#include "resource.h"

ToolboxWindow*          g_toolboxWindow = nullptr;

void on_quit(struct tray_menu *item) {
    tray_exit();
}

void on_click(struct tray_menu *item = nullptr) {
    if (g_toolboxWindow) {
        if (g_toolboxWindow->m_bShow)
            g_toolboxWindow->hide();
        else
            g_toolboxWindow->show();
    }
}

int start(){

    // Neue Anwendung erstellen
    auto app = saucer::application::acquire({
                                                    .id = "toolbox",
                                            });

    // Toolbox-Fenster erstellen und initialisieren
    ToolboxWindow toolboxWindow(app);
    toolboxWindow.initialize();

    g_toolboxWindow = &toolboxWindow;
    //toolboxWindow.show();

    HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));

// Tray-Menü definieren
    tray_menu tray_menu_items[] = {
            {"Öffnen", 0, 0, 0, on_click, nullptr},
            {"-", 0, 0, 0, nullptr, nullptr}, // Separator
            {"Beenden", 0, 0, 0, on_quit, nullptr},
            {nullptr, 0, 0, 0, nullptr, nullptr} // Ende des Menüs
    };

    // ToolboxTray erstellen
    toolboxTray tray("toolbox.ico", "Toolbox Application Tray");

    // Linksklick-Aktion registrieren
    tray.setLeftClickAction([&]() {
        on_click(nullptr); // Ruft die Funktion ohne Menüeintrag auf
    });

    // Tray-Menü registrieren
    tray.setTrayMenu(tray_menu_items);

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

#ifdef _DEBUG
int main(int argc, char** argv) {
    return start(); // Konsole bleibt aktiv im Debug-Modus
}
#else
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return start(); // Keine Konsole im Release-Modus
}
#endif
