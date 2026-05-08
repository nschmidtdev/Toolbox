#pragma once

#ifdef _WIN32
    #include <Windows.h>
#else
    typedef void* HINSTANCE;
    typedef void* HICON;
#endif

extern "C" {
    HICON toolbox_load_small_icon(HINSTANCE instance, int resource_id);
}
