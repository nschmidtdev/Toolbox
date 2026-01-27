#include "optionWindow.h"
#include <iostream>
#include <windows.h>
#include <saucer/embedded/all.hpp>
#include <saucer/navigation.hpp>
#include <saucer/app.hpp>
#include <unordered_map>

namespace {
    std::unordered_map<HWND, WNDPROC> g_option_prev_procs;

    LRESULT CALLBACK option_wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
        if (msg == WM_KEYDOWN && wparam == VK_F12) {
            auto *self = reinterpret_cast<optionWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
            if (self) {
                self->toggleDevTools();
                return 0;
            }
        }
        const auto it = g_option_prev_procs.find(hwnd);
        if (it != g_option_prev_procs.end()) {
            return CallWindowProc(it->second, hwnd, msg, wparam, lparam);
        }
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    void install_option_f12_toggle(HWND hwnd, optionWindow *self) {
        if (!hwnd || !self) {
            return;
        }
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
        auto prev = reinterpret_cast<WNDPROC>(
            SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(option_wndproc))
        );
        if (prev) {
            g_option_prev_procs[hwnd] = prev;
        }
    }
}

optionWindow::optionWindow(std::shared_ptr<saucer::application>& app,
                           std::function<int()> getLuaTimeoutSeconds,
                           std::function<void(int)> setLuaTimeoutSeconds,
                           std::function<std::string()> getActiveToolName,
                           std::function<std::string()> getToolConfigIni,
                           std::function<void(const std::string &)> setToolConfigIni,
                           std::function<void()> openIndex)
    : m_app(app)
    , m_webview([&]() -> saucer::smartview {
          auto window_res = saucer::window::create(app.get());
          if (!window_res.has_value()) {
              throw std::runtime_error("optionWindow: failed to create saucer::window");
          }
          saucer::webview::options opts{window_res.value()};
          opts.browser_flags.insert("--disable-gpu");
          auto sv_res = saucer::smartview::create(opts);
          if (!sv_res.has_value()) {
              throw std::runtime_error("optionWindow: failed to create saucer::smartview");
          }
          return std::move(sv_res.value());
      }())
    , m_hwnd()
    , m_getLuaTimeoutSeconds(std::move(getLuaTimeoutSeconds))
    , m_setLuaTimeoutSeconds(std::move(setLuaTimeoutSeconds))
    , m_getActiveToolName(std::move(getActiveToolName))
    , m_getToolConfigIni(std::move(getToolConfigIni))
    , m_setToolConfigIni(std::move(setToolConfigIni))
    , m_openIndex(std::move(openIndex))
{
}

void optionWindow::initialize() {
    // Modul hinzufügen
    m_hwnd_module = std::make_unique<hwnd_module>(&m_webview);
    m_hwnd = m_hwnd_module->get_hwnd();
    install_option_f12_toggle(m_hwnd, this);
    configureWindow();
    exposeToJs();
    loadResources();
#ifdef _DEBUG
    m_webview.set_dev_tools(false);
#endif
    m_webview.on<saucer::webview::event::navigate>([](const saucer::navigation& nav) {
        const auto scheme = nav.url().scheme();
        const auto host = nav.url().host();
        if (scheme == "saucer" && host && *host == "embedded") {
            return saucer::policy::allow;
        }
        if (scheme == "about") {
            return saucer::policy::allow;
        }
        return saucer::policy::block;
    });

    m_webview.parent().on<saucer::window::event::close>([this]() -> saucer::policy {
        if (m_openIndex) {
            m_openIndex();
        }
        m_webview.parent().hide();
        return saucer::policy::block;
    });
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

    m_webview.parent().set_size({windowWidth, windowHeight});
    const saucer::color bg{0x1e, 0x1e, 0x2e, 0xFF};
    m_webview.set_background(bg);
    m_webview.parent().set_background(bg);

    int xPos = (screenWidth - windowWidth) / 2;
    int yPos = (screenHeight - windowHeight) / 2;

    // HWND über das Modul abrufen
    if (HWND hwnd = m_hwnd) {
        SetWindowPos(hwnd, nullptr, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void optionWindow::loadResources() {
    auto resources = saucer::embedded::all();

    if (!resources.contains("/html/card.html")) {
        std::cerr << "Fehler: 'card.html' wurde nicht gefunden!" << std::endl;
        return;
    }

    auto it = resources.find("/html/einstellungen.html");
    if (it == resources.end()) {
        std::cerr << "Fehler: 'einstellungen.html' wurde nicht gefunden!" << std::endl;
        return;
    }
    m_webview.embed(resources);
    // Explicit URL to avoid accidental fallback to main index
    m_webview.set_url("saucer://embedded/html/einstellungen.html");
    m_webview.set_context_menu(false);

    if (!resources.contains("/ico/toolbox.png")) {
        std::cerr << "Fehler: 'toolbox.png' wurde nicht gefunden!" << std::endl;
        return;
    }

    saucer::icon window_icon = saucer::icon::from(resources.find("/ico/toolbox.png")->second.content).value();
    m_webview.parent().set_icon(window_icon);
    m_webview.parent().set_title("Toolbox");
    saucer::webview::register_scheme("Toolbox");
}

void optionWindow::runLuaScript() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hallo von Lua!')");
}

void optionWindow::show() {
    m_webview.parent().show();
    runLuaScript();
    configureWindow();
}

void optionWindow::exposeToJs() {
    m_webview.expose("openIndex", [&]() {
        if (m_openIndex) {
            m_openIndex();
        }
        m_webview.parent().hide();
    });

    m_webview.expose("getLuaTimeoutSeconds", [&]() -> int {
        if (m_getLuaTimeoutSeconds) {
            return m_getLuaTimeoutSeconds();
        }
        return 30;
    });

    m_webview.expose("setLuaTimeoutSeconds", [&](int seconds) {
        if (m_setLuaTimeoutSeconds) {
            m_setLuaTimeoutSeconds(seconds);
        }
    });

    m_webview.expose("getActiveToolName", [&]() -> std::string {
        if (m_getActiveToolName) {
            return m_getActiveToolName();
        }
        return {};
    });

    m_webview.expose("getToolConfigIni", [&]() -> std::string {
        if (m_getToolConfigIni) {
            return m_getToolConfigIni();
        }
        return {};
    });

    m_webview.expose("setToolConfigIni", [&](const std::string &content) {
        if (m_setToolConfigIni) {
            m_setToolConfigIni(content);
        }
    });
}

void optionWindow::toggleDevTools() {
    m_webview.set_dev_tools(!m_webview.dev_tools());
}
