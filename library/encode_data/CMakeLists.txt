cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)
include_directories(../../utilities/headers)
include_directories (tests/)

file(GLOB ENCODE_DATA_HEADERS headers/*.h)
file(GLOB ENCODE_DATA_SOURCE src/*.cpp)

add_library(EncodeData ${ENCODE_DATA_HEADERS} ${ENCODE_DATA_SOURCE})

file(GLOB TESTS tests/*.cpp)

find_package(GTest)
if (${GTest_FOUND})
    message(STATUS "Starting tests...")
    add_executable(test_encode ${TESTS})

    target_link_libraries(test_encode
            gtest
            gtest_main
            ${CMAKE_THREAD_LIBS_INIT}
            GTest::GTest
            GTest::gtest_main
            GTest::gmock
            GTest::gmock_main
            EncodeData
    )
    enable_testing()
    add_test(NAME ExampleTest COMMAND test_encode)

endif (${GTest_FOUND})