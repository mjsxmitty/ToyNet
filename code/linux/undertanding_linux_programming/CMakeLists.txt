cmake_minimum_required(VERSION 3.0.0)
project(ulp VERSION 0.1.0)

include_directories(.)
include_directories(common)
include_directories(example)

aux_source_directory(. LIB_SRC)
aux_source_directory(example LIB_SRC)
aux_source_directory(common LIB_SRC)

add_executable(ulp "main.c" ${LIB_SRC})
target_link_libraries(ulp curses)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
