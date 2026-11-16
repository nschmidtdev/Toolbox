#pragma once

#include <saucer/smartview.hpp>
#include "platform/windows/hwnd_module.h"
#include <saucer/webview.hpp>
#include <chrono>
#include "lua/luaRunner.h"
#include "ui/windows/luaHelpWindow.h"
#include "ui/windows/optionWindow.h"
#include "ui/saucer/resourceLoader.h"
#include "core/toolConfig.h"
#include "ui/saucer/toolboxJsBridge.h"
#include "core/toolRegistry.h"
#include "platform/windows/windowPlacement.h"

class ToolboxWindow {
public:
    // Konstruktor erhält das Application-Objekt als Parameter
    explicit ToolboxWindow(std::shared_ptr<saucer::application>& app);
    ~ToolboxWindow();

    // Methode zum Anzeigen des Fensters
    void show();
    void hide();
    [[nodiscard]] bool isVisible() const noexcept;
    // Für die Fensterinitialisierung
    void initialize();

    void setupToolboxWindow();
    void toggleDevTools();

    std::vector<ToolboxItem> m_toolboxItems;

    saucer::smartview m_webview;

private:
    std::unique_ptr<hwnd_module> m_hwnd_module;
    HWND m_hwnd{};
    std::shared_ptr<saucer::application> m_app;
    std::unique_ptr<optionWindow> m_optionWindow;
    std::unique_ptr<LuaHelpWindow> m_luaHelpWindow;
    std::thread m_threadMonitor;
    std::jthread m_repositionThread;
    std::atomic_bool m_isVisible = false;
    std::atomic_bool m_isIndex = true;
    std::atomic<bool> m_runningMonitor = true;
    std::chrono::steady_clock::time_point m_lastShowTime{};
    std::atomic_bool m_seenFocusSinceShow = false;
    std::shared_ptr<std::atomic_bool> m_alive = std::make_shared<std::atomic_bool>(true);

    std::string jsonString;

    std::filesystem::path userPath = userDirectory();

    static std::filesystem::path userDirectory();
    void startThreadMonitor();
    void scheduleDelayedReposition();

    bool serveHtmlFile(const std::string &htmlPath, bool setDecorations);

    void configureWindow();
    void moveWindowTo(int x, int y);
    void loadResources();

    void ExposeToJs();

    bool ensureToolboxInUserPath();

    void fillToolboxMenu();

    void debug_print();

    LuaRunner::RunResult run_lua(int id);
    std::string run_lua_path(const std::string& toolPath);
    void cancel_lua(const std::string& toolPath);

    void monitor_focus();

    void open_file_system();

    void open_cmd();

    void setWindowOpacity(int percent);
    int getWindowOpacity() const;

    void SetJsonItems();

    void openEinst();
    void openEinst(const std::string& toolPath);
    void openAddTool();
    void openLuaHelp();
    void centerWindow();
    void resizeWindow(int width, int height);
    void resizeWindow(double widthPercent, double heightPercent);

    void openIndex();
    void getNewContent();

    std::string getActiveToolDetails() const;
    std::string saveActiveToolDetails(const std::string &payload);
    std::string openActiveToolFolder() const;

    std::filesystem::path m_activeToolPath;
    LuaRunner m_luaRunner;
    ToolConfigStore m_configStore;
    int m_lastOpacity = 100;

    std::filesystem::path getToolConfigPath(int id) const;
    int getLuaTimeoutSecondsForId(int id) const;
    std::string createTool(const std::string &payload);
    std::string deleteTool(const std::string& toolPath);
    optionWindow& optionWindowInstance();
    LuaHelpWindow& luaHelpWindowInstance();
};
