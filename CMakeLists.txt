cmake_minimum_required(VERSION 3.21)
project(CPPCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPPCode
        partition.cpp)

add_executable(FastInverseSquareRoot FastInverseSquareRoot.cpp)


add_executable(bst bst.cpp)
add_executable(dspa_21BCE3982 dspa_21BCE3982.cpp)
add_executable(HeapSort_21BCE3982 HeapSort_21BCE3982.cpp)