cmake_minimum_required(VERSION 3.16)

project(essential_cpp LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -ggdb -fPIC")
set(CMAKE_BUILD_TYPE "Debug")

# 添加 Cppcheck 分析目标
add_custom_target(cppcheck_all
    COMMAND cppcheck
        --check-level=exhaustive
        --enable=all
        --project=${CMAKE_BINARY_DIR}/compile_commands.json
        --error-exitcode=1
    COMMENT "Running exhaustive Cppcheck analysis..."
)

add_subdirectory(common)
add_subdirectory(exercise)
add_subdirectory(demo)