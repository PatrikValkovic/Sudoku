cmake_minimum_required(VERSION 3.5)
project(Sudoku)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Group.h
        Group.cpp
        Manager.h
        Manager.cpp
        Options.h
        Options.cpp Functions.h Functions.cpp)
add_executable(Sudoku ${SOURCE_FILES})