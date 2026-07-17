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
                 std::function<std::string()> getToolDetails,
                 std::function<std::string(const std::string &)> saveToolDetails,
                 std::function<std::string()> openToolFolder,
                 std::function<std::string(const std::string &)> createTool,
                 std::function<void()> openLuaHelp,
                 std::function<void()> openIndex);

    // Methode zum Anzeigen des Fensters
    void show();
    void showCreateTool();

    // Für die Fensterinitialisierung
    void initialize();
    void setHWND(HWND hwnd);
    void toggleDevTools();

private:
    std::shared_ptr<saucer::application> m_app;
    saucer::smartview m_webview;
    std::unique_ptr<hwnd_module> m_hwnd_module;
    HWND m_hwnd;
    std::function<std::string()> m_getToolDetails;
    std::function<std::string(const std::string &)> m_saveToolDetails;
    std::function<std::string()> m_openToolFolder;
    std::function<std::string(const std::string &)> m_createTool;
    std::function<void()> m_openLuaHelp;
    std::function<void()> m_openIndex;

    void configureWindow();
    void loadResources();
    void runLuaScript();
    void exposeToJs();
};
