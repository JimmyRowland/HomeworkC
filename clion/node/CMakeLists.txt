cmake_minimum_required(VERSION 3.8)
project(node)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES corrupt/main.cpp)
add_executable(node ${SOURCE_FILES})