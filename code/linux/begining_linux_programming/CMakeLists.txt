cmake_minimum_required(VERSION 3.0.0)
project(begining_linux_programming VERSION 0.1.0)

aux_source_directory(chapter_03 SRC)
aux_source_directory(chapter_04 SRC)
aux_source_directory(chapter_07 SRC)
aux_source_directory(chapter_11 SRC)

add_definitions(-D_REENTRANT) 
add_executable(blp "main.c" ${SRC})
target_link_libraries(blp m pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
