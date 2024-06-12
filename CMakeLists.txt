cmake_minimum_required(VERSION 3.23)
project(NNTU)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

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
#############################################

# 2 course / 1 semester

#add_executable(3_my_1 "3/3_my/v0.1/3_my_v0.1.cpp")
#add_executable(3_my_2 "3/3_my/v0.2/3_my_v0.2.cpp" 3/3_my/v0.2/application.h)
#add_executable(attempt "3/3_my/att/main.cpp" 3/3_my/att/header.h)
##add_executable(solve "3/3_my/solve/main.cpp"
##        3/3_my/solve/processing.cpp
##        3/3_my/solve/application.cpp)
##add_executable(ROMYCH "3/ROMYCH/replacement.cpp")
#add_executable(3_SEM_Mainline
#        "3/3.14DOR/main.cpp"
#        3/3.14DOR/application.cpp
#        3/3.14DOR/vector.cpp)
#add_executable(TESTfile "2/Lab1/test.c")

##add_executable(gor 3/gor/sorting.cpp
##        3/gor/vector.cpp
##        3/gor/application.cpp)
##add_executable(TEST 3/test.cpp)

#############################################

# 2 course / 2 semester

### My - 28
enable_testing()
add_subdirectory(googletest)

add_executable(4_SEM_Mainline_V3
        4/My/Inductance_V3/main.cpp
        4/My/Inductance_V3/application.cpp
        4/My/Inductance_V3/algo.cpp)

add_executable(4_SEM_Mainline_V3_test
        4/My/Inductance_V3/application.cpp
        4/My/Inductance_V3/algo.cpp
        4/My/Inductance_V3/test.cpp)
target_link_libraries(4_SEM_Mainline_V3_test gtest_main gmock_main)


#add_executable(4_SEM_Mainline_Callback_V1
#        4/My/Callback/V1/main.cpp
#        4/My/Callback/V1/application.cpp
#        4/My/Callback/V1/vector.cpp
#        4/My/Callback/V1/vector.h)

add_executable(4_SEM_Mainline_Callback_V2
        4/My/Callback/V2/main.cpp
        4/My/Callback/V2/application.cpp
        4/My/Callback/V2/vector.cpp
        4/My/Callback/V2/vector.h)

add_executable(4_SEM_Mainline_Callback_V3
        4/My/Callback/V3/main.cpp
        4/My/Callback/V3/application.cpp
        4/My/Callback/V3/algo.cpp)


##add_executable(4_SEM_Mainline_Callback_V1_test
##        4/My/Callback/V1/application.cpp
##        4/My/Callback/V1/vector.cpp
##        4/My/Callback/V1/vector.h
##        4/My/Callback/V1/test.cpp)
##target_link_libraries(4_SEM_Mainline_Callback_V1_test gtest_main gmock_main)

add_executable(4_SEM_Mainline_Callback_V2_test
        4/My/Callback/V2/application.cpp
        4/My/Callback/V2/vector.cpp
        4/My/Callback/V2/test.cpp)
target_link_libraries(4_SEM_Mainline_Callback_V2_test gtest_main gmock_main)


####### 1
add_executable(4_SEM_1_Mainline_Inductance_V3
        4/1/Inductance/V3/main.cpp
        4/1/Inductance/V3/application.cpp)

add_executable(4_SEM_1_Mainline_Callback_V3
        4/1/Callback/V3/main.cpp
        4/1/Callback/V3/application.cpp)

####### 10
add_executable(4_SEM_10_Mainline_Inductance_V2
        4/10/Inductance/V2/main.cpp
        4/10/Inductance/V2/application.cpp)

add_executable(4_SEM_10_Mainline_Callback_V2
        4/10/callback/V2/main.cpp
        4/10/callback/V2/application.cpp)

####### 13
#add_executable(4_SEM_13_TEST 4/13/Inductance/V1/test13.cpp)
#add_executable(4_SEM_13_Mainline_Induction_V1
#        4/13/Inductance/V1/main.cpp
#        4/13/Inductance/V1/application.cpp
#        4/13/Inductance/V1/vector.cpp)

add_executable(4_SEM_13_Mainline_Induction_V2
        4/13/Inductance/V2/main.cpp
        4/13/Inductance/V2/application.cpp)

#add_executable(4_SEM_13_Mainline_Callback_V1
#        4/13/Callback/V1/main.cpp
#        4/13/Callback/V1/application.cpp
#        4/13/Callback/V1/vector.cpp)

add_executable(4_SEM_13_Mainline_Callback_V2
        4/13/Callback/V2/main.cpp
        4/13/Callback/V2/application.cpp
)

####### 18

add_executable(4_SEM_18_Mainline_Callback
        4/18/Callback/main.cpp
        4/18/Callback/application.cpp)

add_executable(4_SEM_18_Mainline_Inductance
        4/18/Inductance/main.cpp
        4/18/Inductance/application.cpp)


####### 41
#add_executable(4_SEM_41_Mainline
#        4/41/Inductance/V1/main.cpp
#        4/41/Inductance/V1/application.cpp
#        4/41/Inductance/V1/vector.cpp)
#add_executable(4_SEM_41_2_Mainline
#        4/41/Inductance/V3/main.cpp
#        4/41/Inductance/V3/application.cpp
#        4/41/Inductance/V3/vector.cpp)
add_executable(4_SEM_41_3_Mainline
        4/41/Inductance/V3/main.cpp
        4/41/Inductance/V3/application.cpp)

#add_executable(4_SEM_41_Callback_Mainline
#        4/41/Callback/V3/main.cpp
#        4/41/Callback/V3/application.cpp
#        4/41/Callback/V3/vector.cpp)

add_executable(4_SEM_41_Callback_V3_Mainline
        4/41/Callback/V3/main.cpp
        4/41/Callback/V3/application.cpp)

###### 43
add_executable(4_SEM_43_Inductance_V1
        4/43/Inductance/V1/main.cpp
        4/43/Inductance/V1/application.cpp)

add_executable(4_SEM_43_Callback_V1
        4/43/Callback/V1/main.cpp
        4/43/Callback/V1/application.cpp)