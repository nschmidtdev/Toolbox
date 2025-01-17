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
    ~ToolboxWindow();

    bool m_bShow = false;

    // Methode zum Anzeigen des Fensters
    void show();
    void hide();
    // Für die Fensterinitialisierung
    void initialize();

    void setupToolboxWindow();

    std::atomic_bool isIndex = true;

    struct ToolboxItem{
        std::string id;
        std::string name;
        std::string path;
        std::string icon;
        std::string lua_script_path_string;
        std::string description;
        std::string category;
        std::string version;
        std::string author;
        std::string url;
        std::string license;
    };

    std::vector<ToolboxItem> m_toolboxItems;

    saucer::smartview<saucer::default_serializer, hwnd_module> m_webview;

private:
    std::shared_ptr<saucer::application> m_app;
    std::thread m_threadMonitor;
    std::atomic<bool> m_runningMonitor = true;

    std::string jsonString;

    int size_x,size_y;

#ifdef _WIN32
    std::filesystem::path userPath = std::getenv("USERPROFILE");  // Windows
#else
    std::filesystem::path userPath = std::getenv("HOME");  // Unix/Linux/MacOS
#endif

    void startThreadMonitor();

    bool serveHtmlFile(const std::string &htmlPath, bool setDecorations);

    void configureWindow();
    void moveWindowTo(int x, int y);
    void loadResources();
    void runLuaScript();

    void ExposeToJs();

    bool ensureToolboxInUserPath();

    void fillToolboxMenu();

    void debug_print();

    void run_lua(int id);

    void monitor_focus();

    void open_file_system();

    void SetJsonItems();

    void openEinst();
    void centerWindow();
    void resizeWindow(int width, int height);
    void resizeWindow(double widthPercent, double heightPercent);

    void openIndex();
    void getNewContent();
};
