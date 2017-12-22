cmake_minimum_required(VERSION 3.8)
project(vector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.h vector.cpp)
add_executable(vector ${SOURCE_FILES})