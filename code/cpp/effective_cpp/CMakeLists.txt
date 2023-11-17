cmake_minimum_required(VERSION 3.5)

project(effective_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(effective_cpp main.cpp
                             item/item_01.h item/item_01.cpp)
