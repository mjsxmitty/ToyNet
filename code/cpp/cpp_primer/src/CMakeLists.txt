
#全局设置,最好设置在总项目CMakeLists.txt中
#set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)

#项目级别设置
#message("binary dir:" ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
#target_include_directories(ch_02 PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_executable(ch_01 chapter_01.cpp)
add_executable(ch_02 chapter_02.cpp)
add_executable(ch_03 chapter_03.cpp)
