
include_directories(.)
include_directories(../common)

add_executable(ch_12 chapter_12.cpp)
target_link_libraries(ch_12 common)