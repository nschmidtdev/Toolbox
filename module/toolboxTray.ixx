module;

#include <functional>
#include "tray.h"

export module toolboxTray;

export
class toolboxTray : public tray {
public:
    // Konstruktor mit optionalen Parametern fuer Icon und Tooltip
    toolboxTray(const char* icon = nullptr, const char* tooltip = nullptr) {
        this->icon = icon;
        this->tooltip = const_cast<char*>(tooltip);
        this->menu = nullptr; // Initialisiere ohne Menue (kann spaeter gesetzt werden)
        this->icon_handle = nullptr;
        this->icon_is_shared = 0;
        this->left_click_cb = nullptr;
        this->left_click_context = nullptr;
    }

    // Funktion, um die gewuenschte Aktion fuer den Linksklick zu setzen
    void setLeftClickAction(const std::function<void()>& action) {
        leftClickAction = action;
        this->left_click_cb = &toolboxTray::leftClickThunk;
        this->left_click_context = this;
    }

    // Funktion zum Setzen des Tray-Menues
    void setTrayMenu(tray_menu* menu) {
        this->menu = menu;
    }

    // Ereignis-Handler fuer Mausklicks
    void handleMouseClick(int button) {
        if (button == LEFT_CLICK && leftClickAction) {
            // Fuehrt die Linksklick-Aktion aus
            leftClickAction();
        } else if (button == RIGHT_CLICK) {
            // Zeigt das Menue
            showMenu();
        }
    }

    enum MouseButton {
        LEFT_CLICK = 0,
        RIGHT_CLICK = 1
    };

private:
    std::function<void()> leftClickAction; // Aktion fuer Linksklick

    static void leftClickThunk(void* context) {
        auto* self = static_cast<toolboxTray*>(context);
        if (self && self->leftClickAction) {
            self->leftClickAction();
        }
    }

    // Zeigt das Menue an (Rechtsklick)
    void showMenu() {
        if (this->menu) {
            tray_update(this); // Update des Trays mit dem Menue
        }
    }
};
