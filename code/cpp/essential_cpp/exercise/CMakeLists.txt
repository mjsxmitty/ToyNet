
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(ex_2_6 "ex_2_6.cpp")
target_link_libraries(ex_2_6 common)
target_include_directories(ex_2_6 PUBLIC ../common)

add_executable(ex_3_1 "ex_3_1.cpp")
target_link_libraries(ex_3_1 common)
target_include_directories(ex_3_1 PUBLIC ../common)

add_executable(ex_3_2 "ex_3_2.cpp")
target_link_libraries(ex_3_2 common)
target_include_directories(ex_3_2 PUBLIC ../common)

add_executable(ex_3_3 "ex_3_3.cpp")
target_link_libraries(ex_3_3 common)
target_include_directories(ex_3_3 PUBLIC ../common)

add_executable(ex_3_4 "ex_3_4.cpp")
target_link_libraries(ex_3_4 common)
target_include_directories(ex_3_4 PUBLIC ../common)

add_executable(ex_5_2 "ex_5_2.cpp")
target_link_libraries(ex_5_2 common)
target_include_directories(ex_5_2 PUBLIC ../common)