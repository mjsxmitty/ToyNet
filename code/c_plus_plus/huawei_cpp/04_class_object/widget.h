

#ifndef __HUAWEI_CHAPTER_04_CLASS_OBJECT_WIDGET_H__
#define __HUAWEI_CHAPTER_04_CLASS_OBJECT_WIDGET_H__

#include <iostream>

class Widget
{
public:
    Widget();
public:
    void    Select(int idx, int val);
    int     Count() { return CNT; }
private:
    void f(int val) { std::cout << "void f() " << std::endl; }
    void g(int val) { std::cout << "void g() " << std::endl; }
    void h(int val) { std::cout << "void h() " << std::endl; }
    void i(int val) { std::cout << "void i() " << std::endl; }
private:
    enum {CNT = 4};

    void (Widget::*fptr[CNT])(int val);
};

#endif // __HUAWEI_CHAPTER_04_CLASS_OBJECT_WIDGET_H__
