

add_library(test SHARED test.cpp)

add_executable(item_02 item_02.cpp)
target_link_libraries(item_02 test)
