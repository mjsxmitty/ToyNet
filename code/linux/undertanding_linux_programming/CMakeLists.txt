cmake_minimum_required(VERSION 3.0.0)
project(uulp VERSION 0.1.0)

add_executable(uulp 
                main.c
                chapter_02/ch_02.h
                chapter_02/cp.c
                chapter_02/who.c
                chapter_03/ch_03.h
                chapter_03/ls.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
