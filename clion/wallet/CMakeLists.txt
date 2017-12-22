cmake_minimum_required(VERSION 3.8)
project(wallet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main1.cpp Wallet1.cpp)
add_executable(wallet ${SOURCE_FILES})