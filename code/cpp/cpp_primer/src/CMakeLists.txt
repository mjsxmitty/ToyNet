
#项目级别设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
#全局设置,最好设置在总项目CMakeLists.txt中
#set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)

#头文件设置
include_directories(${PROJECT_SOURCE_DIR}/include)
#颗粒度更精细的设置
#target_include_directories(ch_02 PRIVATE   ${PROJECT_SOURCE_DIR}/include)

add_executable(ch_01 chapter_01.cpp)
add_executable(ch_02 chapter_02.cpp)
add_executable(ch_03 chapter_03.cpp)
