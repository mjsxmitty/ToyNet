
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(chapter_02 "chapter_02.cpp")
target_link_libraries(chapter_02 common)
target_include_directories(chapter_02 PUBLIC ../common)

add_executable(chapter_03 "chapter_03.cpp")
target_link_libraries(chapter_03 common)
target_include_directories(chapter_03 PUBLIC ../common)

add_executable(chapter_04 "chapter_04.cpp")
target_link_libraries(chapter_04 common)
target_include_directories(chapter_04 PUBLIC ../common)

add_executable(chapter_05 "chapter_05.cpp")
target_link_libraries(chapter_05 common)
target_include_directories(chapter_05 PUBLIC ../common)

add_executable(chapter_06 "chapter_06.cpp")
target_link_libraries(chapter_06 common)
target_include_directories(chapter_06 PUBLIC ../common)