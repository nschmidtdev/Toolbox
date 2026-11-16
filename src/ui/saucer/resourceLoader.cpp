#include "ui/saucer/resourceLoader.h"

#include <iostream>

#include <saucer/embedded/all.hpp>

namespace {

std::string normalizeEmbeddedPath(const std::string& path) {
    if (!path.empty() && path[0] != '/') {
        return "/" + path;
    }
    return path;
}

bool applyToolboxIcon(saucer::smartview& webview, const decltype(saucer::embedded::all())& resources) {
    const auto iconIt = resources.find("/ico/toolbox.png");
    if (iconIt == resources.end()) {
        std::cerr << "Fehler: 'toolbox.png' wurde nicht gefunden!" << std::endl;
        return false;
    }

    if (auto windowIcon = saucer::icon::from(iconIt->second.content); windowIcon.has_value()) {
        webview.parent().set_icon(windowIcon.value());
        return true;
    }

    std::cerr << "Fehler: 'toolbox.png' konnte nicht als Fenster-Icon geladen werden!" << std::endl;
    return false;
}

} // namespace

bool ResourceLoader::loadToolboxShell(saucer::smartview& webview) {
    auto resources = saucer::embedded::all();

    if (!resources.contains("/html/card.html")) {
        std::cerr << "Fehler: 'card.html' wurde nicht gefunden!" << std::endl;
        return false;
    }

    if (!resources.contains("/html/index.html")) {
        std::cerr << "Fehler: 'index.html' wurde nicht gefunden!" << std::endl;
        return false;
    }

    webview.embed(resources);
    webview.set_url("saucer://embedded/html/index.html");
    webview.set_context_menu(false);
    applyToolboxIcon(webview, resources);
    webview.parent().set_title("Toolbox");
    saucer::webview::register_scheme("Toolbox");
    return true;
}

bool ResourceLoader::serveHtml(saucer::smartview& webview, const std::string& htmlPath, bool setDecorations) {
    auto resources = saucer::embedded::all();
    const std::string key = normalizeEmbeddedPath(htmlPath);

    if (!resources.contains(key)) {
        std::cerr << "Fehler: '" << key << "' wurde nicht gefunden!" << std::endl;
        return false;
    }

    webview.serve(key);
    webview.parent().set_decorations(setDecorations ? saucer::window::decoration::full
                                                    : saucer::window::decoration::none);
    return true;
}
