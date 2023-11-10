cmake_minimum_required(VERSION 3.22.1)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Charts PrintSupport)

set(CMAKE_AUTOMOC ON)

include_directories(
        qt_dependencies/headers
        qt_mediators/headers
        qt_components/headers
        ${CMAKE_CURRENT_BINARY_DIR}
        ../model/radio/headers
)

file(GLOB QT_DEPENDENCIES_HEADERS qt_dependencies/headers/*.h)
file(GLOB QT_DEPENDENCIES_SOURCE qt_dependencies/src/*.cpp)

file(GLOB QT_MEDIATORS_HEADERS qt_mediators/headers/*.h)
file(GLOB QT_MEDIATORS_SOURCE qt_mediators/src/*.cpp)

file(GLOB QT_COMPONENTS_HEADERS qt_components/headers/*.h)
file(GLOB QT_COMPONENTS_SOURCE qt_components/src/*.cpp)

file(GLOB QT_COMPONENTS_UI qt_components/ui/*.ui)
set(FORMS
        ${QT_COMPONENTS_UI}
)
qt5_wrap_ui(FORMS_HEADERS ${FORMS})

add_library(
        Qt_Plotters
        ${QT_DEPENDENCIES_HEADERS}
        ${QT_DEPENDENCIES_SOURCE}
        ${QT_MEDIATORS_HEADERS}
        ${QT_MEDIATORS_SOURCE}
        ${QT_COMPONENTS_HEADERS}
        ${QT_COMPONENTS_SOURCE}
        ${FORMS_HEADERS}
)

target_link_libraries(
        Qt_Plotters
        Qt5::Core
        Qt5::Widgets
        Qt5::Charts
        Qt5::PrintSupport
)
