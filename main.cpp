#include <iostream>
#include <saucer/smartview.hpp>
#include <saucer/webview.hpp>
#include <saucer/wv2.webview.impl.hpp>
#include <windows.h>

#include "all.hpp"

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

    saucer::smartview webview{{
        .application = app,
    }};

    webview.set_size(400, 600);
    webview.set_force_dark_mode(true);
    //webview.start_drag(true);
    //SendMessage(webview.native(), nullptr,2, 2, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

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

    // Starte die Saucer-Anwendung
    app->run();
}
