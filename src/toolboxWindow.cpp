







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
#include <array>
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

std::filesystem::path ToolboxWindow::userDirectory() {
#ifdef _WIN32
    const DWORD required = GetEnvironmentVariableW(L"USERPROFILE", nullptr, 0);
    if (required > 1) {
        std::wstring directory(required, L'\0');
        const DWORD written = GetEnvironmentVariableW(L"USERPROFILE", directory.data(), required);
        if (written > 0 && written < required) {
            directory.resize(written);
            return std::filesystem::path(directory);
        }
    }
    return std::filesystem::current_path();
#else
    const char* directory = std::getenv("HOME");
    return directory ? std::filesystem::path(directory) : std::filesystem::current_path();
#endif
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
    m_isVisible.store(true, std::memory_order_release);
    m_lastShowTime = std::chrono::steady_clock::now();
    m_seenFocusSinceShow.store(false, std::memory_order_release);

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
    scheduleDelayedReposition();
}

void ToolboxWindow::scheduleDelayedReposition() {
    if (m_repositionThread.joinable()) {
        m_repositionThread.request_stop();
        m_repositionThread.join();
    }

    m_repositionThread = std::jthread([this](std::stop_token stopToken) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (!stopToken.stop_requested()) {
            configureWindow();
        }
    });
}

void ToolboxWindow::hide() {
    m_webview.parent().hide();
    m_isVisible.store(false, std::memory_order_release);
}

bool ToolboxWindow::isVisible() const noexcept {
    return m_isVisible.load(std::memory_order_acquire);
}

void ToolboxWindow::ExposeToJs() {
    ToolboxJsBridge::registerBindings(m_webview, {
        .getToolboxItems = [this]() {
            SetJsonItems();
            return jsonString;
        },
        .runLua = [this](const std::string& toolPath) { return run_lua_path(toolPath); },
        .cancelLua = [this](const std::string& toolPath) { cancel_lua(toolPath); },
        .debugPrint = [this]() { debug_print(); },
        .openFileSystem = [this]() { open_file_system(); },
        .openCommandPrompt = [this]() { open_cmd(); },
        .openAddTool = [this]() { openAddTool(); },
        .openSettings = [this](const std::string& toolPath) { openEinst(toolPath); },
        .deleteTool = [this](const std::string& toolPath) { return deleteTool(toolPath); },
        .setOpacity = [this](int percent) { setWindowOpacity(percent); },
        .getOpacity = [this]() { return getWindowOpacity(); },
        .openIndex = [this]() { openIndex(); },
        .getNewContent = [this]() { getNewContent(); },

    });
}

void ToolboxWindow::SetJsonItems() {// Konvertierung des Vektors in JSON
    nlohmann::json jsonArray = nlohmann::json::array();

    for (const auto& item : m_toolboxItems) {
        LuaRunner::TaskStatus taskStatus;
        try {
            taskStatus = m_luaRunner.status(
                item.path, std::filesystem::u8path(item.lua_script_path_string));
        } catch (const std::exception&) {
            taskStatus = {};
        }
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
                {"license", item.license},
                {"singleInstance", taskStatus.singleInstance},
                {"running", taskStatus.singleInstance && taskStatus.running}
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

LuaRunner::RunResult ToolboxWindow::run_lua(int id) {
    if (id < 0 || id >= static_cast<int>(m_toolboxItems.size())) {
        return {};
    }

    const std::filesystem::path scriptPath = std::filesystem::u8path(m_toolboxItems[id].lua_script_path_string);
    const std::string toolPath = m_toolboxItems[id].path;
    auto app = m_app;
    auto alive = m_alive;
    return m_luaRunner.run(toolPath, scriptPath, getLuaTimeoutSecondsForId(id),
                           [this, app = std::move(app), alive = std::move(alive)](bool) {
        app->post([this, alive] {
            if (!alive->load(std::memory_order_acquire)) {
                return;
            }
            m_webview.saucer::webview::execute("reloadContent()");
        });
    });
}

std::string ToolboxWindow::run_lua_path(const std::string& toolPath) {
    const auto item = std::ranges::find(m_toolboxItems, toolPath, &ToolboxItem::path);
    if (item == m_toolboxItems.end() ||
        !ToolRegistry::getToolDetails(userDirectory(), std::filesystem::u8path(toolPath)).success) {
        return nlohmann::json({
            {"started", false}, {"singleInstance", false}, {"message", "Tool nicht gefunden."}
        }).dump();
    }
    try {
        const auto result = run_lua(static_cast<int>(std::distance(m_toolboxItems.begin(), item)));
        return nlohmann::json({
            {"started", result.started},
            {"singleInstance", result.singleInstance},
            {"message", result.started ? "Tool gestartet." : "Tool laeuft bereits."}
        }).dump();
    } catch (const std::exception& error) {
        return nlohmann::json({
            {"started", false}, {"singleInstance", false}, {"message", error.what()}
        }).dump();
    }
}

void ToolboxWindow::cancel_lua(const std::string& toolPath) {
    m_luaRunner.cancel(toolPath);
}
void ToolboxWindow::debug_print() {
    std::cout << "ToolboxWindow::debug_print()" << std::endl;
}

ToolboxWindow::~ToolboxWindow() {
    m_alive->store(false, std::memory_order_release);
    if (m_repositionThread.joinable()) {
        m_repositionThread.request_stop();
        m_repositionThread.join();
    }
    m_luaRunner.shutdown();
    m_runningMonitor = false;
    if (m_threadMonitor.joinable()) {
        m_threadMonitor.join();
    }
}


void ToolboxWindow::monitor_focus() {
    while (m_runningMonitor) {
        if (m_isVisible.load(std::memory_order_acquire) &&
            m_isIndex.load(std::memory_order_acquire)) {
            const bool focused = m_webview.parent().focused();
            if (focused) {
                m_seenFocusSinceShow.store(true, std::memory_order_release);
            } else if (m_seenFocusSinceShow.load(std::memory_order_acquire)) {
                this->hide();
            }
        }

        // Schlafpause hinzufügen, um die CPU-Last zu reduzieren
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void ToolboxWindow::open_file_system() {
    if (const std::filesystem::path toolboxDir = userPath / ".Toolbox";
        std::filesystem::exists(toolboxDir) && ToolRegistry::ensureToolboxDirectory(userPath)) {
#ifdef _WIN32
        const auto result = reinterpret_cast<std::intptr_t>(
            ShellExecuteW(nullptr, L"open", toolboxDir.c_str(), nullptr, nullptr, SW_SHOWNORMAL));
        if (result <= 32) {
            std::cerr << "Fehler beim Oeffnen des Verzeichnisses: " << result << std::endl;
        }
#elif __APPLE__
        const std::string command = "open \"" + toolboxDir.string() + "\"";
        if (const int result = std::system(command.c_str()); result != 0) {
            std::cerr << "Fehler beim Öffnen des Verzeichnisses: " << result << std::endl;
        }
#elif __linux__
        const std::string command = "xdg-open \"" + toolboxDir.string() + "\"";
        if (const int result = std::system(command.c_str()); result != 0) {
            std::cerr << "Fehler beim Öffnen des Verzeichnisses: " << result << std::endl;
        }
#else
        std::cerr << "Fehler: Plattform nicht unterstützt." << std::endl;
        return;
#endif
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

void ToolboxWindow::setWindowOpacity(int percent) {
    if (percent < 70) percent = 70;
    if (percent > 100) percent = 100;
    m_lastOpacity = percent;
    const double opacity = percent / 100.0;
    m_webview.saucer::webview::execute(
        "document.getElementById('shell').style.opacity = " + std::to_string(opacity));
}

int ToolboxWindow::getWindowOpacity() const {
    return m_lastOpacity;
}


optionWindow& ToolboxWindow::optionWindowInstance() {
    if (!m_optionWindow) {
        m_optionWindow = std::make_unique<optionWindow>(
            m_app,
            [this]() { return getActiveToolDetails(); },
            [this](const std::string& payload) { return saveActiveToolDetails(payload); },
            [this]() { return openActiveToolFolder(); },
            [this](const std::string &payload) { return createTool(payload); },
            [this]() { openLuaHelp(); },
            [this]() { openIndex(); }
        );
        m_optionWindow->initialize();
    }
    return *m_optionWindow;
}

void ToolboxWindow::openEinst() {
    optionWindowInstance().show();
}

void ToolboxWindow::openEinst(const std::string& toolPath) {
    const auto candidate = std::filesystem::u8path(toolPath);
    if (!ToolRegistry::getToolDetails(userDirectory(), candidate).success) {
        std::cerr << "openEinst: invalid tool path" << std::endl;
        return;
    }
    m_activeToolPath = candidate;
    openEinst();
}

void ToolboxWindow::openAddTool() {
    optionWindowInstance().showCreateTool();
}

LuaHelpWindow& ToolboxWindow::luaHelpWindowInstance() {
    if (!m_luaHelpWindow) {
        m_luaHelpWindow = std::make_unique<LuaHelpWindow>(m_app);
        m_luaHelpWindow->initialize();
    }
    return *m_luaHelpWindow;
}

void ToolboxWindow::openLuaHelp() {
    luaHelpWindowInstance().show();
}

std::string ToolboxWindow::createTool(const std::string& payload) {
    nlohmann::json response;
    try {
        const auto input = nlohmann::json::parse(payload);
        ToolDraft draft{
            .name = input.value("name", ""),
            .description = input.value("description", ""),
            .luaScript = input.value("luaScript", ""),
            .iconBase64 = input.value("iconBase64", ""),
            .timeoutSeconds = input.value("timeoutSeconds", 30),
            .templateType = input.value("templateType", "lua"),
            .templateTarget = input.value("templateTarget", ""),
        };
        const ToolCreationResult result = ToolRegistry::createTool(userPath, draft);
        response = {{"success", result.success}, {"message", result.message}};
        if (result.success) {
            fillToolboxMenu();
            SetJsonItems();
        }
    } catch (const std::exception&) {
        response = {{"success", false}, {"message", "Die Tool-Daten sind ungueltig."}};
    }
    return response.dump();
}

std::string ToolboxWindow::deleteTool(const std::string& toolPath) {
    nlohmann::json response;
    try {
        const auto path = std::filesystem::u8path(toolPath);
        const ToolDeletionResult result = ToolRegistry::deleteTool(userPath, path);
        response = {{"success", result.success}, {"message", result.message}};
        if (result.success) {
            fillToolboxMenu();
            SetJsonItems();
        }
    } catch (const std::exception&) {
        response = {{"success", false}, {"message", "Das Tool konnte nicht geloescht werden."}};
    }
    return response.dump();
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
    if (!m_isVisible.load(std::memory_order_acquire)) {
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
    m_isIndex.store(true, std::memory_order_release);
}

void ToolboxWindow::toggleDevTools() {
    m_webview.set_dev_tools(!m_webview.dev_tools());
}

std::filesystem::path ToolboxWindow::getToolConfigPath(int id) const {
    if (id < 0 || id >= static_cast<int>(m_toolboxItems.size())) {
        return {};
    }
    return std::filesystem::u8path(m_toolboxItems[id].path) / "config.ini";
}

int ToolboxWindow::getLuaTimeoutSecondsForId(int id) const {
    const auto configPath = getToolConfigPath(id);
    if (configPath.empty()) {
        return 30;
    }
    return m_configStore.getInt(configPath, "lua_timeout_seconds", 30);
}

std::string ToolboxWindow::getActiveToolDetails() const {
    const auto result = ToolRegistry::getToolDetails(userDirectory(), m_activeToolPath);
    nlohmann::json response{{"success", result.success}, {"message", result.message}};
    if (result.success) {
        response["details"] = {
            {"name", result.details.name},
            {"description", result.details.description},
            {"luaScript", result.details.luaScript},
            {"iconBase64", result.details.iconBase64},
            {"timeoutSeconds", result.details.timeoutSeconds},
            {"templateType", result.details.templateType},
            {"templateTarget", result.details.templateTarget},
        };
    }
    return response.dump();
}

std::string ToolboxWindow::saveActiveToolDetails(const std::string& payload) {
    nlohmann::json response;
    try {
        const auto input = nlohmann::json::parse(payload);
        const std::array<std::string_view, 5> stringFields = {
            "name", "description", "luaScript", "templateType", "templateTarget"
        };
        if (!input.is_object() ||
            std::ranges::any_of(stringFields, [&input](std::string_view field) {
                return !input.contains(field) || !input.at(field).is_string();
            }) || !input.contains("timeoutSeconds") || !input.at("timeoutSeconds").is_number_integer() ||
            (input.contains("iconBase64") && !input.at("iconBase64").is_string())) {
            return nlohmann::json({
                {"success", false},
                {"message", "Die Tool-Daten haben ein ungueltiges Format."}
            }).dump();
        }
        std::optional<std::string> iconBase64;
        if (input.contains("iconBase64")) {
            iconBase64 = input.value("iconBase64", "");
        }
        const ToolUpdateResult result = ToolRegistry::updateTool(userDirectory(), m_activeToolPath, ToolUpdateDraft{
            .name = input.value("name", ""),
            .description = input.value("description", ""),
            .luaScript = input.value("luaScript", ""),
            .iconBase64 = std::move(iconBase64),
            .timeoutSeconds = input.value("timeoutSeconds", 30),
            .templateType = input.value("templateType", "lua"),
            .templateTarget = input.value("templateTarget", ""),
        });
        response = {{"success", result.success}, {"message", result.message}};
        if (result.success) {
            m_activeToolPath = result.toolPath;
            fillToolboxMenu();
            SetJsonItems();
        }
    } catch (const std::exception&) {
        response = {{"success", false}, {"message", "Die Tool-Daten sind ungueltig."}};
    }
    return response.dump();
}

std::string ToolboxWindow::openActiveToolFolder() const {
    if (!ToolRegistry::getToolDetails(userDirectory(), m_activeToolPath).success) {
        return nlohmann::json({{"success", false}, {"message", "Der Toolordner wurde nicht gefunden."}}).dump();
    }
#ifdef _WIN32
    const auto result = reinterpret_cast<std::intptr_t>(
        ShellExecuteW(nullptr, L"open", m_activeToolPath.c_str(), nullptr, nullptr, SW_SHOWNORMAL));
    if (result <= 32) {
        return nlohmann::json({{"success", false}, {"message", "Der Toolordner konnte nicht geoeffnet werden."}}).dump();
    }
#endif
    return nlohmann::json({{"success", true}, {"message", "Toolordner wurde geoeffnet."}}).dump();
}

