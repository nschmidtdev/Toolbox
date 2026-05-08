#include "windowPlacement.h"

namespace {

constexpr int toolboxWidth = 420;
constexpr int toolboxHeight = 720;
constexpr int fallbackPosition = 10;

struct DpiScale {
    double x = 1.0;
    double y = 1.0;
};

DpiScale currentDpiScale() {
    HDC hdc = GetDC(nullptr);
    const int dpiX = GetDeviceCaps(hdc, LOGPIXELSX);
    const int dpiY = GetDeviceCaps(hdc, LOGPIXELSY);
    ReleaseDC(nullptr, hdc);

    return {
        static_cast<double>(dpiX) / 96.0,
        static_cast<double>(dpiY) / 96.0
    };
}

} // namespace

void WindowPlacement::configureToolbox(saucer::smartview& webview, HWND hwnd) {
    SetProcessDPIAware();

    const DpiScale scale = currentDpiScale();
    webview.parent().set_size({toolboxWidth, toolboxHeight});

    const saucer::color bg{0x0b, 0x1c, 0x2c, 0x00};
    webview.set_background(bg);
    webview.parent().set_background(bg);

    RECT workArea;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);

    const int logicalWorkWidth = static_cast<int>((workArea.right - workArea.left) / scale.x);
    const int logicalWorkHeight = static_cast<int>((workArea.bottom - workArea.top) / scale.y);

    int xPos = logicalWorkWidth - toolboxWidth;
    int yPos = logicalWorkHeight - toolboxHeight;

    if (xPos < 0) {
        xPos = fallbackPosition;
    }
    if (yPos < 0) {
        yPos = fallbackPosition;
    }

    moveTo(hwnd, static_cast<int>(xPos * scale.x), static_cast<int>(yPos * scale.y));
}

void WindowPlacement::moveTo(HWND hwnd, int x, int y) {
    if (hwnd) {
        SetWindowPos(hwnd, nullptr, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
    }
}

void WindowPlacement::center(HWND hwnd) {
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowWidth = 0;
    int windowHeight = 0;

    if (hwnd) {
        RECT rect;
        if (GetWindowRect(hwnd, &rect)) {
            windowWidth = rect.right - rect.left;
            windowHeight = rect.bottom - rect.top;
        }
    }

    moveTo(hwnd, (screenWidth - windowWidth) / 2, (screenHeight - windowHeight) / 2);
}

void WindowPlacement::resize(saucer::smartview& webview, int width, int height) {
    webview.parent().set_size({width, height});
}

void WindowPlacement::resizePercent(saucer::smartview& webview, double widthPercent, double heightPercent) {
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    resize(webview,
           static_cast<int>(screenWidth * (widthPercent / 100.0)),
           static_cast<int>(screenHeight * (heightPercent / 100.0)));
}
