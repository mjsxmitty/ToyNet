
include_directories(.)
include_directories(../common)

add_library(student SHARED student_info.cpp)
target_link_libraries(student common)

#add_executable(ch_07 chapter_07.cpp)
#target_link_libraries(ch_07 grammar)