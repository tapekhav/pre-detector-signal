cmake_minimum_required(VERSION 3.22.1)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Charts PrintSupport)

set(CMAKE_AUTOMOC ON)

include_directories(
        qt_plotter_view/qt_dependencies/headers
        qt_plotter_view/qt_mediators/headers
        qt_plotter_view/qt_components/headers
        qt_plotter_controller/headers
        ${CMAKE_CURRENT_BINARY_DIR}
        ../model/headers
        ../model/radio/headers
        ../model/radio/modulation_factory/factory/headers
        ../model/radio/modulation_factory/products/headers
        ../utilities/headers
)

file(GLOB QT_CONTROLLER_HEADERS qt_plotter_controller/headers/*.h)
file(GLOB QT_CONTROLLER_SRC qt_plotter_controller/src/*.cpp)

file(GLOB QT_DEPENDENCIES_HEADERS qt_plotter_view/qt_dependencies/headers/*.h)
file(GLOB QT_DEPENDENCIES_SOURCE qt_plotter_view/qt_dependencies/src/*.cpp)

file(GLOB QT_MEDIATORS_HEADERS qt_plotter_view/qt_mediators/headers/*.h)
file(GLOB QT_MEDIATORS_SOURCE qt_plotter_view/qt_mediators/src/*.cpp)

file(GLOB QT_COMPONENTS_HEADERS qt_plotter_view/qt_components/headers/*.h)
file(GLOB QT_COMPONENTS_SOURCE qt_plotter_view/qt_components/src/*.cpp)

file(GLOB QT_COMPONENTS_UI qt_plotter_view/qt_components/ui/*.ui)
set(FORMS
        ${QT_COMPONENTS_UI}
)
qt5_wrap_ui(FORMS_HEADERS ${FORMS})

add_library(
        Qt_Plotters
        ${QT_CONTROLLER_HEADERS}
        ${QT_CONTROLLER_SRC}
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
        Radio
        Model
)
