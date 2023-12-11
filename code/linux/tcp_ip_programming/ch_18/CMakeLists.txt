
include_directories(.)

add_definitions(-D_REENTRANT)
add_executable(chat_server "chat_server.c")
target_link_libraries(chat_server pthread)
add_executable(chat_client "chat_client.c")
target_link_libraries(chat_client pthread)