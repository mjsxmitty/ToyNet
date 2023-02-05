cmake_minimum_required(VERSION 3.5)

project(cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp main.cpp
                   1/ch_1.hpp
                   1/chapter_01.h 1/chapter_01.cpp
                   2/ch_2.hpp
                   2/chapter_02.h 2/chapter_02.cpp
                   3/ch_3.hpp
                   3/chapter_03.h 3/chapter_03.cpp
                   4/ch_4.hpp
                   4/chapter_04.h 4/chapter_04.cpp
                   5/ch_5.hpp
                   5/chapter_05.h 5/chapter_05.cpp
                   6/ch_6.hpp
                   6/chapter_06.h 6/chapter_06.cpp
                   7/ch_7.hpp
                   7/chapter_07.h 7/chapter_07.cpp
                   8/ch_8.hpp
                   8/chapter_08.h 8/chapter_08.cpp
                   9/ch_9.hpp
                   9/chapter_09.h 9/chapter_09.cpp
                   10/ch_10.hpp
                   10/chapter_10.h 10/chapter_10.cpp
                   11/ch_11.hpp
                   11/chapter_11.h 11/chapter_11.cpp
                   12/ch_12.hpp
                   12/chapter_12.h 12/chapter_12.cpp)
