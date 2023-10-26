cmake_minimum_required(VERSION 3.16)

project(essential_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(essential 
                main.cpp
                chapter_02/ch_2.hpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_02/num_sequence.h chapter_02/num_sequence.cpp
                chapter_03/ch_3.hpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp
                chapter_04/ch_4.hpp
                chapter_04/chapter_04.h chapter_04/chapter_04.cpp
                chapter_04/matrix.h chapter_04/matrix.cpp
                chapter_04/num_sequence_ver1.h chapter_04/num_sequence_ver1.cpp
                chapter_04/stack.h chapter_04/stack.cpp
                chapter_04/user_profile.h chapter_04/user_profile.cpp
                chapter_04/triangular_iterator.h chapter_04/triangular_iterator.cpp
                chapter_04/triangular.h chapter_04/triangular.cpp
                chapter_05/ch_5.hpp
                chapter_05/chapter_05.h chapter_05/chapter_05.cpp
                chapter_05/audio_book.h chapter_05/audio_book.cpp
                chapter_05/book.h chapter_05/book.cpp
                chapter_05/fibonacci_ver1.h chapter_05/fibonacci_ver1.cpp
                chapter_05/fibonacci_ver2.h chapter_05/fibonacci_ver2.cpp
                chapter_05/libmat.h chapter_05/libmat.cpp
                chapter_05/num_sequence_ver1.h chapter_05/num_sequence_ver1.cpp
                chapter_05/num_sequence_ver2.h chapter_05/num_sequence_ver2.cpp
                chapter_05/stack_ver1.h chapter_05/stack_ver1.cpp
                chapter_05/lifo_stack.h chapter_05/lifo_stack.cpp
                chapter_05/peek_back_stack.h chapter_05/peek_back_stack.cpp
                chapter_06/num_sequence_ver3.h chapter_06/num_sequence_ver3.cpp
                chapter_06/num_sequence_ver4.h chapter_06/num_sequence_ver4.cpp
                chapter_06/fibonacci_ver3.h chapter_06/fibonacci_ver3.cpp
                chapter_06/num_sequence_ver5.h
                chapter_06/ch_6.hpp
                chapter_06/chapter_06.h chapter_06/chapter_06.cpp
                chapter_06/bt_node.h chapter_06/bt_node.cpp
                chapter_06/binary_tree.h chapter_06/binary_tree.cpp
                )
