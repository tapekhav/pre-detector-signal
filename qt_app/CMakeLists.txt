cmake_minimum_required(VERSION 3.22.1)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Charts)

set(CMAKE_AUTOUIC ON)

include_directories(
        headers
        ui
)

file(GLOB QT_PLOTTER_HEADERS headers/*.h)
file(GLOB QT_PLOTTER_SOURCE src/*.cpp)

set(FORMS
        ui/qt_plotter.ui
)

qt5_wrap_ui(FORMS_HEADERS ${FORMS})

add_library(Qt_Plotters ${QT_PLOTTER_HEADERS} ${QT_PLOTTER_SOURCE} ${FORMS_HEADERS})
target_link_libraries(Qt_Plotters Qt5::Core Qt5::Widgets Qt5::Charts)
