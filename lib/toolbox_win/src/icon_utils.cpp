#include "toolbox_win/icon_utils.h"

#ifdef _WIN32
    #include <Windows.h>
#endif

HICON toolbox_load_small_icon(HINSTANCE instance, int resource_id) {
#ifdef _WIN32
    if (!instance) {
        instance = GetModuleHandle(NULL);
    }

    return static_cast<HICON>(LoadImage(
        instance,
        MAKEINTRESOURCE(resource_id),
        IMAGE_ICON,
        GetSystemMetrics(SM_CXSMICON),
        GetSystemMetrics(SM_CYSMICON),
        LR_SHARED
    ));
#else
    (void)instance;
    (void)resource_id;
    return nullptr;
#endif
}
