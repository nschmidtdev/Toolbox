#include "ui/saucer/toolboxJsBridge.h"

#include "sol/types.hpp"

void ToolboxJsBridge::registerBindings(saucer::smartview& webview, const Bindings& bindings) {
    webview.expose("getToolboxItems", [bindings]() -> std::string {
        return bindings.getToolboxItems();
    });

    webview.expose("run_lua", [bindings](const std::string& toolPath) -> std::string {
        return bindings.runLua(toolPath);
    });

    webview.expose("cancel_lua", [bindings](const std::string& toolPath) {
        bindings.cancelLua(toolPath);
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

    webview.expose("openAddTool", [bindings]() {
        bindings.openAddTool();
    });

    webview.expose("openEinst", [bindings](const std::string& toolPath) {
        bindings.openSettings(toolPath);
    });

    webview.expose("deleteTool", [bindings](const std::string& toolPath) -> std::string {
        return bindings.deleteTool(toolPath);
    });

    webview.expose("setOpacity", [bindings](int percent) {
        bindings.setOpacity(percent);
    });

    webview.expose("getOpacity", [bindings]() -> int {
        return bindings.getOpacity();
    });

    webview.expose("openIndex", [bindings]() {
        bindings.openIndex();
    });

    webview.expose("getNewContent", [bindings]() {
        bindings.getNewContent();
    });
}
