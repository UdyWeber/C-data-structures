cmake_minimum_required(VERSION 3.22.1)
project(studying_data_structures C)

set(CMAKE_C_STANDARD 23)

add_executable(
        studying_data_structures main.c
        basics/basics.c
        basics/basics.h
        recursion/recursions.c
        recursion/recursions.h
        datastrucutres/array/array_practice.c
        datastrucutres/array/array_practice.h
        datastrucutres/linked_structs/nodes.h
        datastrucutres/linked_structs/singly_linked_list.c
        datastrucutres/linked_structs/singly_linked_list.h
        datastrucutres/linked_structs/nodes.c
)
