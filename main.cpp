#include <saucer/app.hpp>
#include <Windows.h>
#include "toolboxWindow.h"
#include "resource.h"
#include "tray.h"

import toolboxTray;

ToolboxWindow* g_toolboxWindow = nullptr;

void on_quit(struct tray_menu *item) {
    tray_exit();
}

void on_open(struct tray_menu *item = nullptr) {
    if (g_toolboxWindow) {
        if (g_toolboxWindow->m_bShow) {
            g_toolboxWindow->hide();
        } else {
            g_toolboxWindow->show();
        }
    }
}

coco::stray start(saucer::application *app){
    // Toolbox-Fenster erstellen und initialisieren
    std::shared_ptr<saucer::application> app_shared(app, [](saucer::application*){});
    auto toolboxWindow = std::make_unique<ToolboxWindow>(app_shared);
    toolboxWindow->initialize();

    g_toolboxWindow = toolboxWindow.get();

    HICON hIcon = static_cast<HICON>(LoadImage(
        GetModuleHandle(NULL),
        MAKEINTRESOURCE(IDI_ICON1),
        IMAGE_ICON,
        GetSystemMetrics(SM_CXSMICON),
        GetSystemMetrics(SM_CYSMICON),
        LR_SHARED
    ));

    // Tray-Menue definieren
    tray_menu tray_menu_items[] = {
        {"Oeffnen", 0, 0, 0, on_open, nullptr},
        {"-", 0, 0, 0, nullptr, nullptr}, // Separator
        {"Beenden", 0, 0, 0, on_quit, nullptr},
        {nullptr, 0, 0, 0, nullptr, nullptr} // Ende des Menues
    };

    // ToolboxTray erstellen
    toolboxTray tray("toolbox.ico", "Toolbox");
    tray.icon_handle = hIcon;
    tray.icon_is_shared = (hIcon != nullptr) ? 1 : 0;

    // Linksklick-Aktion registrieren
    tray.setLeftClickAction([&]() {
        on_open(nullptr); // Ruft die Funktion ohne Menueeintrag auf
    });

    // Tray-Menue registrieren
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
