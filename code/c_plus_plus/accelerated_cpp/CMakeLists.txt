cmake_minimum_required(VERSION 3.0.0)
project(accelerated_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(accelerated_cpp 
                main.cpp
                chapter02/ch_2.hpp
                chapter02/chapter_02.h chapter02/chapter_02.cpp
                chapter03/ch_3.hpp
                chapter03/chapter_03.h chapter03/chapter_03.cpp
                chapter04/chapter04_student_info.h chapter04/chapter04_student_info.cpp
                chapter04/chapter04_grade.h chapter04/chapter04_grade.cpp
                chapter04/chapter04_median.h chapter04/chapter04_median.cpp
                chapter05/chapter05_extract_fails.h chapter05/chapter05_extract_fails.cpp
                chapter05/chapter05_str.h chapter05/chapter05_str.cpp
                chapter06/chapter06_str.h chapter06/chapter06_str.cpp
                chapter06/chapter06_student.h chapter06/chapter06_student.cpp
                chapter11/chapter11_vec.h chapter11/chapter11_vec.cpp
                chapter12/chapter12_str.h chapter12/chapter12_str.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
