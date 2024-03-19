cmake_minimum_required(VERSION 3.0.0)
project(cpp_primer LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)     #强制使用新特性
set(CMAKE_VERBOSE_MAKEFILE ON)          #输出详细的编译和链接信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")
set(CMAKE_BUILD_TYPE "Debug")

#子目录编译
add_subdirectory(src)

#打包
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#信息输出(用于测试)
#message("the value:" ${PROJECT_SOURCE_DIR})
