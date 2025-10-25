#include "toolboxWindow.h"
#include <iostream>
#include <stdexcept>
#include <windows.h>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <cppcodec/base64_rfc4648.hpp>
#include <saucer/embedded/all.hpp>
#include <format>

ToolboxWindow::ToolboxWindow(std::shared_ptr<saucer::application>& app)
    : m_webview([&]() -> saucer::smartview<> {
          auto window_res = saucer::window::create(app.get());
          if (!window_res.has_value()) {
              throw std::runtime_error("ToolboxWindow: failed to create saucer::window");
          }
          saucer::webview::options opts{window_res.value()};
          auto sv_res = saucer::smartview<>::create(opts);
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
    ensureToolboxInUserPath();
    fillToolboxMenu();
    configureWindow();
    loadResources();
    setupToolboxWindow();
}

void ToolboxWindow::setupToolboxWindow() {
    SetJsonItems();
    ExposeToJs();
    m_webview.parent().set_always_on_top(true);
    m_webview.parent().set_decorations(saucer::window::decoration::none);

#ifdef _DEBUG
    m_webview.set_dev_tools(true);
#endif

    startThreadMonitor();
}

void ToolboxWindow::startThreadMonitor() {
    m_threadMonitor = std::thread([&]() {
        monitor_focus();
    });
    m_threadMonitor.detach();
}

bool ToolboxWindow::serveHtmlFile(const std::string& htmlPath, bool setDecorations) {
    auto resources = saucer::embedded::all();

    const std::string key = (!htmlPath.empty() && htmlPath[0] != '/') ? "/" + htmlPath : htmlPath;

    if (!resources.contains(key)) {
        std::cerr << "Fehler: '" << key << "' wurde nicht gefunden!" << std::endl;
        return false;
    }

    m_webview.serve(key);
    m_webview.parent().set_decorations(setDecorations ? saucer::window::decoration::full : saucer::window::decoration::none);
    return true;
}

void ToolboxWindow::configureWindow() {
    // DPI-Awareness berücksichtigen
    SetProcessDPIAware(); // Macht die Anwendung DPI-bewusst

    // Aktuelle DPI-Einstellungen ermitteln
    HDC hdc = GetDC(NULL);
    int dpiX = GetDeviceCaps(hdc, LOGPIXELSX);
    int dpiY = GetDeviceCaps(hdc, LOGPIXELSY);
    ReleaseDC(NULL, hdc);

    // Skalierungsfaktor berechnen (96 DPI = 100% Skalierung)
    const double scaleX = static_cast<double>(dpiX) / 96.0;
    const double scaleY = static_cast<double>(dpiY) / 96.0;

    // Physische Bildschirmauflösung
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Logische Auflösung (was der Benutzer sieht)
    const int logicalScreenWidth = static_cast<int>(screenWidth / scaleX);
    const int logicalScreenHeight = static_cast<int>(screenHeight / scaleY);

    const int windowWidth = 350;
    const int windowHeight = 600;

    m_webview.parent().set_size({windowWidth, windowHeight});
    m_webview.set_force_dark(true);

    // Arbeitsbereich mit DPI-Skalierung berücksichtigen
    RECT workArea;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);

    // Arbeitsbereich in logische Koordinaten umrechnen
    const int logicalWorkWidth = static_cast<int>((workArea.right - workArea.left) / scaleX);
    const int logicalWorkHeight = static_cast<int>((workArea.bottom - workArea.top) / scaleY);

    const int rightMargin = 0;
    const int bottomMargin = 0;

    // Position in logischen Koordinaten berechnen
    int xPos = logicalWorkWidth - rightMargin - windowWidth;
    int yPos = logicalWorkHeight - bottomMargin - windowHeight;

    // Boundary checks
    if (xPos < 0) xPos = 10;
    if (yPos < 0) yPos = 10;

    // Zurück in physische Koordinaten für SetWindowPos
    const int physicalX = static_cast<int>(xPos * scaleX);
    const int physicalY = static_cast<int>(yPos * scaleY);

    moveWindowTo(physicalX, physicalY);
}

void ToolboxWindow::moveWindowTo(int x, int y) {
    if (const HWND hwnd = m_hwnd) {
        SetWindowPos(hwnd, nullptr, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void ToolboxWindow::loadResources() {
    auto resources = saucer::embedded::all();

    if (!resources.contains("/html/card.html")) {
        std::cerr << "Fehler: 'card.html' wurde nicht gefunden!" << std::endl;
        return;
    }

    if (const auto it = resources.find("/html/index.html"); it == resources.end()) {
        std::cerr << "Fehler: 'index.html' wurde nicht gefunden!" << std::endl;
        return;
    }
    m_webview.embed(resources);
    m_webview.serve("/html/index.html");
    //m_webview.set_url("https://nindo.de");
    m_webview.set_context_menu(false);

    if (!resources.contains("ico/toolbox.png")) {
        std::cerr << "Fehler: 'toolbox.png' wurde nicht gefunden!" << std::endl;
        return;
    }

    const saucer::icon window_icon = saucer::icon::from(resources.find("ico/toolbox.png")->second.content).value();
    m_webview.parent().set_icon(window_icon);
    m_webview.parent().set_title("Toolbox");
    saucer::webview::register_scheme("Toolbox");
}

void ToolboxWindow::runLuaScript() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hallo von Lua!')");
}

void ToolboxWindow::show() {
    m_webview.parent().show();
    m_bShow = true;

    // In some cases the HWND/frame metrics are finalized only after showing.
    // Re-acquire HWND and reposition now, plus schedule a short delayed reposition.
    if (m_hwnd_module) {
        if (HWND newHwnd = m_hwnd_module->get_hwnd(); newHwnd) {
            m_hwnd = newHwnd;
        }
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
    // Funktion, die JSON-Code an das JavaScript exponiert
    m_webview.expose("getToolboxItems", [&]() -> std::string {
        return jsonString;
    });

    m_webview.expose("run_lua", [&](int id) {
        run_lua(id);
    });

    m_webview.expose("debug_print", [&]() {
        debug_print();
    });

    m_webview.expose("open_file_system", [&]() {
        open_file_system();
    });

    m_webview.expose("openEinst", [&]() {
        openEinst();
    });

    m_webview.expose("openIndex", [&]() {
        openIndex();
    });

    m_webview.expose("getNewContent", [&]()
    {
        getNewContent();
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
    // Bestimme das Benutzerverzeichnis abhängig vom Betriebssystem
    std::filesystem::path userPath;

#ifdef _WIN32
    userPath = std::getenv("USERPROFILE");  // Windows
#else
    userPath = std::getenv("HOME");  // Unix/Linux/MacOS
#endif

    // Setze den Pfad zum .Toolbox-Verzeichnis

    // Überprüfe, ob der Pfad existiert
    if (const std::filesystem::path toolboxPath = userPath / ".Toolbox"; !std::filesystem::exists(toolboxPath)) {
        try {
            // Versuche, das Verzeichnis zu erstellen
            if (std::filesystem::create_directory(toolboxPath)) {
                std::cout << ".Toolbox Verzeichnis wurde erstellt." << std::endl;
                return true;
            } else {
                std::cerr << "Fehler beim Erstellen des .Toolbox Verzeichnisses." << std::endl;
                return false;
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Filesystem-Fehler: " << e.what() << std::endl;
            return false;
        }
    }

    std::cout << "Das Verzeichnis .Toolbox existiert bereits." << std::endl;
    return true;
}

void encodeImageToBase64(const std::filesystem::path& imagePath, ToolboxWindow::ToolboxItem& item) {
    std::ifstream file(imagePath, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Fehler beim Öffnen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    const std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> fileData(fileSize);
    if (!file.read(reinterpret_cast<char*>(fileData.data()), fileSize)) {
        std::cerr << "Fehler beim Lesen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    // Kodieren der Binärdaten mit cppcodec zu Base64
    const std::string base64Encoded = cppcodec::base64_rfc4648::encode(fileData);
    item.icon = "data:image/png;base64," + base64Encoded;
}

void ToolboxWindow::fillToolboxMenu() {
    m_toolboxItems.clear();
    std::filesystem::path toolboxDir = userPath / ".Toolbox";

    if (!std::filesystem::exists(toolboxDir) || !std::filesystem::is_directory(toolboxDir)) {
        std::cerr << "Fehler: Das Verzeichnis .Toolbox existiert nicht." << std::endl;
        return;
    }

    int id = 0;
    for (const auto& entry : std::filesystem::directory_iterator(toolboxDir)) {
        if (!entry.is_directory()) continue;

        ToolboxItem item;
        item.id = std::to_string(id++);
        item.name = entry.path().filename().string();
        item.path = entry.path().string();

        // Encode Image
        encodeImageToBase64(entry.path() / "icon.png", item);

        // Lese Beschreibung von description.txt
        std::filesystem::path descriptionFile = entry.path() / "description.txt";
        if (std::filesystem::exists(descriptionFile)) {
            std::ifstream descFile(descriptionFile);
            item.description.assign((std::istreambuf_iterator<char>(descFile)),
                                    std::istreambuf_iterator<char>());
        }

        // Lese Beschreibung von description.txt
        std::filesystem::path luaScript = entry.path() / "start.lua";
        if (std::filesystem::exists(luaScript)) {
            item.lua_script_path_string = luaScript.string();
        }

        m_toolboxItems.push_back(item);
    }
}

void ToolboxWindow::run_lua(int id) {

    /*// Öffnet ein CMD-Fenster, falls noch keins offen ist
    static bool console_opened = false;
    if (!console_opened) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout); // stdout auf die Konsole umleiten
        freopen("CONOUT$", "w", stderr); // stderr auf die Konsole umleiten
        console_opened = true;
    }*/

    // Lambda-Funktion, um das Lua-Skript auszuführen
    auto lua_task = [this, id]() {
        sol::state lua;
        lua.open_libraries(sol::lib::base,
                           sol::lib::os,
                           sol::lib::string,
                           sol::lib::coroutine,
                           sol::lib::package,
                           sol::lib::table,
                           sol::lib::math,
                           sol::lib::utf8,
                           sol::lib::io);

        try {
            std::string scriptPath = m_toolboxItems[id].lua_script_path_string;
            std::cout << "Running Lua script: " << scriptPath << std::endl;

            // Lua-Skript ausführen
            lua.script_file(scriptPath);

            // Nach erfolgreichem Ausführen UI aktualisieren
            m_webview.saucer::webview::execute(std::format("enableButtonByToolId({})", id));
            m_webview.reload();
        } catch (const sol::error& e) {
            // Lua-Fehler in der Konsole ausgeben
            std::cerr << "Lua error: " << e.what() << std::endl;

            // Nach Fehler UI aktualisieren
            m_webview.saucer::webview::execute(std::format("enableButtonByToolId({})", id));
            m_webview.reload();
        }
    };

    // Erstellen und starten des Threads
    std::thread lua_thread(lua_task);

    // Thread lösen, um die Anwendung nicht zu blockieren
    lua_thread.detach();

    std::cout << "Lua-Skript wurde gestartet." << std::endl;
}

void ToolboxWindow::debug_print() {
    std::cout << "ToolboxWindow::debug_print()" << std::endl;
}

ToolboxWindow::~ToolboxWindow() {
    m_runningMonitor = false;
}


void ToolboxWindow::monitor_focus() {
    while (m_runningMonitor) {
        if (m_bShow && !m_webview.parent().focused() && isIndex) {
            this->hide();
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


// Beispielhafte Nutzung:
void ToolboxWindow::openEinst() {
    if (!serveHtmlFile("html/einstellungen.html", true)) {
        return;
    }
    isIndex = false;
    resizeWindow(60.0, 70.0);
    centerWindow();
}

void ToolboxWindow::centerWindow() {
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Aktuelle Fenstergröße abrufen
    int windowWidth = 0;
    int windowHeight = 0;

    if (const HWND hwnd = m_hwnd) {
        RECT rect;
        if (GetWindowRect(hwnd, &rect)) {
            windowWidth = rect.right - rect.left;
            windowHeight = rect.bottom - rect.top;
        }
    }

    // Berechnung der zentralen Position
    const int xPos = (screenWidth - windowWidth) / 2;
    const int yPos = (screenHeight - windowHeight) / 2;

    // Bewege das Fenster an die zentrale Position
    moveWindowTo(xPos, yPos);
}

void ToolboxWindow::resizeWindow(int width, int height)
{
    // Stellen Sie die Größe des Fensters ein
    m_webview.parent().set_size({width, height});
}

void ToolboxWindow::resizeWindow(double widthPercent, double heightPercent)
{
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Berechnung der Fenstergröße basierend auf Prozentwerten
    const int width = static_cast<int>(screenWidth * (widthPercent / 100.0));
    const int height = static_cast<int>(screenHeight * (heightPercent / 100.0));

    // Stellen Sie die Größe des Fensters ein
    m_webview.parent().set_size({width, height});
}

void ToolboxWindow::openIndex() {
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

