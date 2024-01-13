cmake_minimum_required(VERSION 3.16)

project(effective_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CMAKE_CXX_FLAGS} -g -O2 -Wall -ggdb")
set(CMAKE_BUILD_TYPE "Debug")

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#头文件路径
include_directories(include)
add_subdirectory(src)

#可执行文件路径,目录下所有文件
#AUX_SOURCE_DIRECTORY()
