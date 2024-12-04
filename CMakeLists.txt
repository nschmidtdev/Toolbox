cmake_minimum_required(VERSION 3.30)
project(Toolbox)

set(CMAKE_CXX_STANDARD 23)
set(saucer_no_version_check ON)
set(BUILD_SHARED_LIBS OFF)


add_subdirectory(lib/saucer)
add_subdirectory(lib/lua)
add_subdirectory(lib/sol2)

include_directories(inc)
include_directories(out_embed)
file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.h")

add_executable(Toolbox main.cpp ${SOURCES})

target_link_libraries(Toolbox PRIVATE saucer::saucer sol2::sol2 lua)
