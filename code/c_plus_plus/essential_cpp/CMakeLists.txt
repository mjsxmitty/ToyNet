cmake_minimum_required(VERSION 3.16)

project(essential_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(essential 
                main.cpp
                util/num_seq.h util/num_seq.cpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp
                util/stack.h util/stack.cpp
                util/matrix.h util/matrix.cpp
                util/triangular.h util/triangular.cpp
                util/triangular_iterator.h util/triangular_iterator.cpp
                util/num_seq1.h util/num_seq1.cpp
                chapter_04/chapter_04.h chapter_04/chapter_04.cpp
                chapter_05/libmat.h chapter_05/libmat.cpp
                chapter_05/book.h chapter_05/book.cpp
                chapter_05/audio_book.h chapter_05/audio_book.cpp
                chapter_05/chapter_05.h chapter_05/chapter_05.cpp
                util/num_seq2.h util/num_seq2.cpp
                util/fibon.h util/fibon.cpp
                util/fibon3.h util/fibon3.cpp
                util/num_seq2.h util/num_seq2.cpp
                util/num_seq3.h util/num_seq3.cpp
                )
