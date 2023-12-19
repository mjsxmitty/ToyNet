
include_directories(.)

set(COMMOM "sock.c")
add_library(common SHARED ${COMMOM})

add_executable(date_server "date_server.c")
target_link_libraries(date_server common)
