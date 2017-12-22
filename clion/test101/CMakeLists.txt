cmake_minimum_required(VERSION 3.8)
project(test101)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FlashDrive.h FlashDrive.cpp)
add_executable(test101 ${SOURCE_FILES})