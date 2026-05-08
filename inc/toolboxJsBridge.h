#pragma once

#include <functional>
#include <string>

#include <saucer/smartview.hpp>

class ToolboxJsBridge {
public:
    struct Bindings {
        std::function<std::string()> getToolboxItems;
        std::function<void(int)> runLua;
        std::function<void(int)> cancelLua;
        std::function<void()> debugPrint;
        std::function<void()> openFileSystem;
        std::function<void()> openCommandPrompt;
        std::function<void(int)> openSettings;
        std::function<void()> openIndex;
        std::function<void()> getNewContent;
        std::function<int()> getLuaTimeoutSeconds;
        std::function<void(int)> setLuaTimeoutSeconds;
        std::function<std::string()> getActiveToolName;
        std::function<std::string()> getToolConfigIni;
        std::function<void(const std::string&)> setToolConfigIni;
    };

    static void registerBindings(saucer::smartview& webview, Bindings bindings);
};
