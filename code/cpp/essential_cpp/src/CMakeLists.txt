
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(chapter_02 "chapter_02.cpp")
target_link_libraries(chapter_02 common)
target_include_directories(chapter_02 PUBLIC ../common)

add_executable(chapter_03 "chapter_03.cpp")
target_link_libraries(chapter_03 common)
target_include_directories(chapter_03 PUBLIC ../common)