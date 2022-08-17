cmake_minimum_required(VERSION 3.5.0)
project(cpp_primer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp_primer 
                main.cpp
                chapter_02/chapter_02.h chapter_02/chapter_02.cpp
                chapter_03/chapter_03.h chapter_03/chapter_03.cpp
                chapter_04/chapter_04.h chapter_04/chapter_04.cpp
                chapter_05/chapter_05.h chapter_05/chapter_05.cpp
                chapter_06/local_math.h chapter_06/local_math.cpp
                chapter_06/chapter_06.h chapter_06/chapter_06.cpp
                lib_util/sales_data.h lib_util/sales_data.cpp
                lib_util/person.h lib_util/person.cpp
                lib_util/screen.h lib_util/screen.cpp
                lib_util/account.h lib_util/account.cpp
                lib_util/window_mgr.h lib_util/window_mgr.cpp
                chapter_07/chapter_07.h chapter_07/chapter_07.cpp
                chapter_07/gz_sales_data.h chapter_07/gz_sales_data.cpp
                chapter_07/gz_screen.h chapter_07/gz_screen.cpp
                chapter_07/gz_window_mgr.h chapter_07/gz_window_mgr.cpp
                chapter_07/gz_account.h chapter_07/gz_account.cpp
                chapter_08/chapter_08.h chapter_08/chapter_08.cpp
                chapter_09/chapter_09.h chapter_09/chapter_09.cpp
                chapter_10/chapter_10.h chapter_10/chapter_10.cpp
                chapter_11/chapter_11.h chapter_11/chapter_11.cpp
                chapter_12/str_blob.h chapter_12/str_blob.cpp
                chapter_12/query_result.h chapter_12/query_result.cpp
                chapter_12/text_query.h chapter_12/text_query.cpp
                chapter_12/chapter_12.h chapter_12/chapter_12.cpp
                chapter_13/employee.h chapter_13/employee.cpp
                chapter_13/str_vec.h chapter_13/str_vec.cpp
                chapter_13/string.h chapter_13/string.cpp
                chapter_13/has_ptr.h chapter_13/has_ptr.cpp
                chapter_13/folder_message.h chapter_13/folder_message.cpp
                chapter_13/chapter_13.h chapter_13/chapter_13.cpp
                chapter_14/chapter_14.h chapter_14/chapter_14.cpp
                chapter_15/quote.h chapter_15/quote.cpp
                chapter_15/bulk_quote.h chapter_15/bulk_quote.cpp
                chapter_15/limit_quote.h chapter_15/limit_quote.cpp
                chapter_15/disc_quote.h chapter_15/disc_quote.cpp
                chapter_15/chapter_15.h chapter_15/chapter_15.cpp
                object/blob.h
                chapter_16/chapter_16.h chapter_16/chapter_16.cpp
                util/zg_quote.h util/zg_quote.cpp
                util/zg_bulk_quote.h util/zg_bulk_quote.cpp
                util/zg_base.h util/zg_base.cpp
                util/zg_disc_quote.h util/zg_disc_quote.cpp
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CPack)
