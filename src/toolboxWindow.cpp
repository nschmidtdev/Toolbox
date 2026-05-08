#include "toolboxWindow.h"
#include <iostream>
#include <stdexcept>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif
#include <algorithm>
#include <nlohmann/json.hpp>
#include <saucer/navigation.hpp>
#include <saucer/app.hpp>
#include <format>
#include <chrono>
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace {
    std::unordered_map<HWND, WNDPROC> g_toolbox_prev_procs;

    LRESULT CALLBACK toolbox_wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
        if (msg == WM_KEYDOWN && wparam == VK_F12) {
            auto *self = reinterpret_cast<ToolboxWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
            if (self) {
                self->toggleDevTools();
                return 0;
            }
        }
        const auto it = g_toolbox_prev_procs.find(hwnd);
        if (it != g_toolbox_prev_procs.end()) {
            return CallWindowProc(it->second, hwnd, msg, wparam, lparam);
        }
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    void install_toolbox_f12_toggle(HWND hwnd, ToolboxWindow *self) {
        if (!hwnd || !self) {
            return;
        }
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
        auto prev = reinterpret_cast<WNDPROC>(
            SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(toolbox_wndproc))
        );
        if (prev) {
            g_toolbox_prev_procs[hwnd] = prev;
        }
    }
}

ToolboxWindow::ToolboxWindow(std::shared_ptr<saucer::application>& app)
    : m_webview([&]() -> saucer::smartview {
          auto window_res = saucer::window::create(app.get());
          if (!window_res.has_value()) {
              throw std::runtime_error("ToolboxWindow: failed to create saucer::window");
          }
          saucer::webview::options opts{window_res.value()};
          opts.browser_flags.insert("--disable-gpu");
          auto sv_res = saucer::smartview::create(opts);
          if (!sv_res.has_value()) {
              throw std::runtime_error("ToolboxWindow: failed to create saucer::smartview");
          }
          return std::move(sv_res.value());
      }())
    , m_app(app)
{}

void ToolboxWindow::initialize() {
    m_hwnd_module = std::make_unique<hwnd_module>(&m_webview);
    m_hwnd = m_hwnd_module->get_hwnd();
    install_toolbox_f12_toggle(m_hwnd, this);
    ensureToolboxInUserPath();
    fillToolboxMenu();
    configureWindow();
    loadResources();
    setupToolboxWindow();
}

void ToolboxWindow::setupToolboxWindow() {
    SetJsonItems();
    ExposeToJs();
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
    m_webview.parent().set_always_on_top(true);
    m_webview.parent().set_decorations(saucer::window::decoration::none);

#ifdef _DEBUG
    m_webview.set_dev_tools(true);
#endif

    startThreadMonitor();
}

void ToolboxWindow::startThreadMonitor() {
    m_threadMonitor = std::thread([this]() {
        monitor_focus();
    });
}

bool ToolboxWindow::serveHtmlFile(const std::string& htmlPath, bool setDecorations) {
    return ResourceLoader::serveHtml(m_webview, htmlPath, setDecorations);
}

void ToolboxWindow::configureWindow() {
    WindowPlacement::configureToolbox(m_webview, m_hwnd);
}

void ToolboxWindow::moveWindowTo(int x, int y) {
    WindowPlacement::moveTo(m_hwnd, x, y);
}

void ToolboxWindow::loadResources() {
    ResourceLoader::loadToolboxShell(m_webview);
}

void ToolboxWindow::show() {
    m_webview.parent().show();
    m_bShow = true;
    m_lastShowTime = std::chrono::steady_clock::now();
    m_seenFocusSinceShow = false;

    // In some cases the HWND/frame metrics are finalized only after showing.
    // Re-acquire HWND and reposition now, plus schedule a short delayed reposition.
    if (m_hwnd_module) {
        if (HWND newHwnd = m_hwnd_module->get_hwnd(); newHwnd) {
            m_hwnd = newHwnd;
        }
    }

    if (m_hwnd) {
        SetForegroundWindow(m_hwnd);
        SetActiveWindow(m_hwnd);
        SetFocus(m_hwnd);
    }

    // Immediate reposition after showing
    configureWindow();

    // Deferred reposition to catch late layouting from the framework
    std::thread([this]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        configureWindow();
    }).detach();
}

void ToolboxWindow::hide() {
    m_webview.parent().hide();
    m_bShow = false;
}

void ToolboxWindow::ExposeToJs() {
    ToolboxJsBridge::registerBindings(m_webview, {
        .getToolboxItems = [this]() { return jsonString; },
        .runLua = [this](int id) { run_lua(id); },
        .cancelLua = [this](int id) { cancel_lua(id); },
        .debugPrint = [this]() { debug_print(); },
        .openFileSystem = [this]() { open_file_system(); },
        .openCommandPrompt = [this]() { open_cmd(); },
        .openSettings = [this](int id) { openEinst(id); },
        .openIndex = [this]() { openIndex(); },
        .getNewContent = [this]() { getNewContent(); },
        .getLuaTimeoutSeconds = [this]() { return getLuaTimeoutSeconds(); },
        .setLuaTimeoutSeconds = [this](int seconds) { setLuaTimeoutSeconds(seconds); },
        .getActiveToolName = [this]() { return getActiveToolName(); },
        .getToolConfigIni = [this]() { return getToolConfigIni(); },
        .setToolConfigIni = [this](const std::string& content) { setToolConfigIni(content); },
    });
}

void ToolboxWindow::SetJsonItems() {// Konvertierung des Vektors in JSON
    nlohmann::json jsonArray = nlohmann::json::array();

    for (const auto& item : m_toolboxItems) {
        nlohmann::json jsonItem = {
                {"id", item.id},
                {"name", item.name},
                {"path", item.path},
                {"icon", item.icon},
                {"description", item.description},
                {"category", item.category},
                {"version", item.version},
                {"author", item.author},
                {"url", item.url},
                {"license", item.license}
        };
        jsonArray.push_back(jsonItem);
    }
    jsonString = "";
    // Konvertiere den JSON-Array in einen String
    jsonString = jsonArray.dump();
}

bool ToolboxWindow::ensureToolboxInUserPath() {
    return ToolRegistry::ensureToolboxDirectory(userPath);
}


void ToolboxWindow::fillToolboxMenu() {
    m_toolboxItems = ToolRegistry::loadTools(userPath);
}

void ToolboxWindow::run_lua(int id) {
    if (id < 0 || id >= static_cast<int>(m_toolboxItems.size())) {
        return;
    }

    const std::filesystem::path scriptPath = m_toolboxItems[id].lua_script_path_string;
    m_luaRunner.run(id, scriptPath, getLuaTimeoutSecondsForId(id), [this, id]() {
        m_webview.saucer::webview::execute(std::format("enableButtonByToolId({})", id));
        m_webview.reload();
    });
}

void ToolboxWindow::cancel_lua(int id) {
    m_luaRunner.cancel(id);
}
void ToolboxWindow::debug_print() {
    std::cout << "ToolboxWindow::debug_print()" << std::endl;
}

ToolboxWindow::~ToolboxWindow() {
    m_runningMonitor = false;
    if (m_threadMonitor.joinable()) {
        m_threadMonitor.join();
    }
}


void ToolboxWindow::monitor_focus() {
    while (m_runningMonitor) {
        if (m_bShow && isIndex) {
            const bool focused = m_webview.parent().focused();
            if (focused) {
                m_seenFocusSinceShow = true;
            } else if (m_seenFocusSinceShow) {
                this->hide();
            }
        }

        // Schlafpause hinzufügen, um die CPU-Last zu reduzieren
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void ToolboxWindow::open_file_system() {
    if (const std::filesystem::path toolboxDir = userPath / ".Toolbox"; std::filesystem::exists(toolboxDir) && std::filesystem::is_directory(toolboxDir)) {
        std::string path = toolboxDir.string();
        std::string command;

#ifdef _WIN32
        command = "explorer \"" + path + "\"";
#elif __APPLE__
        command = "open \"" + path + "\"";
#elif __linux__
        command = "xdg-open \"" + path + "\"";
#else
        std::cerr << "Fehler: Plattform nicht unterstützt." << std::endl;
        return;
#endif

        if (const int result = std::system(command.c_str()); result != 0) {
            std::cerr << "Fehler beim Öffnen des Verzeichnisses: " << result << std::endl;
        }
    } else {
        std::cerr << "Fehler: Das Verzeichnis .Toolbox existiert nicht." << std::endl;
    }

    fillToolboxMenu();
    SetJsonItems();
    m_webview.saucer::webview::execute("reloadContent()");
}

void ToolboxWindow::open_cmd() {
    std::string command;

#ifdef _WIN32
    command = "cmd.exe";
    ShellExecute(NULL, L"open", L"cmd.exe", NULL, NULL, SW_SHOWNORMAL);
#elif __APPLE__
    command = "open -a Terminal";
    std::system(command.c_str());
#elif __linux__
    command = "x-terminal-emulator";
    std::system(command.c_str());
#else
    std::cerr << "Fehler: Plattform nicht unterstützt." << std::endl;
#endif
}


// Beispielhafte Nutzung:
void ToolboxWindow::openEinst() {
    if (!m_optionWindow) {
        m_optionWindow = std::make_unique<optionWindow>(
            m_app,
            [this]() { return getLuaTimeoutSeconds(); },
            [this](int seconds) { setLuaTimeoutSeconds(seconds); },
            [this]() { return getActiveToolName(); },
            [this]() { return getToolConfigIni(); },
            [this](const std::string &content) { setToolConfigIni(content); },
            [this]() { openIndex(); }
        );
        m_optionWindow->initialize();
    }
    m_optionWindow->show();
}

void ToolboxWindow::openEinst(int id) {
    if (id < 0 || id >= static_cast<int>(m_toolboxItems.size())) {
        std::cerr << "openEinst: invalid tool id " << id << std::endl;
        return;
    }
    m_activeToolId = id;
    ensureConfigExists(id);
    openEinst();
}

void ToolboxWindow::centerWindow() {
    WindowPlacement::center(m_hwnd);
}

void ToolboxWindow::resizeWindow(int width, int height)
{
    WindowPlacement::resize(m_webview, width, height);
}

void ToolboxWindow::resizeWindow(double widthPercent, double heightPercent)
{
    WindowPlacement::resizePercent(m_webview, widthPercent, heightPercent);
}

void ToolboxWindow::openIndex() {
    if (!m_bShow) {
        show();
    }
    if (!serveHtmlFile("html/index.html", false)) {
        return;
    }
    getNewContent();
}

void ToolboxWindow::getNewContent()
{
    configureWindow();
    fillToolboxMenu();
    SetJsonItems();
    m_webview.saucer::webview::execute("reloadContent()");
    isIndex = true;
}

void ToolboxWindow::toggleDevTools() {
    m_webview.set_dev_tools(!m_webview.dev_tools());
}

std::filesystem::path ToolboxWindow::getToolConfigPath(int id) const {
    if (id < 0 || id >= static_cast<int>(m_toolboxItems.size())) {
        return {};
    }
    return std::filesystem::path(m_toolboxItems[id].path) / "config.ini";
}

void ToolboxWindow::ensureConfigExists(int id) const {
    const auto configPath = getToolConfigPath(id);
    if (configPath.empty()) {
        return;
    }
    m_configStore.ensureExists(configPath);
}

int ToolboxWindow::getLuaTimeoutSecondsForId(int id) const {
    const auto configPath = getToolConfigPath(id);
    if (configPath.empty()) {
        return 30;
    }
    return m_configStore.getInt(configPath, "lua_timeout_seconds", 30);
}

int ToolboxWindow::getLuaTimeoutSeconds() {
    if (m_activeToolId < 0) {
        return 30;
    }
    return getLuaTimeoutSecondsForId(m_activeToolId);
}

void ToolboxWindow::setLuaTimeoutSeconds(int seconds) {
    if (m_activeToolId < 0) {
        return;
    }
    const auto configPath = getToolConfigPath(m_activeToolId);
    if (configPath.empty()) {
        return;
    }
    m_configStore.setInt(configPath, "lua_timeout_seconds", seconds);
}

std::string ToolboxWindow::getToolConfigIni() const {
    if (m_activeToolId < 0) {
        return {};
    }
    const auto configPath = getToolConfigPath(m_activeToolId);
    if (configPath.empty()) {
        return {};
    }
    return m_configStore.readAll(configPath);
}

void ToolboxWindow::setToolConfigIni(const std::string &content) {
    if (m_activeToolId < 0) {
        return;
    }
    const auto configPath = getToolConfigPath(m_activeToolId);
    if (configPath.empty()) {
        return;
    }
    m_configStore.writeAll(configPath, content);
}

std::string ToolboxWindow::getActiveToolName() {
    if (m_activeToolId < 0 || m_activeToolId >= static_cast<int>(m_toolboxItems.size())) {
        return {};
    }
    return m_toolboxItems[m_activeToolId].name;
}

