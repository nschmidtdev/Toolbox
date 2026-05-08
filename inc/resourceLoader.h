#pragma once

#include <string>

#include <saucer/smartview.hpp>

class ResourceLoader {
public:
    static bool loadToolboxShell(saucer::smartview& webview);
    static bool serveHtml(saucer::smartview& webview, const std::string& htmlPath, bool setDecorations);
};
