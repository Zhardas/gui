cmake_minimum_required(VERSION 3.2)
project(comparison_gui)

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/lib/wxWidgets/include/")
link_directories(${PROJECT_SOURCE_DIR}/lib/wxWidgets/lib/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wno-unused-function -Wno-deprecated-declarations")

add_executable(comparison_gui
        main.cpp
        main.h)

target_link_libraries(comparison_gui ws2_32 winmm wxmsw30u wxpng wxzlib comctl32)
