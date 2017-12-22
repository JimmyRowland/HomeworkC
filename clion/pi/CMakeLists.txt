cmake_minimum_required(VERSION 3.8)
project(pi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp my_pi_approximator.h my_pi_approximator.cpp)
add_executable(pi ${SOURCE_FILES})