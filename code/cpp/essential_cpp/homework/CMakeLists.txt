
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(hw_2_6 "hw_2_6.cpp")
target_link_libraries(hw_2_6 common)
target_include_directories(hw_2_6 PUBLIC ../common)