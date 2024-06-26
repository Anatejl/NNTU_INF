cmake_minimum_required(VERSION 3.23)
project(NNTU)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

add_executable(V4
main.cpp
application.cpp
        predicator.cpp)
add_executable(TEST TEST_NEW.cpp)
add_executable(KAL SIDOR_GNIDA/main.cpp
        SIDOR_GNIDA/application.cpp
        SIDOR_GNIDA/application.h)
