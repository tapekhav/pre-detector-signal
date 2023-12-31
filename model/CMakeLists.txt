cmake_minimum_required(VERSION 3.20)

find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
    message("Found Protobuf version: ${PROTOBUF_VERSION}")
else()
    message(FATAL_ERROR "Protobuf not found!")
endif()

add_subdirectory(radio)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${PROTOBUF_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter
        ${CMAKE_CURRENT_SOURCE_DIR}/../utilities/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/radio/modulation_factory/factory/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/radio/modulation_factory/products/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/radio/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/../library/files/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/../library/encode_data/encryption/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/../library/encode_data/utilities/headers
)

file(GLOB MODEL_HEADERS headers/*.h)
file(GLOB MODEL_SOURCE src/*.cpp)

set(PROTOBUF_GENERATE_CPP_APPEND_PATH TRUE)
set(PROTO_DIR ../protos)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_DIR}/model.proto)

file(GLOB PROTOBUF_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/*.pb.h)
file(GLOB PROTOBUF_SRC ${CMAKE_CURRENT_BINARY_DIR}/*.pb.cc)

add_library(
        Model
        ${MODEL_HEADERS}
        ${MODEL_SOURCE}
        ${PROTO_SRCS}
        ${PROTO_HDRS}
        ${PROTOBUF_HEADERS}
        ${PROTOBUF_SRC}
)

target_link_libraries(
        Model
        ${PROTOBUF_LIBRARIES}
        Radio
        EncodeData 
)

add_compile_definitions(plt_dir="${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter/plotters/coordinates.txt")
add_compile_definitions(plt="${CMAKE_CURRENT_SOURCE_DIR}/../utilities/plotter/plotters/meters.txt")

add_compile_definitions(path_to_signal="${CMAKE_CURRENT_SOURCE_DIR}/../result.txt")
add_compile_definitions(path_to_config="${CMAKE_CURRENT_SOURCE_DIR}/../config.json")
