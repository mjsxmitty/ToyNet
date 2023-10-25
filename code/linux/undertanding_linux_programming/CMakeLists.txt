cmake_minimum_required(VERSION 3.0.0)
project(ulp VERSION 0.1.0)

include_directories(.)
include_directories(chapter_01)
include_directories(chapter_02)
include_directories(chapter_03)
include_directories(chapter_04)
include_directories(chapter_05)

aux_source_directory(chapter_01 LIB_SRC)
aux_source_directory(chapter_02 LIB_SRC)
aux_source_directory(chapter_03 LIB_SRC)
aux_source_directory(chapter_04 LIB_SRC)
aux_source_directory(chapter_05 LIB_SRC)
list(REMOVE_ITEM LIB_SRC "main.c")

add_library(ulp SHARED ${LIB_SRC})
set_target_properties(ulp PROPERTIES VERSION "0.0.1")

add_executable(main "main.c")
target_link_libraries(main ulp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
