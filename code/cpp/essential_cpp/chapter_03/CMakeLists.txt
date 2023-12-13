
include_directories(.)

add_library(common_03 SHARED common.cpp)

add_executable(ch_3_1 "ch_3_1.cpp")
target_link_libraries(ch_3_1 common_03)

add_executable(ch_3_2 "ch_3_2.cpp")
target_link_libraries(ch_3_2 common_03)
