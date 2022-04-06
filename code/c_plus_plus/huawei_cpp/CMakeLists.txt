cmake_minimum_required(VERSION 3.5)

project(huawei_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(huawei_cpp main.cpp
                            02_c_extersion/a.h 02_c_extersion/a.cpp
                            02_c_extersion/b.h 02_c_extersion/b.cpp
                            02_c_extersion/chapter_02.h 02_c_extersion/chapter_02.cpp
                            03_encapsulation/date.h 03_encapsulation/date.cpp
                            03_encapsulation/stack.h 03_encapsulation/stack.cpp
                            03_encapsulation/chapter_03.h 03_encapsulation/chapter_03.cpp
                            04_class_object/a.h 04_class_object/a.cpp
                            04_class_object/gzstring.h 04_class_object/gzstring.cpp
                            04_class_object/gz_stu.h 04_class_object/gz_stu.cpp
                            04_class_object/gz_student.h 04_class_object/gz_student.cpp
                            04_class_object/widget.h 04_class_object/widget.cpp
                            04_class_object/chapter_04.h 04_class_object/chapter_04.cpp
                            05_friend/point.h 05_friend/point.cpp
                            05_friend/chapter_05.h 05_friend/chapter_05.cpp
                            06_operator_overload/complex.h 06_operator_overload/complex.cpp
                            06_operator_overload/chapter_06.h 06_operator_overload/chapter_06.cpp
                            07_inherit_derive/ida.h 07_inherit_derive/ida.cpp
                            07_inherit_derive/chapter_07.h 07_inherit_derive/chapter_07.cpp
                            08_polymorphism/chapter_08.h 08_polymorphism/chapter_08.cpp
                            08_polymorphism/shape.h 08_polymorphism/shape.cpp
                            08_polymorphism/animal.h 08_polymorphism/animal.cpp
                            08_polymorphism/story.h 08_polymorphism/story.cpp
                            08_polymorphism/computer.h 08_polymorphism/computer.cpp
                            08_polymorphism/employee.h 08_polymorphism/employee.cpp
                            08_polymorphism/manager.h 08_polymorphism/manager.cpp
                            08_polymorphism/technician.h 08_polymorphism/technician.cpp
                            08_polymorphism/salesman.h 08_polymorphism/salesman.cpp
                            08_polymorphism/salemanager.h 08_polymorphism/salemanager.cpp)
