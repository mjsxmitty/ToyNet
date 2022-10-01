cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT (BlackHorse)
SET(SRC_LIST main.cpp test.h test.cpp
            address_book/menu.h  address_book/menu.cpp
            address_book/operator_options.h address_book/operator_options.cpp
            address_book/address_book.h address_book/address_book.cpp
            worker_manager/worker_manager.h worker_manager/worker_manager.cpp
            worker_manager/boss.h worker_manager/boss.cpp
            worker_manager/employee.h worker_manager/employee.cpp
            worker_manager/manager.h worker_manager/manager.cpp
            speech_match/speech_manager.h speech_match/speech_manager.cpp
            speech_match/speaker.h speech_match/speaker.cpp
            room_booking/identity.h room_booking/identity.cpp
            room_booking/student.h room_booking/student.cpp
            room_booking/teacher.h room_booking/teacher.cpp
            room_booking/global.hpp
            room_booking/manager1.h room_booking/manager1.cpp
            room_booking/computer_room.h room_booking/computer_room.cpp
            room_booking/order_file.h room_booking/order_file.cpp)


ADD_EXECUTABLE(BlackHorse ${SRC_LIST})

