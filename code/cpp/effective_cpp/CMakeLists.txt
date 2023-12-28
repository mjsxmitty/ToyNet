cmake_minimum_required(VERSION 3.16)

project(effective_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(item_02)
add_subdirectory(item_03)
add_subdirectory(item_04)
