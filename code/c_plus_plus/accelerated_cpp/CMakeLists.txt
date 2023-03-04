cmake_minimum_required(VERSION 3.0.0)
project(accelerated_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(accelerated 
                main.cpp
                chapter_02/ch_02.hpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_03/ch_03.hpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp
                chapter_04/ch_04.hpp
                chapter_04/chapter_04.h chapter_04/chapter_04.cpp
                chapter_04/student_info.h chapter_04/student_info.cpp
                chapter_04/grade.h chapter_04/grade.cpp
                chapter_04/median.h chapter_04/median.cpp
                chapter_05/extract_fails.h chapter_05/extract_fails.cpp
                chapter_05/str.h chapter_05/str.cpp
                chapter_06/ch_06.hpp
                chapter_06/str.h chapter_06/str.cpp
                chapter_06/student.h chapter_06/student.cpp
                chapter_07/ch_07.hpp
                chapter_07/chapter_07.h chapter_07/chapter_07.cpp
                chapter_09/student_info.h chapter_09/student_info.cpp
                chapter_11/vec.hpp
                chapter_12/str.h chapter_12/str.cpp
                chapter_13/core.h chapter_13/core.cpp
                chapter_13/grad.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
