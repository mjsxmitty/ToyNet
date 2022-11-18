cmake_minimum_required(VERSION 3.5.0)
project(lab VERSION 0.1.0)

add_executable(lab
                main.cpp
                gz_speech_manager.h gz_speech_manager.cpp
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

