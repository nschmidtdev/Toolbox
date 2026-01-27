module;

#include <functional>
#include "tray.h"

export module toolboxTray;


export
class toolboxTray : public tray {
public:
    // Konstruktor mit optionalen Parametern für Icon und Tooltip
    toolboxTray(const char* icon = nullptr, const char* tooltip = nullptr) {
        this->icon = icon;
        this->tooltip = const_cast<char*>(tooltip);
        this->menu = nullptr; // Initialisiere ohne Menü (kann später gesetzt werden)
    }

    // Funktion, um die gewünschte Aktion für den Linksklick zu setzen
    void setLeftClickAction(const std::function<void()>& action) {
        leftClickAction = action;
    }

    // Funktion zum Setzen des Tray-Menüs
    void setTrayMenu(tray_menu* menu) {
        this->menu = menu;
    }

    // Ereignis-Handler für Mausklicks
    void handleMouseClick(int button) {
        if (button == LEFT_CLICK && leftClickAction) {
            // Führt die Linksklick-Aktion aus
            leftClickAction();
        } else if (button == RIGHT_CLICK) {
            // Zeigt das Menü
            showMenu();
        }
    }

    enum MouseButton {
        LEFT_CLICK = 0,
        RIGHT_CLICK = 1
    };

private:
    std::function<void()> leftClickAction; // Aktion für Linksklick

    // Zeigt das Menü an (Rechtsklick)
    void showMenu() {
        if (this->menu) {
            tray_update(this); // Update des Trays mit dem Menü
        }
    }
};
