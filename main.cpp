#include <Windows.h>
#include <saucer/app.hpp>

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "toolboxCli.h"
#include "toolboxWindow.h"
#include "trayController.h"

std::string wideToUtf8(std::wstring_view value) {
    if (value.empty()) {
        return {};
    }
    const int length = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(),
                                           static_cast<int>(value.size()), nullptr, 0, nullptr, nullptr);
    if (length <= 0) {
        return {};
    }
    std::string result(static_cast<std::size_t>(length), '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, value.data(),
                        static_cast<int>(value.size()), result.data(), length, nullptr, nullptr);
    return result;
}

bool isCliRequest(const std::vector<std::string>& args) {
    if (args.empty()) {
        return false;
    }
    const std::string& first = args.front();
    return first == "-h" || first == "--help" || first == "help" ||
           first == "list" || first == "create" || first == "run" ||
           first == "--home" || first == "--color";
}

coco::stray start(saucer::application* app) {
    std::shared_ptr<saucer::application> appShared(app, [](saucer::application*) {});

    auto window = std::make_unique<ToolboxWindow>(appShared);
    window->initialize();

    TrayController tray(*window);
    if (!tray.initialize()) {
        co_return;
    }

    co_await app->finish();
}

int wmain(int argc, wchar_t** argv) {
    std::vector<std::string> args;
    args.reserve(static_cast<std::size_t>(std::max(0, argc - 1)));
    for (int i = 1; i < argc; ++i) {
        args.push_back(wideToUtf8(argv[i]));
    }
    if (isCliRequest(args)) {
        return runCli(std::move(args));
    }
    // GUI mode: hide the console window that a console-subsystem binary gets.
    if (HWND console = GetConsoleWindow(); console != nullptr) {
        ShowWindow(console, SW_HIDE);
    }
    return saucer::application::create({.id = "toolbox"})->run(start);
}
