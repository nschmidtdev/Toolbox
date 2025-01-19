//
// Created by schmidt on 04.12.2024.
//

#ifndef HWND_MODULE_H
#define HWND_MODULE_H


#include <execution>
#include <saucer/smartview.hpp>
#include <saucer/modules/stable/webview2.hpp> // Für Windows mit WebView2

class hwnd_module {
    saucer::webview *m_parent;

    public:
        explicit hwnd_module(saucer::webview *parent)
            : m_parent(parent) {}

        HWND get_hwnd() const
        {
            if (auto [window, webview] = m_parent->native<>(); !webview) {
                throw std::runtime_error("WebView instance is null.");
            }

            HWND parent = nullptr;
            if (FAILED(m_parent->native<>().controller->get_ParentWindow(&parent))) {
                throw std::runtime_error("Failed to retrieve HWND from WebView.");
            }

            return parent;
        }


};

static_assert(saucer::Module<hwnd_module, saucer::webview>);

#endif //HWND_MODULE_H
