
set(COMMON_LIST grade.cpp
				median.cpp
				student_info.cpp)

add_library(common_04 ${COMMON_LIST})

add_executable(ch_04 chapter_04.cpp)
target_link_libraries(ch_04 common_04)

