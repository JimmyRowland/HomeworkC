cmake_minimum_required(VERSION 3.8)
project(inventory_system)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp inventory.h inventory.cpp)
add_executable(inventory_system ${SOURCE_FILES})