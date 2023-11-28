cmake_minimum_required(VERSION 3.20)
project(pre-detector-signal)

include(CheckCXXCompilerFlag)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
    #add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wconversion -Wformat -Wunused -Wshadow -Wuninitialized -Wsign-compare)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

set(CMAKE_PREFIX_PATH "/home/vladimir/anaconda3/lib/cmake/Qt5")

find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)
find_package(Protobuf REQUIRED)

if(PROTOBUF_FOUND)
    message("Found Protobuf version: ${PROTOBUF_VERSION}")
else()
    message(FATAL_ERROR "Protobuf not found!")
endif()
set(PROTOBUF_PROTOC_EXECUTABLE /usr/bin/protoc)
set_target_properties(protobuf::protoc PROPERTIES IMPORTED_LOCATION ${PROTOBUF_PROTOC_EXECUTABLE})

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Charts)

set(
    source_files 
    model.proto
)

set(output_files "")

foreach(proto_file ${source_files})
    get_filename_component(output_file_name ${proto_file} NAME_WE)
    list(APPEND output_files
            ${CMAKE_CURRENT_BINARY_DIR}/model/${output_file_name}.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/model/${output_file_name}.pb.h
    )

    add_custom_command(
            OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/protos/${output_file_name}.pb.cc
            ${CMAKE_CURRENT_BINARY_DIR}/protos/${output_file_name}.pb.h
            COMMAND protoc
            ARGS --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/protos
            -I${CMAKE_CURRENT_SOURCE_DIR}/protos
            protos/${proto_file}
            DEPENDS protos/${proto_file}
    )
endforeach()

add_custom_target(proto_generation DEPENDS ${output_files})

add_subdirectory(model)
add_subdirectory(utilities)
add_subdirectory(library)
add_subdirectory(qt_app)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/model/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/library/encode_data/utilities/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/library/encode_data/encryption/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/library/files/headers
        ${PROTOBUF_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/utilities/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/utilities/plotter
        ${CMAKE_CURRENT_BINARY_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/model/radio/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/model/radio/modulation_factory/factory/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/model/radio/modulation_factory/products/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/qt_app/qt_plotter_view/qt_components/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/qt_app/qt_plotter_view/qt_mediators/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/qt_app/qt_plotter_view/qt_dependencies/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/qt_app/qt_plotter_controller/headers
)

add_executable(
        pre-detector-signal
        main.cpp
)


target_link_libraries(
        pre-detector-signal
        Model
        Utility
        EncodeData
        ${PROTOBUF_LIBRARIES}
        Qt5::Core
        Qt5::Widgets
        Qt5::Charts
        fmt::fmt
        spdlog::spdlog
        Qt_Plotters
        Radio
)

add_compile_definitions(path_to_config="${CMAKE_CURRENT_SOURCE_DIR}/config.json")
add_compile_definitions(path_to_signal="${CMAKE_CURRENT_SOURCE_DIR}/result.txt")
add_compile_definitions(plt_dir="${CMAKE_CURRENT_SOURCE_DIR}/utilities/plotter/plotters/coordinates.txt")
add_compile_definitions(plt="${CMAKE_CURRENT_SOURCE_DIR}/utilities/plotter/plotters/meters.txt")
