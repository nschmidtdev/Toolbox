#pragma once

#include <saucer/smartview.hpp>
#include "modules/hwnd_module.h"
#include "all.hpp"
#include <sol/sol.hpp>
#include <saucer/webview.hpp>

class ToolboxWindow {
public:
    // Konstruktor erhält das Application-Objekt als Parameter
    explicit ToolboxWindow(std::shared_ptr<saucer::application>& app);

    // Methode zum Anzeigen des Fensters
    void show();

    // Für die Fensterinitialisierung
    void initialize();

    void OptionWindow();

    struct ToolboxItem{
        std::string id;
        std::string name;
        std::string path;
        std::string icon;
        std::string lua_script;
        std::string description;
        std::string category;
        std::string version;
        std::string author;
        std::string url;
        std::string license;
    };

    std::vector<ToolboxItem> m_toolboxItems;

private:
    std::shared_ptr<saucer::application> m_app;
    saucer::smartview<saucer::default_serializer, hwnd_module> m_webview;
    void configureWindow();
    void loadResources();
    void runLuaScript();

    void ExposeToJs();

    bool ensureToolboxInUserPath();

    void fillToolboxMenu();

    void debug_print();

    void run_lua(int id);
};
