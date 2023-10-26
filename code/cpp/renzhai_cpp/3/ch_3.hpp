
/**
 * 多态和面向对象
 */

#ifndef __CPP_CH_3_HPP__
#define __CPP_CH_3_HPP__

#include <iostream>
#include "chapter_03.h"

using namespace std;

namespace chapter_03
{

void Fun(const int a,const HelloTest *Ptr,const HelloStruct &InHello)
{
    int ccc = Ptr->a;
    Ptr = new HelloTest();

    InHello.a;
}

void ch_3()
{
    /* 重载在继承中的问题 */
    Test1();

    /* 虚函数和普通函数调用执行区别 */
    Test2();

    /* 纯虚函数 */
    Test3();

    /* 普通函数内使用lambda */
    Test4();

    /* 类中使用lambda */
    Test5();

    /* c/cpp库封装 */
    //TODO...

    /* 强制转换 */
    Test6();

    /* const */
    Test7();
}

}

#endif // __CPP_CH_3_HPP__
