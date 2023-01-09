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
add_executable(graph_utility graph_utility.cpp)
add_executable(roman_to_int roman_to_int.cpp)
add_executable(linked_list linked_list.cpp)
add_executable(testing testing.cpp)
add_executable(kruskal kruskal.cpp)
add_executable(BST BST.cpp)
add_executable(fast_mult fast_mult.cpp)


add_executable(karatsuba_21BCE3982 karatsuba_21BCE3982.cpp)
add_executable(frac_knapsack_21BCE3982 frac_knapsack_21BCE3982.cpp)
add_executable(graph_coloring graph_coloring_21BCE3982.cpp)