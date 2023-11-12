cmake_minimum_required(VERSION 3.22.1)

find_package(FFTW3 REQUIRED)

include_directories(
        headers
        modulation_factory/factory/headers
        modulation_factory/products/headers
)

file(GLOB RADIO_HEADERS headers/*.h)
file(GLOB RADIO_SOURCE src/*.cpp)
file(GLOB RADIO_TESTS tests/*.cpp)

file(GLOB FACTORY_HEADERS modulation_factory/factory/headers/*.h)
file(GLOB FACTORY_SRC modulation_factory/factory/src/*.cpp)

file(GLOB PRODUCTS_HEADERS modulation_factory/products/headers/*.h)
file(GLOB PRODUCTS_SRC modulation_factory/products/src/*.cpp)

add_library(
        Radio STATIC
        ${RADIO_HEADERS}
        ${RADIO_SOURCE}
        ${FACTORY_HEADERS}
        ${FACTORY_SRC}
        ${PRODUCTS_HEADERS}
        ${PRODUCTS_SRC}
)
target_link_libraries(Radio fftw3)

find_package(GTest)
if (${GTest_FOUND})
    message(STATUS "Starting tests for radio...")
    add_executable(test_radio ${RADIO_TESTS})

    target_link_libraries(test_radio
            gtest
            gtest_main
            ${CMAKE_THREAD_LIBS_INIT}
            GTest::GTest
            GTest::gtest_main
            GTest::gmock
            GTest::gmock_main
            Radio
    )
    enable_testing()
    add_test(NAME ExampleTest COMMAND test_radio)

endif (${GTest_FOUND})