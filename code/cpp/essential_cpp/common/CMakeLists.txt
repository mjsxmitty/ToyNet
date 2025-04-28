
set(SRC_FILES common.cpp
              num_sequence.cpp
              stack.cpp
              triangular.cpp
              triangular_iterator.cpp
              matrix.cpp
              mat.cpp
              audio_book.cpp
              lifo_stack.cpp
              )

include_directories(.)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_library(common SHARED ${SRC_FILES})
