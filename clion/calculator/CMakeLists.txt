cmake_minimum_required(VERSION 3.6)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Stack.h Calculator.h Exceptions.h)
add_executable(calculator ${SOURCE_FILES})