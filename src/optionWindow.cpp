#include "optionWindow.h"
#include <iostream>
#include <windows.h>

optionWindow::optionWindow(std::shared_ptr<saucer::application>& app)
    : m_app(app), m_webview({.application = app}), m_hwnd()
{
}

void optionWindow::initialize() {
    // Modul hinzufügen
    configureWindow();
    loadResources();
}

void optionWindow::setHWND(HWND hwnd)
{
    m_hwnd = hwnd;
}

void optionWindow::configureWindow() {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowWidth = static_cast<int>(screenWidth * (500.0 / 1920.0));
    int windowHeight = static_cast<int>(screenHeight * (700.0 / 1080.0));

    m_webview.set_size(windowWidth, windowHeight);
    m_webview.set_force_dark_mode(true);

    int xPos = screenWidth - windowWidth;
    int yPos = screenHeight - 42 - windowHeight;

    // HWND über das Modul abrufen
    if (HWND hwnd = m_hwnd) {
        SetWindowPos(hwnd, nullptr, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void optionWindow::loadResources() {
    auto resources = saucer::embedded::all();

    if (!resources.contains("html/card.html")) {
        std::cerr << "Fehler: 'card.html' wurde nicht gefunden!" << std::endl;
        return;
    }

    auto it = resources.find("html/index.html");
    if (it == resources.end()) {
        std::cerr << "Fehler: 'index.html' wurde nicht gefunden!" << std::endl;
        return;
    }
    m_webview.embed(resources);
    m_webview.serve("html/index.html");
    m_webview.set_context_menu(false);

    if (!resources.contains("ico/toolbox.png")) {
        std::cerr << "Fehler: 'toolbox.png' wurde nicht gefunden!" << std::endl;
        return;
    }

    saucer::icon window_icon = saucer::icon::from(resources.find("ico/toolbox.png")->second.content).value();
    m_webview.set_icon(window_icon);
    m_webview.set_title("Toolbox");
    m_webview.register_scheme("Toolbox");
}

void optionWindow::runLuaScript() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hallo von Lua!')");
}

void optionWindow::show() {
    m_webview.show();
    runLuaScript();
}
