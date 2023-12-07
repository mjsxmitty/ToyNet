
include_directories(.)

add_executable(udp_echo_server "uecho_server.c")
add_executable(udp_echo_client "uecho_client.c")
add_executable(udp_con_echo_server "uecho_connect_server.c")
add_executable(udp_con_echo_client "uecho_connect_client.c")

