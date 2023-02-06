
/**
 * CPP风格IO
 */

#ifndef __CPP_CH_6_HPP__
#define __CPP_CH_6_HPP__

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string.h>

#include "chapter_06.h"

using namespace std;

namespace chapter_06
{

void ch_6()
{
    char    buffer[1024] = {0};

    /* 基本的输入和输出 */
    Test1();

    /* CPP风格文件读写 */
    Test2();

    /* 文件拷贝 */
    Test3();
}

}

#endif // __CPP_CH_6_HPP__
