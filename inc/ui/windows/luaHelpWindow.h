#pragma once

#include "platform/windows/hwnd_module.h"

#include <saucer/app.hpp>
#include <saucer/smartview.hpp>

#include <memory>

class LuaHelpWindow {
public:
    explicit LuaHelpWindow(std::shared_ptr<saucer::application> app);

    void initialize();
    void show();

private:
    std::shared_ptr<saucer::application> m_app;
    saucer::smartview m_webview;
    std::unique_ptr<hwnd_module> m_hwndModule;
    HWND m_hwnd{};

    void configureWindow();
    void loadResources();
    void exposeToJs();
    void injectDocumentationToolbar();
    void showCheatsheet();
    void showOfficialDocumentation();
};
