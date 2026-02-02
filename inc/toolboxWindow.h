#pragma once

#include <saucer/smartview.hpp>
#include "modules/hwnd_module.h"
#include <saucer/embedded/all.hpp>
#include <sol/sol.hpp>
#include <saucer/webview.hpp>
#include <unordered_map>
#include <mutex>
#include <chrono>
#include "optionWindow.h"
#include "toolConfig.h"

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
    void toggleDevTools();

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

    saucer::smartview m_webview;

private:
    std::unique_ptr<hwnd_module> m_hwnd_module;
    HWND m_hwnd{};
    std::shared_ptr<saucer::application> m_app;
    std::unique_ptr<optionWindow> m_optionWindow;
    std::thread m_threadMonitor;
    std::atomic<bool> m_runningMonitor = true;
    std::chrono::steady_clock::time_point m_lastShowTime{};
    bool m_seenFocusSinceShow = false;

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
    void cancel_lua(int id);

    void monitor_focus();

    void open_file_system();

    void SetJsonItems();

    void openEinst();
    void openEinst(int id);
    void centerWindow();
    void resizeWindow(int width, int height);
    void resizeWindow(double widthPercent, double heightPercent);

    void openIndex();
    void getNewContent();

    int getLuaTimeoutSeconds();
    void setLuaTimeoutSeconds(int seconds);
    std::string getActiveToolName();

    struct LuaTask {
        std::shared_ptr<std::atomic_bool> cancel;
    };

    std::mutex m_luaTasksMutex;
    std::unordered_map<int, LuaTask> m_luaTasks;

    int m_activeToolId = -1;
    ToolConfigStore m_configStore;

    std::filesystem::path getToolConfigPath(int id) const;
    void ensureConfigExists(int id) const;
    int getLuaTimeoutSecondsForId(int id) const;
    std::string getToolConfigIni() const;
    void setToolConfigIni(const std::string &content);
};
