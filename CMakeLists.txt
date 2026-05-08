cmake_minimum_required(VERSION 3.30)

project(Toolbox LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
set(saucer_no_version_check ON CACHE BOOL "Skip saucer version checks" FORCE)

# MSVC 19.44 provides the STL features saucer-fill may try to polyfill
# (jthread, stop_token, move_only_function, join_with). Keep the polyfill target
# present for saucer, but disable replacements to avoid duplicate declarations.
set(fill_replacements "" CACHE STRING "saucer-fill replacements" FORCE)

add_subdirectory(lib/c_tray)
add_subdirectory(lib/json)
add_subdirectory(lib/cppcodec)
add_subdirectory(lib/saucer)
add_subdirectory(lib/lua)
add_subdirectory(lib/sol2)
add_subdirectory(lib/toolbox_win)
# add_subdirectory(lib/saucer4lua)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

file(GLOB_RECURSE APP_HEADERS CONFIGURE_DEPENDS
    "inc/*.h"
    "inc/*.hpp"
)

if (WIN32)
    list(APPEND APP_SOURCES toolbox.rc)
endif ()

add_executable(Toolbox
    main.cpp
    ${APP_SOURCES}
    ${APP_HEADERS}
)

target_sources(Toolbox
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        FILES
            module/toolboxTray.ixx
)

target_include_directories(Toolbox
    PRIVATE
        inc
        lib/c_tray
)

if (WIN32)
    target_compile_definitions(Toolbox PRIVATE NOMINMAX UNICODE _UNICODE)

    file(GLOB WEBVIEW2_INCLUDE_DIR
        "${CMAKE_BINARY_DIR}/lib/saucer/nuget/packages/Microsoft.Web.WebView2.*/build/native/include"
    )

    if (WEBVIEW2_INCLUDE_DIR)
        message(STATUS "Using WebView2 includes at: ${WEBVIEW2_INCLUDE_DIR}")
        target_include_directories(Toolbox PRIVATE ${WEBVIEW2_INCLUDE_DIR})
    else ()
        message(WARNING "WebView2 headers not found in build tree. The build may fail when including WebView2.h.")
    endif ()
endif ()

set(EMBED_DESTINATION "${CMAKE_BINARY_DIR}/embedded")
file(MAKE_DIRECTORY "${EMBED_DESTINATION}/saucer/embedded")

file(GLOB_RECURSE EMBED_RESOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/res/*"
)

foreach (RESOURCE_FILE IN LISTS EMBED_RESOURCE_FILES)
    if (IS_DIRECTORY "${RESOURCE_FILE}")
        continue()
    endif ()

    file(RELATIVE_PATH RESOURCE_RELATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/res" "${RESOURCE_FILE}")
    get_filename_component(RESOURCE_RELATIVE_DIR "${RESOURCE_RELATIVE_PATH}" DIRECTORY)
    file(MAKE_DIRECTORY "${EMBED_DESTINATION}/saucer/embedded/files/${RESOURCE_RELATIVE_DIR}")
endforeach ()

saucer_embed("res"
    TARGET Toolbox
    DESTINATION "${EMBED_DESTINATION}"
)

target_link_libraries(Toolbox
    PRIVATE
        saucer::saucer
        sol2::sol2
        lua::lib
        tray
        nlohmann_json
        cppcodec
        toolbox_win
        saucer::embedded
)

if (WIN32)
    target_link_libraries(Toolbox PRIVATE shell32 user32 gdi32)
endif ()

if (WIN32 AND (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel"))
    set_target_properties(Toolbox PROPERTIES WIN32_EXECUTABLE TRUE)
endif ()
