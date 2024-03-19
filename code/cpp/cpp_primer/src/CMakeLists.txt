
#全局设置,最好设置在总项目CMakeLists.txt中
#set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)

#项目级别设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_executable(ch_02 chapter_02.cpp)

