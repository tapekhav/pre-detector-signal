cmake_minimum_required(VERSION 3.22.1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/plotter)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../model)

file(GLOB UTILITIES_HEADERS headers/*.h)
file(GLOB UTILITIES_SOURCE src/*.cpp)

add_library(
        Utility
        ${UTILITIES_HEADERS}
        ${UTILITIES_SOURCE}
        plotter/plotter.h
)

add_compile_definitions(path_to_config="${CMAKE_CURRENT_SOURCE_DIR}/../config.json")
target_link_libraries(Utility Qt5::Widgets Qt5::Charts)