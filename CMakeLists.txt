cmake_minimum_required(VERSION 3.22.1)
project(pre-detector-signal)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG ("-std=c++17" COMPILER_HAVE_CPP17)
if (COMPILER_HAVE_CPP17)
    message(STATUS "Adding C++17")
    set(CMAKE_CXX_STANDARD 17)
endif(COMPILER_HAVE_CPP17)

if (MSVC_VERSION GREATER_EQUAL "1900")
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _cpp_17)
    if (_cpp_17)
        message(STATUS "Adding C++17")
        add_compile_options("/std:c++17")
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wconversion -Wformat -Wunused -Wshadow -Wuninitialized -Wsign-compare)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

find_package(Protobuf REQUIRED)

set(source_files
    model/model.proto
)

set(output_files "")

foreach(proto_file ${source_files})
    get_filename_component(output_file_name ${proto_file} NAME_WE)
    list(APPEND output_files
            ${CMAKE_CURRENT_BINARY_DIR}/model/proto/${output_file_name}.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/model/proto/${output_file_name}.pb.h
    )

    add_custom_command(
            OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/model/proto/${output_file_name}.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/model/proto/${output_file_name}.pb.h
            COMMAND protoc
            ARGS --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/model/proto
            -I${CMAKE_CURRENT_SOURCE_DIR}/model/proto
            ${CMAKE_CURRENT_SOURCE_DIR}/model/proto/${proto_file}
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/model/proto/${proto_file}
    )
endforeach()

add_custom_target(proto_generation DEPENDS ${output_files})


add_subdirectory(model)

include_directories(model/headers)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(model/proto)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/model)

add_executable(pre-detector-signal
        dependencies/json.hpp
        main.cpp)

target_link_libraries(pre-detector-signal Model ${PROTOBUF_LIBRARIES})
