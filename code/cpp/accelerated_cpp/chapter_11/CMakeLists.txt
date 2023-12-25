
include_directories(.)
include_directories(../common)

add_executable(ch_11 chapter_11.cpp)
target_link_libraries(ch_11 common)