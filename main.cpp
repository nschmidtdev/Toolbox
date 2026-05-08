#include <Windows.h>
#include <saucer/app.hpp>

#include <memory>

#include "toolboxWindow.h"
#include "trayController.h"

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

#ifdef _DEBUG
int main(int, char**) {
    return saucer::application::create({.id = "toolbox"})->run(start);
}
#else
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return saucer::application::create({.id = "toolbox"})->run(start);
}
#endif
