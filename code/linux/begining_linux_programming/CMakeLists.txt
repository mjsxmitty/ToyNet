cmake_minimum_required(VERSION 3.0.0)
project(begining_linux_programming VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
add_compile_options(-std=c++11 -pthread -g  -ggdb -O0 -Wall -fstack-protector-all -march=native -fnon-call-exceptions)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -core")
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(chapter_07)