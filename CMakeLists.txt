cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)
set(saucer_no_version_check ON)
set(BUILD_SHARED_LIBS OFF)
option(BUILD_SHARED_LIBS "Build as shared library" OFF)

project(Toolbox)

add_subdirectory(lib/c_tray)
add_subdirectory(lib/json)
add_subdirectory(lib/cppcodec)
add_subdirectory(lib/saucer)
add_subdirectory(lib/lua)
add_subdirectory(lib/sol2)
#add_subdirectory(lib/saucer4lua)

include_directories(inc)
include_directories(lib/json/include/nlohmann)
#include_directories(out_embed)

if (WIN32)
    set(RESOURCE_FILES toolbox.rc)
endif ()

# Header-Datei einbinden
include_directories(lib/c_tray)

# Plattformabhängige Einstellungen
if (WIN32)
    set(PLATFORM_SOURCES lib/c_tray/tray_windows.c)
    set(LIBS shell32)
elseif (APPLE)
    set(PLATFORM_SOURCES lib/c_tray/tray_darwin.m)
    find_library(COCOA_LIBRARY Cocoa)
    set(LIBS ${COCOA_LIBRARY})
elseif (UNIX)
    set(PLATFORM_SOURCES lib/c_tray/tray_linux.c)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(APPINDICATOR REQUIRED appindicator3-0.1)
    include_directories(${APPINDICATOR_INCLUDE_DIRS})
    set(LIBS ${APPINDICATOR_LIBRARIES})
endif ()

file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.h") # Nur für .cpp und .h
file(GLOB_RECURSE MODULE_SOURCES "module/*.ixx") # Separates GLOB für Module

add_executable(Toolbox main.cpp
        ${SOURCES}
        ${RESOURCE_FILES}
        ${PLATFORM_SOURCES}
)

target_sources(Toolbox
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        FILES ${MODULE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE "out_embed")
target_link_libraries(Toolbox
        PRIVATE
        saucer::saucer
        sol2::sol2
        lua
        tray
        nlohmann_json
        cppcodec
        #saucer4lua
)

if (WIN32 AND (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel"))
    set_target_properties(Toolbox PROPERTIES WIN32_EXECUTABLE TRUE)
endif ()