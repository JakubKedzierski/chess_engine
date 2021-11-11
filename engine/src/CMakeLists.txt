project(chess_engine LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)

file(GLOB SOURCES "*.cpp")
add_library(chess_engine STATIC ${SOURCES})
target_include_directories(chess_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)