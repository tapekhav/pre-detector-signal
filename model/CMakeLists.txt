cmake_minimum_required(VERSION 3.22.1)

find_package(Protobuf REQUIRED)

include_directories(headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter/plotter.h)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB MODEL_HEADERS headers/*.h)
file(GLOB MODEL_SOURCE src/*.cpp)

set(PROTOBUF_GENERATE_CPP_APPEND_PATH TRUE)
set(PROTO_DIR ../protos)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_DIR}/model.proto)

file(GLOB PROTOBUF_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/*.pb.h)
file(GLOB PROTOBUF_SRC ${CMAKE_CURRENT_BINARY_DIR}/*.pb.cc)

add_library(Model STATIC ${MODEL_HEADERS} ${MODEL_SOURCE} ${PROTO_SRCS} ${PROTO_HDRS}
            ${PROTOBUF_HEADERS} ${PROTOBUF_SRC})
target_link_libraries(Model ${PROTOBUF_LIBRARIES})

add_compile_definitions(plt_dir="${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter/plotters/coordinates.txt")
add_compile_definitions(plt="${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter/plotters/meters.txt")