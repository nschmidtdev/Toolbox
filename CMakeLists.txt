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

include(FetchContent)
FetchContent_Declare(portable_file_dialogs
    GIT_REPOSITORY https://github.com/samhocevar/portable-file-dialogs.git
    GIT_TAG 8ccf2a93f70d021842e72fd950eac2a0bb244eec
    GIT_SHALLOW TRUE
)
# portable-file-dialogs 0.1.0 declares CMake 3.1 support. Its interface target
# is still compatible; permit that legacy policy declaration only while loading it.
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
FetchContent_MakeAvailable(portable_file_dialogs)
unset(CMAKE_POLICY_VERSION_MINIMUM)

add_subdirectory(lib/c_tray)
add_subdirectory(lib/json)
add_subdirectory(lib/cppcodec)
add_subdirectory(lib/saucer)
add_subdirectory(lib/lua)
add_subdirectory(lib/sol2)
add_subdirectory(lib/toolbox_win)
add_subdirectory(lib/CLI11)
add_library(rang INTERFACE)
target_include_directories(rang INTERFACE lib/rang/include)
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
    cli/main.cpp
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

if (MSVC)
    target_compile_options(Toolbox PRIVATE /utf-8)
endif ()

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
        CLI11::CLI11
        rang
        toolbox_win
        portable_file_dialogs
        saucer::embedded
)

if (WIN32)
    target_link_libraries(Toolbox PRIVATE shell32 user32 gdi32 shlwapi)
endif ()

include(CTest)
if (BUILD_TESTING)
    add_executable(toolbox-template-tests
        tests/toolTemplatesTests.cpp
        src/core/toolTemplates.cpp
    )
    target_include_directories(toolbox-template-tests PRIVATE inc)
    target_link_libraries(toolbox-template-tests PRIVATE sol2::sol2 lua::lib)
    if (MSVC)
        target_compile_options(toolbox-template-tests PRIVATE /utf-8)
    endif ()
    add_test(NAME toolbox-template-contract COMMAND toolbox-template-tests)

    add_executable(toolbox-settings-tests
        tests/toolRegistrySettingsTests.cpp
        src/core/toolRegistry.cpp
        src/core/toolTemplates.cpp
    )
    target_include_directories(toolbox-settings-tests PRIVATE inc)
    target_link_libraries(toolbox-settings-tests PRIVATE nlohmann_json cppcodec)
    if (MSVC)
        target_compile_options(toolbox-settings-tests PRIVATE /utf-8)
    endif ()
    add_test(NAME toolbox-settings-contract COMMAND toolbox-settings-tests)

    add_executable(toolbox-lua-runner-tests
        tests/luaRunnerTests.cpp
        src/lua/luaRunner.cpp
        src/lua/toolLaunchBridge.cpp
    )
    target_include_directories(toolbox-lua-runner-tests PRIVATE inc)
    target_link_libraries(toolbox-lua-runner-tests PRIVATE sol2::sol2 lua::lib)
    if (WIN32)
        target_link_libraries(toolbox-lua-runner-tests PRIVATE shell32)
    endif ()
    if (MSVC)
        target_compile_options(toolbox-lua-runner-tests PRIVATE /utf-8)
    endif ()
    add_test(NAME toolbox-lua-runner-contract COMMAND toolbox-lua-runner-tests)

    add_executable(toolbox-file-dialog-tests
        tests/fileDialogTests.cpp
        src/platform/fileDialog.cpp
    )
    target_include_directories(toolbox-file-dialog-tests PRIVATE inc)
    target_link_libraries(toolbox-file-dialog-tests PRIVATE portable_file_dialogs)
    if (MSVC)
        target_compile_options(toolbox-file-dialog-tests PRIVATE /utf-8)
    endif ()
    add_test(NAME toolbox-file-dialog-contract COMMAND toolbox-file-dialog-tests)

    find_package(Python3 COMPONENTS Interpreter QUIET)
    if (Python3_Interpreter_FOUND)
        add_test(
            NAME toolbox-cli-contract
            COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/toolbox_cli_test.py $<TARGET_FILE:Toolbox>
        )
    endif ()

    find_program(NODE_EXECUTABLE node)
    if (NODE_EXECUTABLE)
        add_test(
            NAME toolbox-runtime-ui-contract
            COMMAND ${NODE_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/toolRuntime.test.js
        )
    endif ()
endif ()

if (WIN32)
    # Toolbox is a console-subsystem binary so -h/list/create/run write to the
    # inherited stdout/stderr. In GUI mode the console window is hidden at runtime.
    set_target_properties(Toolbox PROPERTIES
        WIN32_EXECUTABLE FALSE
        LINK_FLAGS "/ENTRY:\"wmainCRTStartup\""
    )
endif ()
