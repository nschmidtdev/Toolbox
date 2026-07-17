//
// Created by Yadciel on 04.12.2024.
//

#include "modules/hwnd_module.h"

HWND hwnd_module::require_hwnd() const
{
    if (m_parent == nullptr) {
        throw std::runtime_error("hwnd_module: parent webview is null");
    }
    // Ensure the native webview/controller is available
    auto natives = m_parent->native<>();
    if (!natives.webview || !natives.controller) {
        throw std::runtime_error("hwnd_module: native webview/controller is null");
    }
    HWND parent = nullptr;
    if (FAILED(natives.controller->get_ParentWindow(&parent)) || parent == nullptr) {
        throw std::runtime_error("hwnd_module: failed to retrieve HWND from WebView controller");
    }
    return parent;
}

void hwnd_module::set_topmost(bool enable) const
{
    const HWND hwnd = require_hwnd();
    SetWindowPos(hwnd, enable ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}

SIZE hwnd_module::get_size() const
{
    RECT r{};
    if (!GetWindowRect(require_hwnd(), &r)) {
        throw std::runtime_error("hwnd_module: GetWindowRect failed");
    }
    return SIZE{r.right - r.left, r.bottom - r.top};
}

POINT hwnd_module::get_position() const
{
    RECT r{};
    if (!GetWindowRect(require_hwnd(), &r)) {
        throw std::runtime_error("hwnd_module: GetWindowRect failed");
    }
    return POINT{r.left, r.top};
}

void hwnd_module::move_to(int x, int y) const
{
    const HWND hwnd = require_hwnd();
    RECT r{};
    if (!GetWindowRect(hwnd, &r)) {
        throw std::runtime_error("hwnd_module: GetWindowRect failed");
    }
    const int w = r.right - r.left;
    const int h = r.bottom - r.top;
    SetWindowPos(hwnd, nullptr, x, y, w, h, SWP_NOZORDER | SWP_NOACTIVATE);
}

void hwnd_module::resize_to(int width, int height) const
{
    const HWND hwnd = require_hwnd();
    RECT r{};
    if (!GetWindowRect(hwnd, &r)) {
        throw std::runtime_error("hwnd_module: GetWindowRect failed");
    }
    SetWindowPos(hwnd, nullptr, r.left, r.top, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
}

void hwnd_module::center_on_screen() const
{
    const HWND hwnd = require_hwnd();
    RECT r{};
    if (!GetWindowRect(hwnd, &r)) {
        throw std::runtime_error("hwnd_module: GetWindowRect failed");
    }
    const int w = r.right - r.left;
    const int h = r.bottom - r.top;
    const int screen_w = GetSystemMetrics(SM_CXSCREEN);
    const int screen_h = GetSystemMetrics(SM_CYSCREEN);
    const int x = (screen_w - w) / 2;
    const int y = (screen_h - h) / 2;
    SetWindowPos(hwnd, nullptr, x, y, w, h, SWP_NOZORDER | SWP_NOACTIVATE);
}
