
/**
 * 异常和反射
 */

#ifndef __CPP_CH_5_HPP__
#define __CPP_CH_5_HPP__

#include <stdio.h>
#include <iostream>

#include "chapter_05.h"

using namespace std;

namespace chapter_05
{

void ch_5()
{
    /* 认识CPP异常 */
    Test1();

    /* 封装任意参数打印 */
    Test2();

    /* 自定义异常类 */
    Test3();

    /* typeid获取类型反射信号 */
    Test4();
}

}

#endif //
