
include_directories(.)

#aux_source_directory添加目录下所有文件
set(CLASS_LIST  mat.cpp
                book.cpp
                audio_book.cpp)

set(OBJECT_LIST num_sequence_ver1.cpp
                fibonacci_ver1.cpp
                num_sequence_ver2.cpp
                fibonacci_ver2.cpp
                stack.cpp
                lifo_stack.cpp)

add_library(mat SHARED ${CLASS_LIST})
add_library(object SHARED ${OBJECT_LIST})

add_executable(ch_5_2 "ch_5_2.cpp")
target_link_libraries(ch_5_2 mat)

add_executable(ch_5_5 "ch_5_5.cpp")
target_link_libraries(ch_5_5 object)

add_executable(ch_5_6 "ch_5_6.cpp")
target_link_libraries(ch_5_6 object)

add_executable(ch_5_8 "ch_5_8.cpp")
target_link_libraries(ch_5_8 object)

add_executable(ch_5_9 "ch_5_9.cpp")
target_link_libraries(ch_5_9 object)

add_executable(ch_5_10 "ch_5_10.cpp")
target_link_libraries(ch_5_10 object)

add_executable(ex_5_2 "ex_5_2.cpp")
target_link_libraries(ex_5_2 object)
