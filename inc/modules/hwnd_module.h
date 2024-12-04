//
// Created by schmidt on 04.12.2024.
//

#ifndef HWND_MODULE_H
#define HWND_MODULE_H



#include <saucer/modules/native/webview2.hpp> // Für Windows mit WebView2

class hwnd_module {
    saucer::natives m_natives;
    saucer::smartview_core *m_smartview;

public:
    hwnd_module(saucer::smartview_core *smartview, saucer::natives natives)
        : m_natives(natives), m_smartview(smartview) {}

    HWND get_hwnd() {
        auto [window, webview] = m_natives;
        return window->hwnd.get();
    }
};

static_assert(saucer::Module<hwnd_module>);



#endif //HWND_MODULE_H
