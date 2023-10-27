cmake_minimum_required(VERSION 3.0.0)
project(ulp VERSION 0.1.0)

include_directories(.)
include_directories(common)

aux_source_directory(common LIB_SRC)
list(REMOVE_ITEM LIB_SRC "main.c")

add_library(ulp SHARED ${LIB_SRC})
set_target_properties(ulp PROPERTIES VERSION "0.0.1")

add_executable(main "main.c")
target_link_libraries(main ulp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
