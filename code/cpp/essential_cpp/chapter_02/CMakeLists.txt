
include_directories(.)

add_library(common_02 SHARED common.cpp)

add_executable(ch_2_1 "ch_2_1.cpp")
target_link_libraries(ch_2_1 common_02)

add_executable(ch_2_3 "ch_2_3.cpp")
target_link_libraries(ch_2_3 common_02)

add_executable(ch_2_4 "ch_2_4.cpp")
target_link_libraries(ch_2_4 common_02)

add_executable(hw_2_6 "hw_2_6.cpp")
target_link_libraries(hw_2_6 common_02)
