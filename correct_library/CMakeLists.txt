cmake_minimum_required(VERSION 3.22.1)

include_directories(encode/headers)
include_directories(files/headers)
include_directories (encode/tests/)

file(GLOB ENCODE_SHORT_HEADERS encode_data/headers/*.h)
file(GLOB ENCODE_SHORT_SOURCE encode_data/src/*.cpp)

file(GLOB FILES_HEADERS files/headers/*.h)
file(GLOB FILES_SOURCE files/src/*.cpp)

add_library(EncodeData ${ENCODE_SHORT_HEADERS} ${ENCODE_SHORT_SOURCE} ${FILES_HEADERS} ${FILES_SOURCE})

file(GLOB TESTS encode_data/tests/*.cpp)

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