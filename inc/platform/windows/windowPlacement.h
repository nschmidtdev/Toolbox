#pragma once

#include <Windows.h>

#include <saucer/smartview.hpp>

class WindowPlacement {
public:
    static void configureToolbox(saucer::smartview& webview, HWND hwnd);
    static void moveTo(HWND hwnd, int x, int y);
    static void center(HWND hwnd);
    static void resize(saucer::smartview& webview, int width, int height);
    static void resizePercent(saucer::smartview& webview, double widthPercent, double heightPercent);
};
