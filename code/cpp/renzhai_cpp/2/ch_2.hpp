
/**
 * 继承和操作符重载
 */

#ifndef __CPP_CH_2_HPP__
#define __CPP_CH_2_HPP__

#include "chapter_02.h"

using namespace std;

namespace chapter_02
{

void ch_2()
{
    /* 结构体成员权限 */
    Test1();

    /* 类成员函数 */
    Test2();

    /* 类的继承与成员函数 */
    Test3();

    /* 类的多继承与架构 */
    Test4();

    /* 类的虚继承 */
    Test5();

    /* 友元类 */
    Test6();

    /* 友元函数 */
    Test7();

    /* 构造函数和析构函数 */
    Test8();

    /* 浅拷贝,深拷贝 */
    Test9();

    /* 命名空间 */
    Test10();

    /* 重载<< >> */
    Test11();

    /* 重载操作符的深拷贝和浅拷贝 */
    Test12();
}

}

#endif //
