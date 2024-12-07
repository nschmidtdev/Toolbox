#include "toolboxWindow.h"
#include "optionWindow.h"
#include <iostream>
#include <windows.h>
#include <nlohmann/json.hpp>
#include <cppcodec/base64_rfc4648.hpp>

ToolboxWindow::ToolboxWindow(std::shared_ptr<saucer::application>& app)
        : m_app(app), m_webview({.application = app}) {}

void ToolboxWindow::initialize() {
    ensureToolboxInUserPath();
    fillToolboxMenu();
    configureWindow();
    loadResources();
    ExposeToJs();
    m_webview.set_dev_tools(true);
    //m_webview.set_decorations(false);
    //m_webview.set_always_on_top(true);

    m_threadMonitor = std::thread([&]() {
        monitor_focus();
    });

    m_threadMonitor.detach();
}

void ToolboxWindow::configureWindow() {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowWidth = static_cast<int>(screenWidth * (500.0 / 1920.0));
    int windowHeight = static_cast<int>(screenHeight * (700.0 / 1080.0));

    m_webview.set_size(windowWidth, windowHeight);
    m_webview.set_force_dark_mode(true);

    int xPos = screenWidth - windowWidth;
    int yPos = screenHeight - 42 - windowHeight;

    if (HWND hwnd = m_webview.module<hwnd_module>().get_hwnd()) {
        SetWindowPos(hwnd, nullptr, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void ToolboxWindow::loadResources() {
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

void ToolboxWindow::runLuaScript() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Hallo von Lua!')");
}

void ToolboxWindow::show() {
    m_webview.show();
    m_bShow = true;
}

void ToolboxWindow::hide() {
    m_webview.hide();
    m_bShow = false;
}

void ToolboxWindow::ExposeToJs() {
    // Konvertierung des Vektors in JSON
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

    // Konvertiere den JSON-Array in einen String
    std::string jsonString = jsonArray.dump();

    // Funktion, die JSON-Code an das JavaScript exponiert
    m_webview.expose("getToolboxItems", [jsonString]() -> std::string {
        return jsonString;
    }, saucer::launch::async);

    m_webview.expose("run_lua", [&](int id) {
        run_lua(id);
    }, saucer::launch::async);

    m_webview.expose("debug_print", [&]() {
        debug_print();
    }, saucer::launch::async);
}

void ToolboxWindow::OptionWindow() {
    std::cout << "OptionWindow" << std::endl;

    // Starte einen neuen Thread
    std::thread optionThread([this]() {

    });

    // Thread im Hintergrund ausführen lassen
    optionThread.detach();
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
    std::filesystem::path toolboxPath = userPath / ".Toolbox";

    // Überprüfe, ob der Pfad existiert
    if (!std::filesystem::exists(toolboxPath)) {
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

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<unsigned char> fileData(fileSize);
    if (!file.read(reinterpret_cast<char*>(fileData.data()), fileSize)) {
        std::cerr << "Fehler beim Lesen des PNG-Bildes: " << imagePath << std::endl;
        return;
    }

    // Kodieren der Binärdaten mit cppcodec zu Base64
    std::string base64Encoded = cppcodec::base64_rfc4648::encode(fileData);
    item.icon = "data:image/png;base64," + base64Encoded;
}

void ToolboxWindow::fillToolboxMenu() {
    // Bestimme das Benutzerverzeichnis abhängig vom Betriebssystem
    std::filesystem::path userPath;

#ifdef _WIN32
    userPath = std::getenv("USERPROFILE");  // Windows
#else
    userPath = std::getenv("HOME");  // Unix/Linux/MacOS
#endif

    std::filesystem::path toolboxDir = userPath / ".Toolbox";

    if (std::filesystem::exists(toolboxDir) && std::filesystem::is_directory(toolboxDir)) {
        int id = 0;
        for (const auto& entry : std::filesystem::directory_iterator(toolboxDir)) {
            if (entry.is_directory()) {
                ToolboxItem item;
                item.id = std::to_string(id);
                item.name = entry.path().filename().string();
                item.path = entry.path().string();

                // Verwenden Sie lodepng und cppcodec, um PNG-Bilder zu Base64 zu kodieren
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
                    item.lua_script = luaScript.string();
                }

                m_toolboxItems.push_back(item);
            }
            id++;
        }
    } else {
        std::cerr << "Fehler: Das Verzeichnis .Toolbox existiert nicht." << std::endl;
    }
}

void ToolboxWindow::run_lua(int id) {

    // Lambda-Funktion, um das Lua-Skript auszuführen
    auto lua_task = [this, id]() {
        sol::state lua;
        lua.open_libraries(sol::lib::base, sol::lib::os);

        try {
            std::string scriptPath = m_toolboxItems[id].lua_script;
            lua.script_file(scriptPath);
            m_webview.execute("enableButtonByToolId({})",saucer::make_args(id));
            m_webview.reload();
        } catch (const sol::error& e) {
            std::cerr << "Lua error: " << e.what() << std::endl;
        }
    };

    // Erstellen und starten des Threads
    std::thread lua_thread(lua_task);

    // Optional: Warten auf den Abschluss des Threads
    lua_thread.detach(); // Falls Sie den Thread nicht blockieren wollen

    std::cout << "Lua-Skript wurde gestartet." << std::endl;
}

void ToolboxWindow::debug_print() {
    std::cout << "ToolboxWindow::debug_print()" << std::endl;
}

ToolboxWindow::~ToolboxWindow() {
    m_runningMonitor = false;
}

void ToolboxWindow::monitor_focus() {
    while(m_runningMonitor){
        if(m_bShow && !m_webview.focused()) {
            this->hide();
        }
    }
}
