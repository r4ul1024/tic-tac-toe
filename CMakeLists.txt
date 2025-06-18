cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable(tic_tac_toe ${SOURCES})

target_include_directories(tic_tac_toe PRIVATE include)
