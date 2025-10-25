#include <saucer/app.hpp>
#include "toolboxWindow.h"
#include "resource.h"
#include "tray.h"

import toolboxTray;

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

coco::stray start(saucer::application *app){
    // Toolbox-Fenster erstellen und initialisieren
    std::shared_ptr<saucer::application> app_shared(app, [](saucer::application*){});
    auto toolboxWindow = std::make_unique<ToolboxWindow>(app_shared);
    toolboxWindow->initialize();

    g_toolboxWindow = toolboxWindow.get();

    HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));

    // Tray-Menü definieren
    tray_menu tray_menu_items[] = {
        {reinterpret_cast<const char*>(u8"Öffnen"), 0, 0, 0, on_click, nullptr},
        {"-", 0, 0, 0, nullptr, nullptr}, // Separator
        {reinterpret_cast<const char*>(u8"Beenden"), 0, 0, 0, on_quit, nullptr},
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
        co_return; // Fehlerfall: coroutine beenden
    }

    //toolboxWindow->show();

    co_await app->finish();
}

#ifdef _DEBUG
int main(int argc, char** argv) {
    return saucer::application::create({.id = "toolbox"})->run(start);
}
#else
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return saucer::application::create({.id = "toolbox"})->run(start);
}
#endif
