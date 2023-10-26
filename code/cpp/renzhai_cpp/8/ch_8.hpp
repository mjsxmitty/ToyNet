
/**
 * 预分配和多维内存
 */

#ifndef __CPP_CH_8_HPP__
#define __CPP_CH_8_HPP__

#include <stdlib.h>
#include "chapter_08.h"

using namespace std;

namespace chapter_08
{

void ch_8()
{
    /* 认识new和delete */
    Test1();

    /* new delete malloc free */
    Test2();

    /* new delete与虚析构 */
    Test3();

    /* 一维数组delete[] delete */
    Test4();

    /* 多维数组的内存创建和删除 */
    Test5();

    /* 为什么要预分配连续内存 */
    Test6();
}

}


#endif //__CPP_CH_8_HPP__
