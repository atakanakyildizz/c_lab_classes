cmake_minimum_required(VERSION 3.16)
project(lab_exercises C)

set(CMAKE_C_STANDARD 99)


add_executable(catalan lab_08/catalan_numbers.c)

add_executable(multiplication lab_08/multiplication.c)

add_executable(white-spaces_count lab_08/white-spaces_count.c)

add_executable(palindromes lab_08/palindromes.c)

add_executable(triangles lab_08/triangles.c)