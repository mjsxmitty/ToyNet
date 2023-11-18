cmake_minimum_required(VERSION 3.5)

project(effective_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(item ITEM)
add_executable(effective_cpp main.cpp ${ITEM})
