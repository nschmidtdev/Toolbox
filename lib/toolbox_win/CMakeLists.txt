cmake_minimum_required(VERSION 3.30)

project(toolbox_win LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(toolbox_win STATIC
    src/icon_utils.cpp
)

target_include_directories(toolbox_win
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (WIN32)
    target_link_libraries(toolbox_win PUBLIC user32)
endif ()
