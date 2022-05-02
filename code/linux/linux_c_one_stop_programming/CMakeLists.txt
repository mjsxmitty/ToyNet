cmake_minimum_required(VERSION 3.0.0)
project(one_stop VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(one_stop main.c
                chapter_28/chapter_28.h chapter_28/chapter_28.c
                chapter_29/chapter_29.h chapter_29/chapter_29.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
