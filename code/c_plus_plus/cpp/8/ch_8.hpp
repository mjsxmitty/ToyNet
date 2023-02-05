
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
    {
        int *p = new int;
        delete p;
    }

    /* new delete malloc free */
    {
        int *p1 = new int;
        int *p2 = (int *)malloc(sizeof(int)); // 分配一片内存

        delete p2;
        free(p1);

        Base *b = new Base();
        delete b;

        //b->Base();    // error
        //b->~Base();   // 可以调用
        //free(b);
    }

    /* new delete与虚析构 */
    {
        Base *base = new Children();
        delete base;
    }

    /* 一维数组delete[] delete */
    {
        Base *p = new Base[10];
        delete [] p;
        //delete p;
    }

    /* 多维数组的内存创建和删除 */
    {
        Children **pp = new Children* [10];
        for (int i = 0; i != 10; ++i)
        {
            pp[i] = new Children[10];
        }

        cout << "distruct ... " << endl;
        for (int i = 0; i != 10; ++i)
        {
            delete [] pp[i];
        }
        delete [] pp;

        Children ***ppp = new Children**[10];
        for (int i = 0; i != 10; ++i)
        {
            ppp[i] = new Children*[10];

            for (int j = 0; j != 10; ++j)
            {
                ppp[i][j] = new Children[10];
            }
        }

        cout << "distruct ... " << endl;
        for (int i = 0; i != 10; ++i)
        {
            for (int j = 0; j != 10; ++j)
            {
                delete [] ppp[i][j];
            }

            delete [] ppp[i];
        }
        delete [] ppp;
    }

    /* 为什么要预分配连续内存 */
    {
        PreDistribution<Base> distribution(10);
        Base *ptr = distribution[1];
        ptr->Hello();
    }
}

}


#endif //__CPP_CH_8_HPP__
