
include_directories(.)

add_executable(word_count "word_count.c")
target_link_libraries(word_count pthread)