
include_directories(.)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(COMMON_LIST str.cpp         str_util.cpp
				grade.cpp
				median.cpp
				student_info.cpp
                                grammar.cpp
                                core.cpp
                                grad.cpp
                                picture_base.cpp
                                picture.cpp
                                string_picture.cpp
                                frame_picture.cpp)

add_library(common SHARED ${COMMON_LIST})
