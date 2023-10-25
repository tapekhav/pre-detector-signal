cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)

file(GLOB PLOTTER_HEADERS headers/*.h)
file(GLOB PLOTTER_SOURCE src/*.cpp)

add_library(Qt_Plotters ${PLOTTER_HEADERS} ${PLOTTER_SOURCE})

target_link_libraries(Qt_Plotters Qt5::Widgets Qt5::Charts)