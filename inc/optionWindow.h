#pragma once

#include <saucer/smartview.hpp>
#include "modules/hwnd_module.h"
#include <saucer/embedded/all.hpp>
#include <sol/sol.hpp>
#include <saucer/webview.hpp>
#include <functional>
#include <memory>

class optionWindow {

public:
    // Konstruktor erhält das Application-Objekt als Parameter
    optionWindow(std::shared_ptr<saucer::application>& app,
                 std::function<int()> getLuaTimeoutSeconds,
                 std::function<void(int)> setLuaTimeoutSeconds,
                 std::function<std::string()> getActiveToolName,
                 std::function<std::string()> getToolConfigIni,
                 std::function<void(const std::string &)> setToolConfigIni,
                 std::function<void()> openIndex);

    // Methode zum Anzeigen des Fensters
    void show();

    // Für die Fensterinitialisierung
    void initialize();
    void setHWND(HWND hwnd);
    void toggleDevTools();

private:
    std::shared_ptr<saucer::application> m_app;
    saucer::smartview m_webview;
    std::unique_ptr<hwnd_module> m_hwnd_module;
    HWND m_hwnd;
    std::function<int()> m_getLuaTimeoutSeconds;
    std::function<void(int)> m_setLuaTimeoutSeconds;
    std::function<std::string()> m_getActiveToolName;
    std::function<std::string()> m_getToolConfigIni;
    std::function<void(const std::string &)> m_setToolConfigIni;
    std::function<void()> m_openIndex;

    void configureWindow();
    void loadResources();
    void runLuaScript();
    void exposeToJs();
};
