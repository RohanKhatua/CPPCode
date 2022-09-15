cmake_minimum_required(VERSION 3.21)
project(CPPCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPPCode
        partition.cpp)

add_executable(FastInverseSquareRoot FastInverseSquareRoot.cpp)
add_executable(dspa dspa.cpp)