
include_directories(.)
include_directories(../common)

add_library(grammar SHARED grammar.cpp)
target_link_libraries(grammar common)

add_executable(ch_07 chapter_07.cpp)
target_link_libraries(ch_07 grammar)