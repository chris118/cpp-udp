cmake_minimum_required(VERSION 3.5)
project(udpserver)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(udpserver ${SOURCE_FILES})