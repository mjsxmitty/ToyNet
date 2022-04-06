

#ifndef __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTU_H__
#define __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTU_H__

#include <string>


class GZStu
{
public:
    GZStu(std::string name) : name_(name) {}
    GZStu(std::string name, int n) : name_(name), num_(n) {}
    void Dis();

    std::string name_;
    int         num_;

    static int data_;
    static void Display();
};

#endif // __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTU_H__
