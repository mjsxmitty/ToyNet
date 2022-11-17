cmake_minimum_required(VERSION 3.5.0)
project(lab VERSION 0.1.0)

add_executable(lab
                main.cpp
                gz_worker_manager.h gz_worker_manager.cpp
                gz_worker.h
                gz_employee.h gz_employee.cpp
                gz_manager.h gz_manager.cpp
                gz_boss.h gz_boss.cpp
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

