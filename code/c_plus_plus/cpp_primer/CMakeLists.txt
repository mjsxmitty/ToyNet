cmake_minimum_required(VERSION 3.5.0)
project(cpp_primer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp_primer
    common/gz_ch_13.hpp
    common/gz_ch_14.hpp
    common/gz_ch_16.hpp
    common/blob.hpp common/gz_blob_ptr.hpp
    common/gz_math.h common/gz_math.cpp
    common/gz_string.h common/gz_string.cpp
    common/gz_str_vec.h common/gz_str_vec.cpp
    common/gz_message.h common/gz_message.cpp
    common/gz_folder.h common/gz_folder.cpp
    common/gz_has_ptr.h common/gz_has_ptr.cpp
    common/sales_data.h common/sales_data.cpp
    common/screen.h common/screen.cpp
    common/window_mgr.h common/window_mgr.cpp
    common/account.h common/account.cpp
    common/str_blob.h common/str_blob.cpp
    common/gz_str_blob_ptr.h common/gz_str_blob_ptr.cpp
    common/gz_query_result.h common/gz_query_result.cpp
    common/gz_text_query.h common/gz_text_query.cpp
    common/zg_quote.h common/zg_quote.cpp
    common/zg_bulk_quote.h common/zg_bulk_quote.cpp
    common/zg_base.h common/zg_base.cpp
    common/zg_disc_quote.h common/zg_disc_quote.cpp
    common/zg_limited_quote.h common/zg_limited_quote.cpp
    main.cpp
    chapter_02/chapter_02.h chapter_02/chapter_02.cpp
    chapter_03/chapter_03.h chapter_03/chapter_03.cpp
    chapter_04/chapter_04.h chapter_04/chapter_04.cpp
    chapter_05/chapter_05.h chapter_05/chapter_05.cpp
    chapter_06/chapter_06.h chapter_06/chapter_06.cpp
    chapter_07/chapter_07.h chapter_07/chapter_07.cpp
    chapter_08/chapter_08.h chapter_08/chapter_08.cpp
    chapter_09/chapter_09.h chapter_09/chapter_09.cpp
    chapter_10/chapter_10.h chapter_10/chapter_10.cpp
    chapter_11/chapter_11.h chapter_11/chapter_11.cpp
    chapter_12/chapter_12.h chapter_12/chapter_12.cpp
    chapter_13/chapter_13.h chapter_13/chapter_13.cpp
    chapter_14/chapter_14.h chapter_14/chapter_14.cpp
    chapter_15/chapter_15.h chapter_15/chapter_15.cpp
    chapter_16/chapter_16.h chapter_16/chapter_16.cpp
    chapter_15/quote.h chapter_15/quote.cpp
    chapter_15/bulk_quote.h chapter_15/bulk_quote.cpp
    chapter_15/limit_quote.h chapter_15/limit_quote.cpp
    chapter_15/disc_quote.h chapter_15/disc_quote.cpp
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CPack)
