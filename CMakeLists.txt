cmake_minimum_required(VERSION 3.29)
project(c_lab_classes C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(26_09_2024_first_lab)

add_executable(1_1_a_InputVerificationAndConversion 10_10_2024_third_lab/1_1_a_InputVerificationAndConversion.c
        10_10_2024_third_lab/morse_command.c
        17_10_2024_fifth_lab/1_1.c)
add_executable(1_1_b_IntegerConversionWithAtof 10_10_2024_third_lab/1_1_b_IntegerConversionWithAtof.c)
add_executable(1_1_c_d_VerificationOfTheNumberOfPassportCharacters 10_10_2024_third_lab/1_1_c_d_VerificationOfTheNumberOfPassportCharacters.c)
add_executable(1_1_e_ConversionOfInputCharactersTouUpercaseLowercase 10_10_2024_third_lab/1_1_e_ConversionOfInputCharactersTouUpercaseLowercase.c)
add_executable(1_2MorseCodeTranslator 10_10_2024_third_lab/1_2MorseCodeTranslator.c)
add_executable(morse_command 10_10_2024_third_lab/morse_command.c)

add_executable(1_1 17_10_2024_fifth_lab/1_1.c
        17_10_2024_fifth_lab/1_2.c
        17_10_2024_fifth_lab/2_1.c
        24_10_2024_sixth_lab/1_1_lab_5.c
        24_10_2024_sixth_lab/rectangle_sorting_1.c)
add_executable(1_2 17_10_2024_fifth_lab/1_2.c)

add_executable(2_1 17_10_2024_fifth_lab/2_1.c)

add_executable(1_1_lab_5 24_10_2024_sixth_lab/1_1_lab_5.c)

add_executable(rectangle_sorting_1 24_10_2024_sixth_lab/rectangle_sorting_1.c)

add_executable(rectangle_sorting_2 24_10_2024_sixth_lab/rectangle_sorting_2.c)



