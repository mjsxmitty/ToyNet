
include_directories(.)

set(COMMON_LIST str.cpp
				grade.cpp
				median.cpp
				student_info.cpp
				extract_fails.cpp)
				
add_library(common ${COMMON_LIST})


