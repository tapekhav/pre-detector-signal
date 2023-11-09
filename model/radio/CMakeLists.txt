cmake_minimum_required(VERSION 3.22.1)

find_package(FFTW3 REQUIRED)

include_directories(
        headers
)

file(GLOB RADIO_HEADERS headers/*.h)
file(GLOB RADIO_SOURCE src/*.cpp)

add_library(
        Radio STATIC
        ${RADIO_HEADERS}
        ${RADIO_SOURCE}
)

target_link_libraries(Radio FFTW3)