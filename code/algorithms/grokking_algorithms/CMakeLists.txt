
cmake_minimum_required(VERSION 3.0.0)
project(grokking_algorithms VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(grokking_algorithms
               main.c
               01/01.h 01/01.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_C_FLAGS_DEBUG "-g -D_DEBUG -O0")
include(CPack)