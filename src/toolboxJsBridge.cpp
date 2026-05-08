#include "toolboxJsBridge.h"

void ToolboxJsBridge::registerBindings(saucer::smartview& webview, Bindings bindings) {
    webview.expose("getToolboxItems", [bindings]() -> std::string {
        return bindings.getToolboxItems();
    });

    webview.expose("run_lua", [bindings](int id) {
        bindings.runLua(id);
    });

    webview.expose("cancel_lua", [bindings](int id) {
        bindings.cancelLua(id);
    });

    webview.expose("debug_print", [bindings]() {
        bindings.debugPrint();
    });

    webview.expose("open_file_system", [bindings]() {
        bindings.openFileSystem();
    });

    webview.expose("open_cmd", [bindings]() {
        bindings.openCommandPrompt();
    });

    webview.expose("openEinst", [bindings](int id) {
        bindings.openSettings(id);
    });

    webview.expose("openIndex", [bindings]() {
        bindings.openIndex();
    });

    webview.expose("getNewContent", [bindings]() {
        bindings.getNewContent();
    });

    webview.expose("getLuaTimeoutSeconds", [bindings]() -> int {
        return bindings.getLuaTimeoutSeconds();
    });

    webview.expose("setLuaTimeoutSeconds", [bindings](int seconds) {
        bindings.setLuaTimeoutSeconds(seconds);
    });

    webview.expose("getActiveToolName", [bindings]() -> std::string {
        return bindings.getActiveToolName();
    });

    webview.expose("getToolConfigIni", [bindings]() -> std::string {
        return bindings.getToolConfigIni();
    });

    webview.expose("setToolConfigIni", [bindings](const std::string& content) {
        bindings.setToolConfigIni(content);
    });
}
