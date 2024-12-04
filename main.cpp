#include <iostream>
#include <saucer/smartview.hpp>
#include <saucer/webview.hpp>
#include <windows.h>
#include "modules/hwnd_module.h"
#include "all.hpp"
#include <sol/sol.hpp>

int main(int argc, char** argv)
{
    // Initialisiere die Saucer-Anwendung
    auto app = saucer::application::acquire({
    .id = "example",
});

    // Lade alle eingebetteten Dateien
    auto resources = saucer::embedded::all();

    // Überprüfen, ob die "index.html"-Ressource verfügbar ist
    auto it = resources.find("index.html");
    if (it == resources.end())
    {
        std::cerr << "Fehler: 'index.html' wurde nicht gefunden!" << std::endl;
        return 1;
    }

    saucer::smartview<saucer::default_serializer, hwnd_module> webview({
        .application = app,
    });

    webview.set_size(400, 600);
    webview.set_force_dark_mode(true);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int xPos = screenWidth - 400; // 400 ist die Fensterbreite
    int yPos = screenHeight - 42 - 600; // 600 ist die Fensterhöhe

    // Zugriff auf das native Fenster-Handle
    HWND hwnd = webview.module<hwnd_module>().get_hwnd();
    if (hwnd) {
        // Setze die Fensterposition auf (x: 100, y: 100)
        SetWindowPos(hwnd, nullptr, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }


    // Erstelle ein WebView-Fenster
    webview.expose(
        "add_random",
        [&](float number)
        {
            auto random = webview.evaluate<float>("Math.random()").get();
            return number + random;
        },
        saucer::launch::async);

    // Lade die eingebettete "index.html" aus den Ressourcen
    webview.embed(saucer::embedded::all());
    webview.serve("index.html");

    // Zeige das Fenster an
    webview.show();

    // Lua-Umgebung erstellen
    sol::state lua;
    // Standardbibliotheken öffnen
    lua.open_libraries(sol::lib::base);
    // Weitere Implementierung folgt...
    // Lua-Code ausführen
    lua.script("print('Hallo von Lua!')");


    // Starte die Saucer-Anwendung
    app->run();
}
