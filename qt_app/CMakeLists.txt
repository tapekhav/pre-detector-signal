cmake_minimum_required(VERSION 3.22.1)

project(Qt_Plotters)

include_directories(headers)

file(GLOB QT_PLOTTER_HEADERS headers/*.h)
file(GLOB QT_PLOTTER_SOURCE src/*.cpp)

add_library(Qt_Plotters ${QT_PLOTTER_HEADERS} ${QT_PLOTTER_SOURCE})
target_link_libraries(Qt_Plotters Qt5::Widgets Qt5::Charts)
