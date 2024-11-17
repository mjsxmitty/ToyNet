
#项目级别设置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 创建动态库
add_library(header SHARED header.cpp)

#target_include_directories(header PUBLIC ${CMAKE_CURRENT_DIR})