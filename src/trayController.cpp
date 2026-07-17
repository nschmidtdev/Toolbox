#include "trayController.h"

#include <Windows.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <cstdio>
#include <mutex>
#include <thread>

#include "resource.h"
#include "toolboxWindow.h"
#include "toolbox_win/icon_utils.h"
#include "tray.h"

import toolboxTray;

namespace {

constexpr DWORD minExplorerRestartDelayMs = 500;
constexpr int maxTrayReinitAttempts = 5;
constexpr int maxRetryDelayMs = 5000;

struct TrayState {
    bool reinitScheduled = false;
    int reinitAttempts = 0;
    DWORD lastExplorerRestartTime = 0;
};

void onQuit(tray_menu*) {
    tray_exit();
}

void openCommandPrompt(tray_menu*) {
    ShellExecuteW(nullptr, L"open", L"cmd.exe", nullptr, nullptr, SW_SHOWNORMAL);
}

bool isExplorerReady() {
    const HWND taskbar = FindWindowW(L"Shell_TrayWnd", nullptr);
    return taskbar && IsWindow(taskbar) && IsWindowVisible(taskbar) && GetDesktopWindow();
}

bool isTaskbarWindow(HWND hwnd) {
    const HWND taskbar = FindWindowW(L"Shell_TrayWnd", nullptr);
    return taskbar && hwnd == taskbar;
}

int retryDelayMs(int attempt) {
    const int delay = 200 * (1 << std::max(0, attempt - 1));
    return std::min(delay, maxRetryDelayMs);
}

} // namespace

struct TrayController::Impl {
    explicit Impl(ToolboxWindow& toolboxWindow)
        : window(toolboxWindow),
          menuItems{{
              {"CMD", 0, 0, 0, openCommandPrompt, nullptr},
              {"-", 0, 0, 0, nullptr, nullptr},
              {"Oeffnen", 0, 0, 0, &Impl::toggleToolboxWindow, nullptr},
              {"-", 0, 0, 0, nullptr, nullptr},
              {"Beenden", 0, 0, 0, onQuit, nullptr},
              {nullptr, 0, 0, 0, nullptr, nullptr},
          }} {}

    bool initialize() {
        {
            std::lock_guard<std::mutex> lock(activeControllerMutex);
            activeController = this;
        }

        const HICON icon = toolbox_load_small_icon(GetModuleHandleW(nullptr), IDI_ICON1);
        trayIcon = std::make_unique<toolboxTray>("toolbox.ico", "Toolbox");
        trayIcon->icon_handle = icon;
        trayIcon->icon_is_shared = icon ? 1 : 0;
        trayIcon->setLeftClickAction([] { toggleToolboxWindow(nullptr); });
        trayIcon->setTrayMenu(menuItems.data());

        if (tray_init(trayIcon.get()) != 0) {
            std::fprintf(stderr, "Fehler beim Initialisieren des Tray-Icons\n");
            return false;
        }

        installExplorerHook();
        return true;
    }

    void shutdown() {
        stopping.store(true);
        uninstallExplorerHook();

        {
            std::lock_guard<std::mutex> activeLock(activeControllerMutex);
            if (activeController == this) {
                activeController = nullptr;
            }
        }

        if (retryThread.joinable()) {
            retryThread.request_stop();
            retryThread.join();
        }

        std::lock_guard<std::mutex> trayLock(trayMutex);
        trayIcon.reset();
    }

    static void toggleToolboxWindow(tray_menu*) {
        std::lock_guard<std::mutex> lock(activeControllerMutex);
        if (!activeController || activeController->stopping.load()) {
            return;
        }

        ToolboxWindow& window = activeController->window;
        if (window.isVisible()) {
            window.hide();
            return;
        }

        window.show();
    }

    bool reinitTray() {
        std::lock_guard<std::mutex> lock(trayMutex);
        if (stopping.load()) {
            return false;
        }
        if (!trayIcon || state.reinitScheduled) {
            return false;
        }

        ++state.reinitAttempts;
        if (state.reinitAttempts > maxTrayReinitAttempts) {
            std::fprintf(stderr, "Maximale Anzahl an Reinitialisierungsversuchen erreicht\n");
            return false;
        }

        state.reinitScheduled = true;
        int result = tray_init(trayIcon.get());

        if (result != 0) {
            std::fprintf(stderr, "Fehler beim Re-Initialisieren des Tray-Icons (Versuch %d/%d)\n",
                         state.reinitAttempts, maxTrayReinitAttempts);

            Sleep(retryDelayMs(state.reinitAttempts));
            result = tray_init(trayIcon.get());
        }

        if (result == 0) {
            std::printf("Tray erfolgreich neu initialisiert\n");
            state.reinitAttempts = 0;
        }

        state.reinitScheduled = false;
        return result == 0;
    }

    void retryTrayReinitAsync() {
        if (retryThread.joinable()) {
            if (retryRunning.load()) {
                return;
            }
            retryThread.join();
        }

        retryRunning.store(true);
        retryThread = std::jthread([this](std::stop_token stopToken) {
            Sleep(500);

            bool recovered = false;
            for (int attempt = 0; attempt < 3; ++attempt) {
                if (stopToken.stop_requested() || stopping.load()) {
                    break;
                }
                if (isExplorerReady() && reinitTray()) {
                    recovered = true;
                    break;
                }

                Sleep(500 * (attempt + 1));
            }

            if (!recovered && !stopToken.stop_requested() && !stopping.load()) {
                std::fprintf(stderr, "Tray konnte nach Explorer-Neustart nicht wiederhergestellt werden\n");
            }
            retryRunning.store(false);
        });
    }

    void scheduleTrayReinit() {
        if (stopping.load()) {
            return;
        }

        {
            std::lock_guard<std::mutex> lock(trayMutex);
            const DWORD now = GetTickCount();
            if (now - state.lastExplorerRestartTime < minExplorerRestartDelayMs) {
                return;
            }
            state.lastExplorerRestartTime = now;
        }
        Sleep(300);

        if (!reinitTray()) {
            retryTrayReinitAsync();
        }
    }

    static void CALLBACK handleExplorerEvent(HWINEVENTHOOK, DWORD event, HWND hwnd, LONG idObject, LONG, DWORD,
                                             DWORD) {
        std::lock_guard<std::mutex> lock(activeControllerMutex);
        if (!activeController || activeController->stopping.load() || idObject != OBJID_WINDOW || !isTaskbarWindow(hwnd)) {
            return;
        }

        if (event == EVENT_OBJECT_CREATE) {
            std::printf("Explorer-Neustart erkannt (Taskbar neu erstellt)\n");
            std::printf(isExplorerReady()
                            ? "Explorer ist bereit - Tray wird neu initialisiert\n"
                            : "Explorer noch nicht bereit - Warten...\n");
            activeController->scheduleTrayReinit();
            return;
        }

        if (event == EVENT_OBJECT_DESTROY) {
            std::printf("Explorer wird heruntergefahren\n");
        }
    }

    void installExplorerHook() {
        explorerHook = SetWinEventHook(EVENT_OBJECT_CREATE, EVENT_OBJECT_DESTROY, nullptr, handleExplorerEvent, 0, 0,
                                       WINEVENT_OUTOFCONTEXT);

        if (!explorerHook) {
            std::fprintf(stderr, "Warnung: Explorer-Neustart-Ueberwachung konnte nicht initialisiert werden\n");
            return;
        }

        std::printf("Explorer-Neustart-Ueberwachung erfolgreich initialisiert\n");
    }

    void uninstallExplorerHook() {
        if (explorerHook) {
            UnhookWinEvent(explorerHook);
            explorerHook = nullptr;
        }
    }

    ToolboxWindow& window;
    std::unique_ptr<toolboxTray> trayIcon;
    std::array<tray_menu, 6> menuItems;
    TrayState state;
    HWINEVENTHOOK explorerHook = nullptr;
    std::jthread retryThread;
    std::atomic_bool retryRunning = false;
    std::atomic_bool stopping = false;
    std::mutex trayMutex;
    static std::mutex activeControllerMutex;
    static Impl* activeController;
};

std::mutex TrayController::Impl::activeControllerMutex;
TrayController::Impl* TrayController::Impl::activeController = nullptr;

TrayController::TrayController(ToolboxWindow& window)
    : m_impl(std::make_unique<Impl>(window)) {}

TrayController::~TrayController() {
    shutdown();
}

bool TrayController::initialize() {
    return m_impl->initialize();
}

void TrayController::shutdown() {
    if (m_impl) {
        m_impl->shutdown();
    }
}
