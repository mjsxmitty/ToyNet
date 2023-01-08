cmake_minimum_required(VERSION 3.0.0)
project(ulp VERSION 0.1.0)

add_executable(ulp 
                main.c
                chapter_01/ch_01.h chapter_01/ch_01.c
                chapter_01/gz_more.h chapter_01/gz_more.c
                chapter_02/ch_02.h
                chapter_02/cp.c
                chapter_02/who.c
                chapter_03/ch_03.h
                chapter_03/ls.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
