
include_directories(.)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_library(common SHARED common.cpp num_sequence.cpp)
