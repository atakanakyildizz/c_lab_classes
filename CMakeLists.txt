cmake_minimum_required(VERSION 3.29)
project(c_lab_classes C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(26_09_2024_first_lab)

add_executable(c_lab_classes
    26_09_2024_first_lab/first_lab.c
        3_10_2024_second_lab/3_10_2024_second_lab.c
        10_10_2024_third_lab/third_lab.c)

add_executable(3_10_2024_second_lab 3_10_2024_second_lab/3_10_2024_second_lab.c
        10_10_2024_third_lab/third_lab.c)
add_executable(first_lab 26_09_2024_first_lab/first_lab.c
        10_10_2024_third_lab/third_lab.c)
add_executable(third_lab 10_10_2024_third_lab/third_lab.c
        10_10_2024_third_lab/third_lab.c)