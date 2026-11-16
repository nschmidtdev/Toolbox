#include "ui/windows/optionWindow.h"
#include "core/toolTemplates.h"
#include "platform/fileDialog.h"
#include <filesystem>
#include <iostream>
#include <windows.h>
#include <nlohmann/json.hpp>
#include <saucer/embedded/all.hpp>
#include <saucer/navigation.hpp>
#include <saucer/app.hpp>
#include <unordered_map>

namespace {

    std::string templateJson(const ToolTemplateResult& result) {
        nlohmann::json response = {
            {"success", result.success},
            {"message", result.message},
        };
        if (result.success) {
            response["draft"] = {
                {"name", result.draft.name},
                {"description", result.draft.description},
                {"luaScript", result.draft.luaScript},
                {"templateType", result.draft.templateType},
                {"templateTarget", result.draft.templateTarget},
            };
        }
        return response.dump();
    }

    std::string selectionJson(const FileDialogSelection& selection,
                              ToolTemplateResult (*createTemplate)(const std::filesystem::path&)) {
        if (selection.cancelled) {
            return nlohmann::json({{"success", false}, {"cancelled", true}}).dump();
        }
        if (!selection.error.empty()) {
            return nlohmann::json({{"success", false}, {"message", selection.error}}).dump();
        }
        return templateJson(createTemplate(selection.path));
    }

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
                           std::function<std::string()> getToolDetails,
                           std::function<std::string(const std::string &)> saveToolDetails,
                           std::function<std::string()> openToolFolder,
                           std::function<std::string(const std::string &)> createTool,
                           std::function<void()> openLuaHelp,
                           std::function<void()> openIndex)
    : m_app(app)
    , m_webview([&]() -> saucer::smartview {
          auto window_res = saucer::window::create(app.get());
          if (!window_res.has_value()) {
              throw std::runtime_error("optionWindow: failed to create saucer::window");
          }
          saucer::webview::options opts{window_res.value()};
          opts.storage_path = std::filesystem::temp_directory_path() / "toolbox-option-webview2";
          opts.browser_flags.insert("--disable-gpu");
          auto sv_res = saucer::smartview::create(opts);
          if (!sv_res.has_value()) {
              throw std::runtime_error("optionWindow: failed to create saucer::smartview");
          }
          return std::move(sv_res.value());
      }())
    , m_hwnd()
    , m_getToolDetails(std::move(getToolDetails))
    , m_saveToolDetails(std::move(saveToolDetails))
    , m_openToolFolder(std::move(openToolFolder))
    , m_createTool(std::move(createTool))
    , m_openLuaHelp(std::move(openLuaHelp))
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

    RECT workArea{};
    if (SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0)) {
        screenWidth = static_cast<int>(workArea.right - workArea.left);
        screenHeight = static_cast<int>(workArea.bottom - workArea.top);
    }

    int windowWidth = static_cast<int>(screenWidth * (500.0 / 1920.0));
    int windowHeight = static_cast<int>(screenHeight * (700.0 / 1080.0));

    m_webview.parent().set_size({windowWidth, windowHeight});
    const saucer::color bg{0x0b, 0x1c, 0x2c, 0x00};
    m_webview.set_background(bg);
    m_webview.parent().set_background(bg);
    m_webview.parent().set_decorations(saucer::window::decoration::none);

    int xPos = workArea.left + (screenWidth - windowWidth) / 2;
    int yPos = workArea.top + (screenHeight - windowHeight) / 2;

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

    auto it = resources.find("/html/einstellungen_custom.html");
    if (it == resources.end()) {
        std::cerr << "Fehler: 'einstellungen_custom.html' wurde nicht gefunden!" << std::endl;
        return;
    }
    m_webview.embed(resources);
    // Explicit URL to avoid accidental fallback to main index
    m_webview.set_url("saucer://embedded/html/einstellungen_custom.html");
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
    m_webview.serve("/html/einstellungen_custom.html");
    configureWindow();
    m_webview.parent().show();
    m_webview.parent().focus();
}

void optionWindow::showCreateTool() {
    m_webview.serve("/html/add_tool.html");
    configureWindow();
    m_webview.parent().show();
    m_webview.parent().focus();
}

void optionWindow::exposeToJs() {
    m_webview.expose("openIndex", [&]() {
        if (m_openIndex) {
            m_openIndex();
        }
        m_webview.parent().hide();
    });

    m_webview.expose("getToolDetails", [&]() -> std::string {
        return m_getToolDetails ? m_getToolDetails() :
            R"({"success":false,"message":"Kein Tool ist ausgewaehlt."})";
    });

    m_webview.expose("saveToolDetails", [&](const std::string& payload) -> std::string {
        return m_saveToolDetails ? m_saveToolDetails(payload) :
            R"({"success":false,"message":"Das Tool kann nicht gespeichert werden."})";
    });

    m_webview.expose("openToolFolder", [&]() -> std::string {
        return m_openToolFolder ? m_openToolFolder() :
            R"({"success":false,"message":"Der Toolordner kann nicht geoeffnet werden."})";
    });

    m_webview.expose("createTool", [&](const std::string &payload) -> std::string {
        if (m_createTool) {
            return m_createTool(payload);
        }
        return R"({"success":false,"message":"Tool-Erstellung ist nicht verfuegbar."})";
    });

    m_webview.expose("selectProgramTemplate", [&]() -> std::string {
        return selectionJson(FileDialog::select(FileDialog::programSelectionRequest()),
                             &ToolTemplates::programLauncher);
    });

    m_webview.expose("selectFolderTemplate", [&]() -> std::string {
        return selectionJson(FileDialog::select(FileDialog::folderSelectionRequest()),
                             &ToolTemplates::folderLauncher);
    });

    m_webview.expose("createWebsiteTemplate", [&](const std::string& url) -> std::string {
        return templateJson(ToolTemplates::websiteLauncher(url));
    });

    m_webview.expose("openLuaHelp", [&]() {
        if (m_openLuaHelp) {
            m_openLuaHelp();
        }
    });
}

void optionWindow::toggleDevTools() {
    m_webview.set_dev_tools(!m_webview.dev_tools());
}
