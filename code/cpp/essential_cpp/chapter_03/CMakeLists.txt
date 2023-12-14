
include_directories(.)

add_library(common_03 SHARED common.cpp)

add_executable(ch_3_1 "ch_3_1.cpp")
target_link_libraries(ch_3_1 common_03)

add_executable(ch_3_2 "ch_3_2.cpp")
target_link_libraries(ch_3_2 common_03)

add_executable(ch_3_6 "ch_3_6.cpp")
target_link_libraries(ch_3_6 common_03)

add_executable(ch_3_9 "ch_3_9.cpp")
target_link_libraries(ch_3_9 common_03)

add_executable(ch_3_10 "ch_3_10.cpp")
target_link_libraries(ch_3_10 common_03)

add_executable(ex_3_1 "ex_3_1.cpp")
target_link_libraries(ex_3_1 common_03)

add_executable(ex_3_2 "ex_3_2.cpp")
target_link_libraries(ex_3_2 common_03)

add_executable(ex_3_3 "ex_3_3.cpp")
target_link_libraries(ex_3_3 common_03)

add_executable(ex_3_4 "ex_3_4.cpp")
target_link_libraries(ex_3_4 common_03)
