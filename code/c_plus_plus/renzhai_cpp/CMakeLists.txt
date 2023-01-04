cmake_minimum_required(VERSION 3.5)

project(cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp main.cpp
                   1/ch_1.h 1/ch_1.cpp
                   2/ch_2.h 2/ch_2.cpp)
