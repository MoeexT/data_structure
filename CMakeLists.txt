cmake_minimum_required(VERSION 3.10)
project(data_structure)

set(CMAKE_CXX_STANDARD 11)

add_executable(data_structure main.cpp linear_table/sequence_table.cpp linear_table.h linear_table/single_list.cpp linear_table/doubly_linked_list.cpp linear_table/circular_linked_list.cpp)