#include "ui/windows/luaHelpWindow.h"

#include <saucer/embedded/all.hpp>
#include <saucer/navigation.hpp>
#include <saucer/script.hpp>

#include <algorithm>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <utility>
#include <windows.h>

namespace {
constexpr auto kLuaManualUrl = "https://www.lua.org/manual/5.4/";
}

LuaHelpWindow::LuaHelpWindow(std::shared_ptr<saucer::application> app)
    : m_app(std::move(app))
    , m_webview([this]() -> saucer::smartview {
          auto window = saucer::window::create(m_app.get());
          if (!window.has_value()) {
              throw std::runtime_error("LuaHelpWindow: failed to create saucer::window");
          }

          saucer::webview::options options{window.value()};
          options.storage_path = std::filesystem::temp_directory_path() / "toolbox-lua-help-webview2";
          options.browser_flags.insert("--disable-gpu");
          auto webview = saucer::smartview::create(options);
          if (!webview.has_value()) {
              throw std::runtime_error("LuaHelpWindow: failed to create saucer::smartview");
          }
          return std::move(webview.value());
      }())
{
}

void LuaHelpWindow::initialize() {
    m_hwndModule = std::make_unique<hwnd_module>(&m_webview);
    m_hwnd = m_hwndModule->get_hwnd();
    configureWindow();
    exposeToJs();
    injectDocumentationToolbar();
    loadResources();

#ifdef _DEBUG
    m_webview.set_dev_tools(false);
#endif

    m_webview.on<saucer::webview::event::navigate>([](const saucer::navigation& navigation) {
        const auto scheme = navigation.url().scheme();
        const auto host = navigation.url().host();
        if ((scheme == "saucer" && host && *host == "embedded") || scheme == "about") {
            return saucer::policy::allow;
        }
        if (scheme == "https" && host && *host == "www.lua.org") {
            const auto path = navigation.url().path().generic_string();
            if (path.starts_with("/manual/5.4")) {
                return saucer::policy::allow;
            }
        }
        return saucer::policy::block;
    });

    m_webview.parent().on<saucer::window::event::close>([this]() -> saucer::policy {
        m_webview.parent().hide();
        return saucer::policy::block;
    });
}

void LuaHelpWindow::show() {
    m_webview.serve("/html/lua_cheatsheet.html");
    configureWindow();
    m_webview.parent().show();
    m_webview.parent().focus();
}

void LuaHelpWindow::configureWindow() {
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    RECT workArea{};
    int workLeft = 0;
    int workTop = 0;
    int workWidth = screenWidth;
    int workHeight = screenHeight;
    if (SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0)) {
        workLeft = static_cast<int>(workArea.left);
        workTop = static_cast<int>(workArea.top);
        workWidth = static_cast<int>(workArea.right - workArea.left);
        workHeight = static_cast<int>(workArea.bottom - workArea.top);
    }

    const int width = std::min(980, static_cast<int>(workWidth * 0.84));
    const int height = std::min(820, static_cast<int>(workHeight * 0.86));

    m_webview.parent().set_size({width, height});
    const saucer::color background{0x0b, 0x1c, 0x2c, 0x00};
    m_webview.set_background(background);
    m_webview.parent().set_background(background);
    m_webview.parent().set_decorations(saucer::window::decoration::none);

    if (m_hwnd) {
        SetWindowPos(m_hwnd, nullptr,
                     workLeft + (workWidth - width) / 2,
                     workTop + (workHeight - height) / 2,
                     0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void LuaHelpWindow::loadResources() {
    auto resources = saucer::embedded::all();
    if (!resources.contains("/html/lua_cheatsheet.html")) {
        throw std::runtime_error("LuaHelpWindow: lua_cheatsheet.html is not embedded");
    }

    m_webview.embed(resources);
    m_webview.set_url("saucer://embedded/html/lua_cheatsheet.html");
    m_webview.set_context_menu(false);

    if (const auto icon = resources.find("/ico/toolbox.png"); icon != resources.end()) {
        m_webview.parent().set_icon(saucer::icon::from(icon->second.content).value());
    }
    m_webview.parent().set_title("Toolbox - Lua-Hilfe");
}

void LuaHelpWindow::exposeToJs() {
    m_webview.expose("showLuaCheatsheet", [this]() {
        showCheatsheet();
    });
    m_webview.expose("showOfficialLuaDocs", [this]() {
        showOfficialDocumentation();
    });
    m_webview.expose("luaDocsBack", [this]() {
        m_webview.back();
    });
    m_webview.expose("luaDocsForward", [this]() {
        m_webview.forward();
    });
    m_webview.expose("reloadLuaDocs", [this]() {
        m_webview.reload();
    });
}

void LuaHelpWindow::injectDocumentationToolbar() {
    const std::string script = R"JS((() => {
            if (location.hostname !== 'www.lua.org' || !location.pathname.startsWith('/manual/5.4')) {
                return;
            }
            if (document.getElementById('toolbox-lua-doc-toolbar')) {
                return;
            }

            const style = document.createElement('style');
            style.textContent = `
                html { scroll-padding-top: 112px; }
                body { padding-top: 104px !important; }
                #toolbox-lua-doc-toolbar {
                    position: fixed; inset: 0 0 auto 0; z-index: 2147483647;
                    height: 104px; box-sizing: border-box; display: flex;
                    flex-direction: column; background: #0d2234; color: #dff6ff;
                    font: 12px/1.2 "Segoe UI", sans-serif;
                    box-shadow: 0 5px 18px rgba(0, 0, 0, .28);
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-titlebar {
                    height: 52px; box-sizing: border-box; display: flex;
                    align-items: center; justify-content: space-between;
                    padding: 10px 12px; border-bottom: 1px solid rgba(140, 210, 255, .2);
                    background: linear-gradient(180deg, rgba(20, 45, 70, .96), rgba(12, 28, 45, .94));
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-title-left,
                #toolbox-lua-doc-toolbar .toolbox-doc-window-actions,
                #toolbox-lua-doc-toolbar .toolbox-doc-tabs {
                    display: flex; align-items: center;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-title-left { gap: 10px; }
                #toolbox-lua-doc-toolbar .toolbox-doc-window-actions { gap: 8px; }
                #toolbox-lua-doc-toolbar .toolbox-doc-mark {
                    width: 26px; height: 26px; display: grid; place-items: center;
                    border: 1px solid rgba(140, 210, 255, .38); border-radius: 8px;
                    background: rgba(79, 195, 255, .14); color: #8fe7ff;
                    font: 700 18px/1 Georgia, serif;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-title {
                    color: #b8d3e3; font-size: 14px; letter-spacing: .4px;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-window-button,
                #toolbox-lua-doc-toolbar .toolbox-doc-nav-button {
                    border: 1px solid rgba(140, 210, 255, .35); border-radius: 8px;
                    background: rgba(10, 26, 40, .7); color: #dff6ff;
                    font: inherit; cursor: pointer;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-window-button {
                    width: 30px; height: 26px; padding: 0;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-tabs {
                    height: 52px; box-sizing: border-box; gap: 6px; padding: 9px 10px 0;
                    border-bottom: 1px solid rgba(140, 210, 255, .18);
                    background: rgba(10, 26, 40, .92);
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-tab {
                    align-self: stretch; position: relative; bottom: -1px;
                    border: 1px solid transparent; border-bottom: 0;
                    border-radius: 10px 10px 0 0; padding: 0 14px;
                    background: transparent; color: #b8d3e3;
                    font: inherit; font-weight: 650; cursor: pointer;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-active {
                    border-color: rgba(140, 210, 255, .28);
                    background: rgba(19, 43, 63, .96); color: #dff6ff;
                }
                #toolbox-lua-doc-toolbar .toolbox-doc-spacer { flex: 1; }
                #toolbox-lua-doc-toolbar .toolbox-doc-origin { color: #8fdcff; }
                #toolbox-lua-doc-toolbar .toolbox-doc-nav-button {
                    width: 30px; height: 28px; padding: 0;
                }
                #toolbox-lua-doc-toolbar button:hover { background: rgba(30, 65, 95, .9); }
            `;
            document.head.append(style);

            const toolbar = document.createElement('div');
            toolbar.id = 'toolbox-lua-doc-toolbar';

            const addButton = (parent, label, title, action, className = '') => {
                const button = document.createElement('button');
                button.type = 'button';
                button.textContent = label;
                button.title = title;
                button.className = className;
                button.setAttribute('data-webview-ignore', '');
                if (action) {
                    button.addEventListener('click', action);
                }
                parent.append(button);
                return button;
            };

            const titlebar = document.createElement('div');
            titlebar.className = 'toolbox-doc-titlebar';
            titlebar.setAttribute('data-webview-drag', '');
            const titleLeft = document.createElement('div');
            titleLeft.className = 'toolbox-doc-title-left';
            titleLeft.setAttribute('data-webview-drag', '');
            const mark = document.createElement('span');
            mark.className = 'toolbox-doc-mark';
            mark.textContent = 'λ';
            mark.setAttribute('data-webview-drag', '');
            const title = document.createElement('span');
            title.className = 'toolbox-doc-title';
            title.textContent = 'Lua-Hilfe';
            title.setAttribute('data-webview-drag', '');
            titleLeft.append(mark, title);
            const windowActions = document.createElement('div');
            windowActions.className = 'toolbox-doc-window-actions';
            const minimize = addButton(windowActions, '−', 'Minimieren', null, 'toolbox-doc-window-button');
            minimize.setAttribute('data-webview-minimize', '');
            const close = addButton(windowActions, '×', 'Schließen', null, 'toolbox-doc-window-button');
            close.setAttribute('data-webview-close', '');
            titlebar.append(titleLeft, windowActions);

            const tabs = document.createElement('nav');
            tabs.className = 'toolbox-doc-tabs';
            tabs.setAttribute('aria-label', 'Lua-Hilfe');
            addButton(tabs, 'Cheatsheet', 'Zum Toolbox-Cheatsheet',
                () => saucer.exposed.showLuaCheatsheet(), 'toolbox-doc-tab');
            addButton(tabs, 'Offizielle Lua-5.4-Doku', 'Startseite des Lua-Handbuchs',
                () => saucer.exposed.showOfficialLuaDocs(), 'toolbox-doc-tab toolbox-doc-active');

            const spacer = document.createElement('span');
            spacer.className = 'toolbox-doc-spacer';
            tabs.append(spacer);

            const origin = document.createElement('span');
            origin.className = 'toolbox-doc-origin';
            origin.textContent = 'Online · lua.org';
            tabs.append(origin);
            addButton(tabs, '←', 'Zurück', () => saucer.exposed.luaDocsBack(), 'toolbox-doc-nav-button');
            addButton(tabs, '→', 'Vor', () => saucer.exposed.luaDocsForward(), 'toolbox-doc-nav-button');
            addButton(tabs, '⟳', 'Neu laden', () => saucer.exposed.reloadLuaDocs(), 'toolbox-doc-nav-button');
            toolbar.append(titlebar, tabs);
            document.body.prepend(toolbar);
        })())JS";

    m_webview.inject({
        .code = script,
        .run_at = saucer::script::time::ready,
        .no_frames = true,
        .clearable = false,
    });

    m_webview.on<saucer::webview::event::navigated>([this, script](const saucer::url& url) {
        const auto host = url.host();
        if (url.scheme() == "https" && host && *host == "www.lua.org" &&
            url.path().generic_string().starts_with("/manual/5.4")) {
            m_webview.saucer::webview::execute(script);
        }
    });
}

void LuaHelpWindow::showCheatsheet() {
    m_webview.serve("/html/lua_cheatsheet.html");
}

void LuaHelpWindow::showOfficialDocumentation() {
    m_webview.set_url(kLuaManualUrl);
}


