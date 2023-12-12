
include_directories(.)

add_library(chapter_02 SHARED chapter_02.cpp)

add_executable(ch_2_1 "ch_2_1.cpp")
target_link_libraries(ch_2_1 chapter_02)
