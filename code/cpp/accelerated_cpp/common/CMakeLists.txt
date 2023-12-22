
include_directories(.)

set(COMMON_LIST grade.cpp
				median.cpp
				student_info.cpp)
				
add_library(common ${COMMON_LIST})


