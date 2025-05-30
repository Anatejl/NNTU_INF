cmake_minimum_required(VERSION 3.20)
project(NNTU)

# Set CMAKE_OSX_SYSROOT to empty or to a valid SDK path to avoid warnings
set(CMAKE_OSX_SYSROOT "" CACHE STRING "SDK path" FORCE)

#set(CMAKE_C_COMPILER "/bin/c99-gcc")
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
enable_testing()
include_directories(${CMAKE_SOURCE_DIR})
include_directories("/build")

# 1 course / 1 semester

#add_executable(test "1/1.Test/Test.c")
#add_executable(1.1 "1/1.1/1.c")
#add_executable(1.2 "1/1.2/2.c")
#add_executable(1.3 "1/1.3/3.c")
#add_executable(1.4 "1/1.4/4.c")
#add_executable(1.5 "1/1.5/5.c")
#add_executable(1.6 "1/1.6/6.c")
#add_executable(1.7 "1/1.7/7.c")
#add_executable(1.8 "1/1.8/8.c")
#add_executable(1.9 "1/1.9/9.c")
#add_executable(1.10 "1/1.10/10.c")
#add_executable(1.11 "1/1.11/11.c")
#add_executable(1.12 "1/1.12/12.c")
#add_executable(1.13 "1/1.13/13.c")
#add_executable(1.14 "1/1.14/14.c")
#add_executable(1.15 "1/1.15/15.c")
#add_executable(1.Tin2.1 "1/Tinakov/2.1/2.1.c")
#add_executable(1.Tin2.2 "1/Tinakov/2.2/2.2.c")

# add_executable(1.1-Egorov 1/Egorov/1/1.c)
# add_executable(1.1EZ-Egorov 1/Egorov/1EZ/1EZ.c)
# add_executable(1.2.1-Egorov 1/Egorov/2.1/2.1.c)
# add_executable(1.2.2-Egorov 1/Egorov/2.2/2.2.c)

# add_executable(1.3-Egorov 1/Egorov/3/3.c)
# target_link_libraries(1.3-Egorov m)

# add_executable(1.4-pointer-Egorov 1/Egorov/4/pointer/4-pointer-main.c
#        1/Egorov/4/pointer/4-pointer-input.c
#        1/Egorov/4/pointer/4-pointer-process.c
#        1/Egorov/4/pointer/4-pointer-output.c)

# add_executable(1.4-array-Egorov 1/Egorov/4/array/4-array-main.c
#        1/Egorov/4/array/4-array-input.c
#        1/Egorov/4/array/4-array-process.c
#        1/Egorov/4/array/4-array-output.c)

# add_executable(1.4-TEST-Egorov 1/Egorov/4/pointer/4-pointer-test.c
#         1/Egorov/4/pointer/4-pointer-process.c)

# add_test(NAME REVERSE_TEST COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/1.4-TEST-Egorov)

# add_executable(1.5-array-Egorov 1/Egorov/5/array/5-array-main.c
#         1/Egorov/5/array/5-array-input.c
#         1/Egorov/5/array/5-array-process.c
#         1/Egorov/5/array/5-array-output.c)

# add_executable(1.5-pointer-Egorov 1/Egorov/5/pointer/5-pointer-main.c
#         1/Egorov/5/pointer/5-pointer-run.c
#         1/Egorov/5/pointer/5-pointer-input.c
#         1/Egorov/5/pointer/5-pointer-process.c
#         1/Egorov/5/pointer/5-pointer-output.c)

# add_executable(1.1-Sedyx 1/Sedyx/1/1.c)
# add_executable(1.2.1-Sedyx 1/Sedyx/2-1/2-1.c)
# add_executable(1.2.2-Sedyx 1/Sedyx/2-2/2-2.c)
# target_link_libraries(1.2.2-Sedyx m)
# add_executable(1.3-Sedyx 1/Sedyx/3/3.c)
# target_link_libraries(1.3-Sedyx m)
# add_executable(1.4a-Sedyx 1/Sedyx/4a/4a-main.c
#         1/Sedyx/4a/4a-header.h
#         1/Sedyx/4a/4a-input.c
#         1/Sedyx/4a/4a-process.c
#         1/Sedyx/4a/4a-output.c)
# add_executable(1.4p-Sedyx 1/Sedyx/4p/4p-main.c
#         1/Sedyx/4p/4p-header.h
#         1/Sedyx/4p/4p-input.c
#         1/Sedyx/4p/4p-process.c
#         1/Sedyx/4p/4p-output.c)
# add_executable(1.5a-Sedyx 1/Sedyx/5a/5a-main.c
#         1/Sedyx/5a/5a-header.h
#         1/Sedyx/5a/5a-input.c
#         1/Sedyx/5a/5a-process.c
#         1/Sedyx/5a/5a-output.c)
# add_executable(1.5p-Sedyx 1/Sedyx/5p/5p-main.c
#         1/Sedyx/5p/5p-header.h
#         1/Sedyx/5p/5p-input.c
#         1/Sedyx/5p/5p-process.c
#         1/Sedyx/5p/5p-output.c)

# add_executable(1.1-Vor 1/Vor/1/1.c)
# target_link_libraries(1.1-Vor m)
# add_executable(1.2.1-Vor 1/Vor/2-1/2-1.c)
# add_executable(1.2.2-Vor 1/Vor/2-2/2-2.c)
# target_link_libraries(1.2.2-Vor m)
# add_executable(1.3-Vor 1/Vor/3/3.c)
# target_link_libraries(1.3-Vor m)
# add_executable(1.4p-Vor 1/Vor/4p/4p.c
#         1/Vor/4p/4p.h)
# add_executable(1.4a-Vor 1/Vor/4a/4a.c
#         1/Vor/4a/4a.h)
# add_executable(1.5a-Vor 1/Vor/5a/5a.c
#         1/Vor/5a/5a.h)
# add_executable(1.5p-Vor 1/Vor/5p/5p.c
#         1/Vor/5p/5p.h)

# add_executable(1.2.1-Mans 1/Mans/2.1/2.1.c)
# add_executable(1.2.2-Mans 1/Mans/2.2/2.2.c)
# add_executable(1.3-Mans 1/Mans/3/3.c)
# target_link_libraries(1.3-Mans m)
# add_executable(1.4a-Mans 1/Mans/4a/4a.c)
# add_executable(1.4p-Mans 1/Mans/4p/4p.c)
# add_executable(1.5a-Mans 1/Mans/5a/5a.c)
# target_link_libraries(1.5a-Mans m)
# add_executable(1.5p-Mans 1/Mans/5p/5p.c)
# target_link_libraries(1.5p-Mans m)

#############################################

# 1 course / 2 semester

#add_executable(2.1 "2/2.1/master.c" 2/2.1/data.h )
#add_executable(2.1tn "2/2.1t/main.c" 2/2.1t/data.h
#        4/13/Inductance/test13.cpp)
#add_executable(2.1ch "2/2.1ch/index.c" 2/2.1ch/struct.h)
#add_executable(2.1g "2/2.1g/main.c" 2/2.1g/programs.h)
#add_executable(2_lab1_1_1 "2/Lab1/1.1.c")
#add_executable(2_lab1_1_2 "2/Lab1/1.2.c")
#add_executable(2_lab1_1_3 "2/Lab1/1.3.c")
#add_executable(2_lab1_2_1 "2/Lab1/2.1.c")
#add_executable(2_lab1_2_2 "2/Lab1/2.2.c")
#add_executable(2_lab1_2_3 "2/Lab1/2.3.c")
#add_executable(2_lab1_2_4 "2/Lab1/2.4.c")
#add_executable(2_lab1_3_1 "2/Lab1/3.1.c")
#add_executable(2_lab1_3_2 "2/Lab1/3.2.c")
#add_executable(2_lab1_3_2 "2/Lab1/3.2.c")

add_executable(2_1 "2/1/train.c")
add_executable(2_1_test "2/1/train_test.c" "2/1/train.c")
target_compile_definitions(2_1_test PRIVATE TEST_BUILD=1)
add_test(NAME 2_1_test COMMAND 2_1_test)

add_executable(2_5 "2/5/coin.c")
add_executable(2_5_test "2/5/coin_test.c" "2/5/coin.c")
target_compile_definitions(2_5_test PRIVATE TEST_BUILD=1)
add_test(NAME 2_5_test COMMAND 2_5_test)

add_executable(2_9_ch "2/9/main.c")

add_executable(2_31 "2/31/circle.c")
# Ensure TEST_BUILD is defined for the test target
add_executable(2_31_test "2/31/circle_test.c" "2/31/circle.c")
target_compile_definitions(2_31_test PRIVATE TEST_BUILD=1)
target_link_libraries(2_31_test m)
add_test(NAME 2_31_test COMMAND 2_31_test)

#############################################

# 2 course / 1 semester

#add_executable(3_my_1 "3/3_my-31/v0.1/3_my_v0.1.cpp")
#add_executable(3_my_2 "3/3_my-31/v0.2/3_my_v0.2.cpp" 3/3_my-31/v0.2/application.h)
#add_executable(attempt "3/3_my-31/att/main.cpp" 3/3_my-31/att/header.h)
# add_executable(3_SEM_MY_31_FINAL 3/3_my-31/FINAL/main.cpp
#         3/3_my-31/FINAL/vector.cpp
#         3/3_my-31/FINAL/application.cpp)
##add_executable(ROMYCH-37 "3/ROMYCH-37/replacement.cpp")
#add_executable(TESTfile "2/Lab1/test.c")

##add_executable(gor-7 3/gor-7/sorting.cpp
##        3/gor-7/vector.cpp
##        3/gor-7/application.cpp)
##add_executable(TEST 3/test.cpp)

############ GOING ALL OUT

## 1

# add_executable(3_1
#         3/1/main.cpp
#         3/1/application.cpp
# )

# add_executable(3_2
#         3/2/main.cpp
#         3/2/application.cpp
#         3/2/application.cpp
#         3/2/application.h
#         3/2/handler.cpp
#         3/2/handler.h
# )

# add_executable(3_6 
#         3/6/main.cpp
#         3/6/application.cpp
#         3/6/app_begin.cpp
#         3/6/app_process.cpp
#         3/6/app_end.cpp
#         3/6/application.h
#         3/6/vector.cpp
#         3/6/vector.h)

# add_executable(3_27 3/27/main.cpp
#         3/27/application.cpp
#         3/27/application.h
#         3/27/cartesian.cpp
#         3/27/cartesian.h)

# add_executable(3_27_COMMENTS 3/27/COMMENTS/main.cpp
#         3/27/COMMENTS/application.cpp
#         3/27/COMMENTS/application.h
#         3/27/COMMENTS/cartesian.cpp
#         3/27/COMMENTS/cartesian.h)

# add_executable(3_41_Kornilov 3/41-23-Kornilov/main.cpp
#         3/41-23-Kornilov/application.cpp
#         3/41-23-Kornilov/application.h
#         3/41-23-Kornilov/vector_handle.h
#         3/41-23-Kornilov/vector_handle.cpp)


#############################################

# 2 course / 2 semester

### My - 28
enable_testing()
add_subdirectory(googletest)

# add_executable(4_SEM_Mainline_V3
#         4/My/Inductance_V3/main.cpp
#         4/My/Inductance_V3/application.cpp
#         4/My/Inductance_V3/algo.cpp)

# add_executable(4_SEM_Mainline_V3_test
#         4/My/Inductance_V3/application.cpp
#         4/My/Inductance_V3/algo.cpp
#         4/My/Inductance_V3/test.cpp)
# target_link_libraries(4_SEM_Mainline_V3_test gtest_main gmock_main)


# THIS BELOW WORKS!
# add_executable(4_SEM_Mainline_V2_test
#         4/My/Inductance_V2/application.cpp
#         4/My/Inductance_V2/vector.cpp
#         4/My/Inductance_V2/test.cpp)
# target_link_libraries(4_SEM_Mainline_V2_test gtest_main gmock_main)

#add_executable(4_SEM_Mainline_Callback_V1
#        4/My/Callback/V1/main.cpp
#        4/My/Callback/V1/application.cpp
#        4/My/Callback/V1/vector.cpp
#        4/My/Callback/V1/vector.h)

#add_executable(4_SEM_Mainline_Callback_V2
#        4/My/Callback/V2/main.cpp
#        4/My/Callback/V2/application.cpp
#        4/My/Callback/V2/vector.cpp
#        4/My/Callback/V2/vector.h)

# add_executable(4_SEM_Mainline_Callback_V3
#         4/My/Callback/V3/main.cpp
#         4/My/Callback/V3/application.cpp
#         4/My/Callback/V3/algo.cpp)


##add_executable(4_SEM_Mainline_Callback_V1_test
##        4/My/Callback/V1/application.cpp
##        4/My/Callback/V1/vector.cpp
##        4/My/Callback/V1/vector.h
##        4/My/Callback/V1/test.cpp)
##target_link_libraries(4_SEM_Mainline_Callback_V1_test gtest_main gmock_main)

# add_executable(4_SEM_Mainline_Callback_V2_test
#         4/My/Callback/V2/application.cpp
#         4/My/Callback/V2/vector.cpp
#         4/My/Callback/V2/test.cpp)
# target_link_libraries(4_SEM_Mainline_Callback_V2_test gtest_main gmock_main)


####### 1
# add_executable(4_SEM_1_Mainline_Inductance_V3
#         4/1/Inductance/V3/main.cpp
#         4/1/Inductance/V3/application.cpp)

# add_executable(4_SEM_1_Mainline_Callback_V3
#         4/1/Callback/V3/main.cpp
#         4/1/Callback/V3/application.cpp)

####### 10
# add_executable(4_SEM_10_Mainline_Inductance_V2
#         4/10/Inductance/V2/main.cpp
#         4/10/Inductance/V2/application.cpp)

# add_executable(4_SEM_10_Mainline_Callback_V2
#         4/10/callback/V2/main.cpp
#         4/10/callback/V2/application.cpp
#         4_Practice_1/My/main.c)

####### 13
#add_executable(4_SEM_13_TEST 4/13/Inductance/V1/test13.cpp)
#add_executable(4_SEM_13_Mainline_Induction_V1
#        4/13/Inductance/V1/main.cpp
#        4/13/Inductance/V1/application.cpp
#        4/13/Inductance/V1/vector.cpp)

# add_executable(4_SEM_13_Mainline_Induction_V2
#         4/13/Inductance/V2/main.cpp
#         4/13/Inductance/V2/application.cpp)

#add_executable(4_SEM_13_Mainline_Callback_V1
#        4/13/Callback/V1/main.cpp
#        4/13/Callback/V1/application.cpp
#        4/13/Callback/V1/vector.cpp)

# add_executable(4_SEM_13_Mainline_Callback_V2
#         4/13/Callback/V2/main.cpp
#         4/13/Callback/V2/application.cpp
# )

####### 18

#add_executable(4_SEM_18_Mainline_Callback
#        4/18/Callback/main.cpp
#        4/18/Callback/application.cpp)
#
#add_executable(4_SEM_18_Mainline_Inductance
#        4/18/Inductance/main.cpp
#        4/18/Inductance/application.cpp)


####### 41
#add_executable(4_SEM_41_Mainline
#        4/41/Inductance/V1/main.cpp
#        4/41/Inductance/V1/application.cpp
#        4/41/Inductance/V1/vector.cpp)
#add_executable(4_SEM_41_2_Mainline
#        4/41/Inductance/V3/main.cpp
#        4/41/Inductance/V3/application.cpp
#        4/41/Inductance/V3/vector.cpp)
#add_executable(4_SEM_41_3_Mainline
#        4/41/Inductance/V3/main.cpp
#        4/41/Inductance/V3/application.cpp)

#add_executable(4_SEM_41_Callback_Mainline
#        4/41/Callback/V3/main.cpp
#        4/41/Callback/V3/application.cpp
#        4/41/Callback/V3/vector.cpp)

#add_executable(4_SEM_41_Callback_V3_Mainline
#        4/41/Callback/V3/main.cpp
#        4/41/Callback/V3/application.cpp)

###### 43
#add_executable(4_SEM_43_Inductance_V1
#        4/43/Inductance/V1/main.cpp
#        4/43/Inductance/V1/application.cpp)
#
#add_executable(4_SEM_43_Callback_V1
#        4/43/Callback/V1/main.cpp
#        4/43/Callback/V1/application.cpp)
#
#add_executable(4_SEM_21_IND
#        4/21/Induction/application.cpp
#        4/21/Induction/application.h
#        4/21/Induction/main.cpp
#        4/21/Induction/check_neighbour.cpp
#        4/21/Induction/check_neighbour.h)
#add_executable(4_SEM_21_CB
#        4/21/Callback/application.cpp
#        4/21/Callback/application.h
#        4/21/Callback/main.cpp
#        4/21/Callback/check_neighbour.cpp
#        4/21/Callback/check_neighbour.h)
#
#add_executable(KAL
#        4/My/Inductance_V4/SIDOR_GNIDA/main.cpp
#        4/My/Inductance_V4/SIDOR_GNIDA/application.cpp
#        4/My/Inductance_V4/SIDOR_GNIDA/application.h)
#
#add_executable(KAL_KALBACK
#        4/My/Inductance_V4/SIDOR_GNIDA/EBAL_EGO_MERTVUJU_MAMAWU/main.cpp
#        4/My/Inductance_V4/SIDOR_GNIDA/EBAL_EGO_MERTVUJU_MAMAWU/application.cpp
#        4/My/Inductance_V4/SIDOR_GNIDA/EBAL_EGO_MERTVUJU_MAMAWU/application.h)
#
#################################################################################################################

#PRACTICE 1 - SEM 2

#add_executable(4_SEM_PRAC_1_MY
#        4_Practice_1/My/main.c
#        4_Practice_1/My/application.c
#        4_Practice_1/My/application.h
#        4_Practice_1/My/handler.c
#        4_Practice_1/My/handler.h)
#add_executable(4_SEM_PRAC_1_MY_LAB 4_Practice_1/My/LAB.c)
#add_executable(4_SEM_PRAC_1_MY_LAB2 4_Practice_1/My/LAB2.c)
#
#add_executable(library_practica 4_Practice_1/Roma/main.c
#        4_Practice_1/Roma/library.c
#        4_Practice_1/Roma/application.c
#        4_Practice_1/Roma/application.h)


####################

###MTUCI

add_executable(4_MTUCI_TERMINAL_TEST 4/MTUCI/14/terminal_test.c)
add_executable(4_MTUCI_TASK 4/MTUCI/14/task.c)