cmake_minimum_required(VERSION 3.23)
project(Inductor_Example)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

add_executable(MAIN "src/inductive_operation.cpp" src/small_rejector.cpp)