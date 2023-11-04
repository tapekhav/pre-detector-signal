cmake_minimum_required(VERSION 3.22.1)

find_package(Gnuradio REQUIRED)

include_directories(
        headers
        ${GNURADIO_INCLUDE_DIRS}
)

link_directories(${GNURADIO_LIBRARY_DIRS})

file(GLOB RADIO_HEADERS headers/*.h)
file(GLOB RADIO_SOURCE src/*.cpp)

add_library(
        Radio STATIC
        ${RADIO_HEADERS}
        ${RADIO_SOURCE}
)