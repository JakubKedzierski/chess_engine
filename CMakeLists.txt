project(JacoboBot LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(googletest)
add_subdirectory(engine)
add_subdirectory(tests)

