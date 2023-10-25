

#include <stdio.h>
#include <iostream>
//#include "stdbool.h"            // C语言需要包含布尔
#include "chapter_01.h"

using namespace std;

namespace chapter_01
{

void Func(Hello &ref)           // C++支持传引用,C语言不支持传引用
{
    ref.a = 0;
}

void Func(Hello *ptr)           // C++ 支持传指针(也会有copy)
{
    ptr->a = 0;
}

Hello* CreateObject()
{
    return NULL;
}

void Test1()
{
    printf("Hello World \n");       // C
    cout << "Hello World" << endl;  // C++
}

void Test2()
{
    bool bok = false;
}

void Test3()
{
    Hello o;
    Func(o);

    Hello &o1 = o;      // 引用必须初始化; 唯一性
    Hello &o2 = o;      // 被多个变量引用
//        Hello &o3 = NULL;

    cout << "o1 size : " << sizeof(o1) << endl;

    Hello o3;
    o2 = o3;            // 引用的指向不变

    // 指针可以修改指向
    Hello *optr = &o;
    optr = &o3;

    // 对象值的时候,使用指针(避免创建不成功)
    if (CreateObject())
    {
        //
    }
}

}

// C语言不支持结构内定义函数,支持指针

/*

void Hello(int a, int b)
{

}

struct Test
{
    void (*FuncPtr)(int, int);

    int a;
    int b;

} test;

void main()
{
    test.FuncPtr = Hello;
}

*/
