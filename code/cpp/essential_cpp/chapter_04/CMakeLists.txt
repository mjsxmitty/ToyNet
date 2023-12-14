
include_directories(.)

#aux_source_directory添加目录下所有文件
set(CLASS_LIST
            stack.cpp
            matrix.cpp
            triangular.cpp
            triangular_iterator.cpp
            num_sequence.cpp
            user_profile.cpp
    )

set(COMMON_LIST chapter_04.cpp)

add_library(class SHARED ${CLASS_LIST})
add_library(common_04 SHARED ${COMMON_LIST})

add_executable(ch_4_1 "ch_4_1.cpp")
target_link_libraries(ch_4_1 class)

add_executable(ch_4_3 "ch_4_3.cpp")
target_link_libraries(ch_4_3 class)

add_executable(ch_4_5 "ch_4_5.cpp")
target_link_libraries(ch_4_5 class)

add_executable(ch_4_7 "ch_4_7.cpp")
target_link_libraries(ch_4_7 class)

add_executable(ch_4_9 "ch_4_9.cpp")
target_link_libraries(ch_4_9 common_04)

add_executable(ch_4_10 "ch_4_10.cpp")
target_link_libraries(ch_4_10 class)

add_executable(ch_4_11 "ch_4_11.cpp")
target_link_libraries(ch_4_11 class)

add_executable(ex_4_4 "ex_4_4.cpp")
target_link_libraries(ex_4_4 class)
