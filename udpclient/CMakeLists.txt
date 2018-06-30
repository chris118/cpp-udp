cmake_minimum_required(VERSION 3.5)
project(udpclient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(udpclient ${SOURCE_FILES})