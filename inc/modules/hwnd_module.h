//
// Created by Yadciel on 04.12.2024.
//

#ifndef HWND_MODULE_H
#define HWND_MODULE_H

#include <stdexcept>
#include <utility>
#include <windows.h>

#include <saucer/webview.hpp>
#include <saucer/modules/stable/webview2.hpp> // Für Windows mit WebView2

// A lightweight Saucer module providing Win32 window (HWND) utilities for a given webview
class hwnd_module {
    saucer::webview *m_parent;

    HWND require_hwnd() const;

public:
    explicit hwnd_module(saucer::webview *parent) : m_parent(parent) {}

    // Retrieve the native HWND handle
    HWND get_hwnd() const { return require_hwnd(); }

    // Visibility and state
    void show() const { ShowWindow(require_hwnd(), SW_SHOW); }
    void hide() const { ShowWindow(require_hwnd(), SW_HIDE); }
    bool is_visible() const { return IsWindowVisible(require_hwnd()) != 0; }

    void minimize() const { ShowWindow(require_hwnd(), SW_MINIMIZE); }
    void maximize() const { ShowWindow(require_hwnd(), SW_MAXIMIZE); }
    void restore() const { ShowWindow(require_hwnd(), SW_RESTORE); }
    bool is_minimized() const { return IsIconic(require_hwnd()) != 0; }
    bool is_maximized() const { return IsZoomed(require_hwnd()) != 0; }

    // Z-Order
    void set_topmost(bool enable) const;

    // Geometry
    SIZE get_size() const;

    POINT get_position() const;

    void move_to(int x, int y) const;

    void resize_to(int width, int height) const;

    void center_on_screen() const;

    // Close the native window
    void close() const { PostMessageW(require_hwnd(), WM_CLOSE, 0, 0); }
};

#endif // HWND_MODULE_H
