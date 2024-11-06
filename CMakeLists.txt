cmake_minimum_required(VERSION 3.16)
project(lab_exercises C)

set(CMAKE_C_STANDARD 99)

add_executable(student_record_management_system
        Lab_6/main.c
        Lab_6/student_record_management_system.c
        Lab_6/student_record_management_system.h)
