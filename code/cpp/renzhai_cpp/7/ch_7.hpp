
/**
 * 信号
 */

#ifndef __CPP_CH_7_HPP__
#define __CPP_CH_7_HPP__

#include <csignal>
#include <iostream>
#include "chapter_07.h"

using namespace std;

namespace chapter_07
{

void ch_7()
{
    // 注册
    signal(SIGFPE, SignalFunction);
    signal(SIGINT, SignalFunction1);
    signal(SIGSEGV, SignalFunction2);

    for (int i = 0; i != 10; ++i)
    {
        if (i == 3)
        {
            raise(SIGFPE);
            continue;
        }

        if (i == 6)
        {
            raise(SIGINT);
            continue;
        }

        if (i == 9)
        {
            raise(SIGSEGV);
            continue;
        }

        cout << i << endl;
    }
}

}


#endif //__CPP_CH_7_HPP__
