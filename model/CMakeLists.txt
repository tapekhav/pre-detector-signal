cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)

file(GLOB MODEL_HEADERS headers/*.h)
file(GLOB MODEL_SOURCE src/*.cpp)

add_library(Model ${MODEL_HEADERS} ${MODEL_SOURCE})