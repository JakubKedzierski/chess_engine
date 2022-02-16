project(chess_engine LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


file(GLOB SOURCES "*.cpp" "*.hpp")
add_library(chess_engine STATIC ${SOURCES})
target_include_directories(chess_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(chess_engine PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(chess_engine)
endif()
