
#target_link_libraries(chapter_02 common)
#target_include_directories(chapter_02 PUBLIC ../common)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(ch_02 chapter_02.cpp)
add_executable(ch_03 chapter_03.cpp)
