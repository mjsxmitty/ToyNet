cmake_minimum_required(VERSION 3.5)

project(video LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(video main.cpp
                          part_01/01/my_complex.h part_01/01/my_complex.cpp
                          part_01/01/my_string.h part_01/01/my_string.cpp
                          part_01/01/my_account.h part_01/01/my_account.cpp
                          part_01/01/my_queue.h part_01/01/my_queue.cpp
                          part_01/01/my_delegation.h part_01/01/my_delegation.cpp
                          part_01/01/my_inheritance.h part_01/01/my_inheritance.cpp
                          part_01/01/my_delegation_inheritance.h part_01/01/my_delegation_inheritance.cpp
                          part_01/01/my_prototype_model.h part_01/01/my_prototype_model.cpp part_01/01/test_prototype.h
                          part_01/02/my_conversion_func.h part_01/02/my_conversion_func.cpp
                          part_01/02/my_point_like.h part_01/02/my_point_like.cpp
                          part_01/02/my_member_template.h part_01/02/my_member_template.cpp
                          part_01/02/my_specialization.h part_01/02/my_specialization.cpp
                          part_01/02/my_template2_param.h part_01/02/my_template2_param.cpp)

