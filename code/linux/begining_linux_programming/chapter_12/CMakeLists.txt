
include_directories(.)

add_definitions(-D_REENTRANT)

add_executable(thread1 "thread1.c")
target_link_libraries(thread1 pthread)

add_executable(thread2 "thread2.c")
target_link_libraries(thread2 pthread)

add_executable(thread3 "thread3.c")
target_link_libraries(thread3 pthread)