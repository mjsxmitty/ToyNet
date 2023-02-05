
#ifndef __CPP_CH_1_HPP__
#define __CPP_CH_1_HPP__

/**
 * C和CPP的不同点
 */

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

int ch_1()
{
    /* 打印方式不同 */
    {
        printf("Hello World \n");       // C
        cout << "Hello World" << endl;  // C++
    }

    /* bool变量不同 */
    {
        bool bok = false;
    }

    /* 形参引用 */
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
    }

    // 对象值的时候,使用指针(避免创建不成功)
    if (CreateObject())
    {
        //
    }

    return 0;
}

}


#endif //
