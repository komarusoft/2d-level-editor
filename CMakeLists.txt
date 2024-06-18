cmake_minimum_required(VERSION 3.5)

project(2d-level-editor LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "clang")  

find_package(raylib REQUIRED)
 
option(DEBUG "Debug version?" OFF)
if(DEBUG)
    # Set Debug - for debug
    # Set Release - for release
    set(CMAKE_BUILD_TYPE Debug)
    add_compile_definitions(DEBUG)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE 
    src/main.c
    src/level.c
    src/gui.c
    )
add_executable(2d-level-editor ${SOURCE})

target_link_libraries(2d-level-editor PRIVATE raylib)

target_include_directories(2d-level-editor PRIVATE ${RAYLIB_INCLUDE_DIRS})

if(UNIX AND NOT APPLE)
    target_link_libraries(2d-level-editor PRIVATE m pthread dl rt X11)
endif()

# For Windows idk...
# if(WIN32)
#     target_link_libraries(2d-level-editor PRIVATE gdi32 winmm)
# endif()
