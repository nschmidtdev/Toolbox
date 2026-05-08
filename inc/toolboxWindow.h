#pragma once

#include <saucer/smartview.hpp>
#include "modules/hwnd_module.h"
#include <saucer/webview.hpp>
#include <chrono>
#include "luaRunner.h"
#include "optionWindow.h"
#include "resourceLoader.h"
#include "toolConfig.h"
#include "toolboxJsBridge.h"
#include "toolRegistry.h"
#include "windowPlacement.h"

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

    void ExposeToJs();

    bool ensureToolboxInUserPath();

    void fillToolboxMenu();

    void debug_print();

    void run_lua(int id);
    void cancel_lua(int id);

    void monitor_focus();

    void open_file_system();

    void open_cmd();

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

    int m_activeToolId = -1;
    LuaRunner m_luaRunner;
    ToolConfigStore m_configStore;

    std::filesystem::path getToolConfigPath(int id) const;
    void ensureConfigExists(int id) const;
    int getLuaTimeoutSecondsForId(int id) const;
    std::string getToolConfigIni() const;
    void setToolConfigIni(const std::string &content);
};
