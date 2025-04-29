cmake_minimum_required(VERSION 3.16)
project(accelerated_cpp LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -ggdb -fPIC")
set(CMAKE_BUILD_TYPE "Debug")

find_program(CPPCHECK_EXE NAMES cppcheck)
if(CPPCHECK_EXE)
    add_custom_target(cppcheck_all
        COMMAND ${CPPCHECK_EXE}
            --enable=all
            --check-level=exhaustive
            --project=${CMAKE_BINARY_DIR}/compile_commands.json
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()

add_subdirectory(common)
add_subdirectory(demo)
add_subdirectory(homework)