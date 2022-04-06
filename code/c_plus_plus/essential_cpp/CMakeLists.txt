cmake_minimum_required(VERSION 3.16)

project(essential_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(essential 
                main.cpp
                num_seq/num_seq.h num_seq/num_seq.cpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp)
