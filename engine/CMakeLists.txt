project(JacoboBot LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(src)

set(PROJECT_SOURCES
        "main.cpp"
)

add_executable(JacoboBot
        ${PROJECT_SOURCES}
)

target_link_libraries(JacoboBot PUBLIC chess_engine)
target_include_directories(JacoboBot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
