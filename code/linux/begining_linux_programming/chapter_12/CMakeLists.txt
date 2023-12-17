
include_directories(.)

add_definitions(-D_REENTRANT)

add_executable(thread1 "thread1.c")
target_link_libraries(thread1 pthread)

add_executable(thread2 "thread2.c")
target_link_libraries(thread2 pthread)

add_executable(thread3 "thread3.c")
target_link_libraries(thread3 pthread)

add_executable(thread4 "thread4.c")
target_link_libraries(thread4 pthread)

add_executable(thread5 "thread5.c")
target_link_libraries(thread5 pthread)

add_executable(thread6 "thread6.c")
target_link_libraries(thread6 pthread)

add_executable(thread7 "thread7.c")
target_link_libraries(thread7 pthread)

add_executable(thread8 "thread8.c")
target_link_libraries(thread8 pthread)