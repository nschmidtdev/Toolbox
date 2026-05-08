#pragma once

#include <memory>

class ToolboxWindow;

class TrayController {
public:
    explicit TrayController(ToolboxWindow& window);
    ~TrayController();

    TrayController(const TrayController&) = delete;
    TrayController& operator=(const TrayController&) = delete;

    bool initialize();
    void shutdown();

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
