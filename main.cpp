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

    saucer::smartview<saucer::default_serializer, hwnd_module> webview({
        .application = app,
    });

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Berechne die relativen Fenstermaße
    int windowWidth = static_cast<int>(screenWidth * (400.0 / 1920.0));
    int windowHeight = static_cast<int>(screenHeight * (600.0 / 1080.0));

    webview.set_size(windowWidth, windowHeight);
    webview.set_force_dark_mode(true);

    int xPos = screenWidth - windowWidth; // 400 ist die Fensterbreite
    int yPos = screenHeight - 42 - windowHeight; // 600 ist die Fensterhöhe

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
    auto resources = saucer::embedded::all();

    if (resources.find("card.html") == resources.end()) {
        std::cerr << "Fehler: 'card.html' wurde nicht gefunden!" << std::endl;
        return 1;
    }
    // Überprüfen, ob die "index.html"-Ressource verfügbar ist
    auto it = resources.find("index.html");
    if (it == resources.end())
    {
        std::cerr << "Fehler: 'index.html' wurde nicht gefunden!" << std::endl;
        return 1;
    }
    webview.embed(resources); // Bindet alle eingebetteten Ressourcen ein
    webview.serve("index.html"); // Stellt "index.html" bereit


    webview.set_context_menu(false);

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
