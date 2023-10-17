cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)
include_directories(../utilities/headers)

file(GLOB ENCODE_DATA_HEADERS headers/*.h)
file(GLOB ENCODE_DATA_SOURCE src/*.cpp)

add_library(EncodeData ${ENCODE_DATA_HEADERS} ${ENCODE_DATA_SOURCE})