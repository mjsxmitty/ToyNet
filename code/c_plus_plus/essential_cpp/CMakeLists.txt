cmake_minimum_required(VERSION 3.16)

project(essential_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(essential 
                main.cpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp
                chapter_04/chapter_04.h chapter_04/chapter_04.cpp
                chapter_05/chapter_05.h chapter_05/chapter_05.cpp
                util/audio_book.h util/audio_book.cpp
                util/book.h util/book.cpp
                util/fibonacci_ver2.h util/fibonacci_ver2.cpp
                util/fibonacci_ver3.h util/fibonacci_ver3.cpp
                util/libmat.h util/libmat.cpp
                util/matrix.h util/matrix.cpp
                util/num_sequence.h util/num_sequence.cpp
                util/num_sequence_ver1.h util/num_sequence_ver1.cpp
                util/num_sequence_ver2.h util/num_sequence_ver2.cpp
                util/num_sequence_ver3.h util/num_sequence_ver3.cpp
                util/stack.h util/stack.cpp
                util/triangular.h util/triangular.cpp
                util/triangular_iterator.h util/triangular_iterator.cpp
                )
