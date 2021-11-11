project(ChessEngineTests LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)

file(GLOB SOURCES "*.cpp")
add_executable(ChessEngineTests ${SOURCES})

target_link_libraries(ChessEngineTests PUBLIC 
    gtest_main 
    chess_engine
)

add_test(
    NAME ChessEngineTests
    COMMAND ChessEngineTests
)