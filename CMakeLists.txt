cmake_minimum_required(VERSION 3.26)
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
)
