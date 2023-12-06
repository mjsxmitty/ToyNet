cmake_minimum_required(VERSION 3.0.0)
project(tcp_ip VERSION 0.1.0)

add_subdirectory(ch_01)
add_subdirectory(ch_02)
add_subdirectory(ch_04)
add_subdirectory(ch_06)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

