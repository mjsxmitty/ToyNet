cmake_minimum_required(VERSION 3.0.0)
project(ulp VERSION 0.1.0)

add_executable(ulp 
                main.c
                chapter_01/ch_01.h chapter_01/ch_01.c
                chapter_01/more.h chapter_01/more.c
                chapter_02/ch_02.h chapter_02/ch_02.c
                chapter_02/who1.h chapter_02/who1.c
                chapter_02/cp.h chapter_02/cp.c
                chapter_02/who2.h chapter_02/who2.c
                chapter_03/ch_03.h chapter_03/ch_03.c
                chapter_03/ls.h chapter_03/ls.c
                chapter_04/ch_04.h chapter_04/ch_04.c
                chapter_04/pwd.h chapter_04/pwd.c
                chapter_05/ch_05.h chapter_05/ch_05.c
                chapter_05/play_again.h chapter_05/play_again.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
