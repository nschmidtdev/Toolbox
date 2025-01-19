#pragma once

#include <saucer/smartview.hpp>
#include "modules/hwnd_module.h"
#include "all.hpp"
#include <sol/sol.hpp>
#include <saucer/webview.hpp>

class optionWindow {

public:
    // Konstruktor erhält das Application-Objekt als Parameter
    explicit optionWindow(std::shared_ptr<saucer::application>& app);

    // Methode zum Anzeigen des Fensters
    void show();

    // Für die Fensterinitialisierung
    void initialize();
    void setHWND(HWND hwnd);

private:
    std::shared_ptr<saucer::application> m_app;
    saucer::smartview<saucer::default_serializer> m_webview;
    HWND m_hwnd;

    void configureWindow();
    void loadResources();
    void runLuaScript();
};
