#pragma once

#include <functional>
#include <string>

#include <saucer/smartview.hpp>

class ToolboxJsBridge {
public:
    struct Bindings {
        std::function<std::string()> getToolboxItems;
        std::function<std::string(const std::string&)> runLua;
        std::function<void(const std::string&)> cancelLua;
        std::function<void()> debugPrint;
        std::function<void()> openFileSystem;
        std::function<void()> openCommandPrompt;
        std::function<void()> openAddTool;
        std::function<void(const std::string&)> openSettings;
        std::function<std::string(const std::string&)> deleteTool;
        std::function<void(int)> setOpacity;
        std::function<int()> getOpacity;
        std::function<void()> openIndex;
        std::function<void()> getNewContent;
    };

    static void registerBindings(saucer::smartview& webview, const Bindings& bindings);
};
