cmake_minimum_required(VERSION 3.0.0)
project(blp VERSION 0.1.0)

aux_source_directory(chapter_03 LIB_SRC)
aux_source_directory(chapter_04 LIB_SRC)
aux_source_directory(chapter_07 LIB_SRC)
list(REMOVE_ITEM LIB_SRC "main.c")

add_library(blp SHARED ${LIB_SRC})
set_target_properties(blp PROPERTIES VERSION "0.0.1")

add_executable(main "main.c")
target_link_libraries(main blp m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
