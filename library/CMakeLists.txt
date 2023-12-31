project(pre-detector-signal)
cmake_minimum_required(VERSION 3.22.1)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/files/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/encode_data/tests
        ${CMAKE_CURRENT_SOURCE_DIR}/encode_data/utilities/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/encode_data/encryption/headers
        ${CMAKE_CURRENT_SOURCE_DIR}/encode_data/exceptions/headers
)

file(GLOB UTILITIES_HEADERS encode_data/utilities/headers/*.h)
file(GLOB UTILITIES_SOURCE encode_data/utilities/src/*.cpp)

file(GLOB FILES_COMPONENTS_HEADERS files/headers/*.h)
file(GLOB FILES_COMPONENTS_SOURCE files/src/*.cpp)

file(GLOB EXCEPTIONS_HEADERS encode_data/exceptions/headers/*.h)
file(GLOB EXCEPTIONS_SOURCE encode_data/exceptions/src/*.cpp)

file(GLOB ENCRYPTION_HEADERS encode_data/encryption/headers/*.h)
file(GLOB ENCRYPTION_SOURCE encode_data/encryption/src/*.cpp)

add_library(
        EncodeData
        ${ENCRYPTION_HEADERS}
        ${ENCRYPTION_SOURCE}
        ${EXCEPTIONS_HEADERS}
        ${EXCEPTIONS_SOURCE}
        ${UTILITIES_HEADERS}
        ${UTILITIES_SOURCE}
        ${FILES_COMPONENTS_HEADERS}
        ${FILES_COMPONENTS_SOURCE}
)

file(GLOB TESTS encode_data/tests/*.cpp)

find_package(GTest)
if (${GTest_FOUND})
    message(STATUS "Starting encode tests...")

    add_executable(test_encode ${TESTS})

    add_definitions(-DGTEST_SKIP_MEDIATOR=ON)
    target_compile_definitions(test_encode PRIVATE -DGTEST_SKIP_MEDIATOR)

    target_link_libraries(
            test_encode
            PUBLIC
            gtest
            gtest_main
            ${CMAKE_THREAD_LIBS_INIT}
            GTest::GTest
            GTest::gtest_main
            GTest::gmock
            GTest::gmock_main
            spdlog::spdlog
            fmt::fmt
            EncodeData
    )

    enable_testing()
    add_test(NAME ExampleTest COMMAND test_encode)
else()
    message(WARNING "GTest not found. Skipping test_encode.")
endif ()


target_link_libraries(EncodeData PUBLIC spdlog::spdlog fmt::fmt)
add_compile_definitions(CURRENT_DIR="${CMAKE_CURRENT_SOURCE_DIR}")