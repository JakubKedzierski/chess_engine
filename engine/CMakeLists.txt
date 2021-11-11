project(JacoboBot LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
add_subdirectory(src)

add_executable(JacoboBot "main.cpp")
target_link_libraries(JacoboBot PUBLIC chess_engine)
target_include_directories(JacoboBot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

