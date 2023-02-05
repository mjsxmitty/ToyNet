
/**
 * 模板
 */

#ifndef __CPP_CH_4_HPP__
#define __CPP_CH_4_HPP__

#include "chapter_04.h"

namespace chapter_04
{

void ch_4()
{
    /* 函数模板与类模板 */
    {
        Vector<int>     ivec;
        Vector<float>   fvec;
        Vector<Test>    hvec;

        CallArray(ivec);
        CallArray(hvec);        // 可以自行推断
        CallArray<float>(fvec); //
    }

    /* 类模板匹配 */
    {
        Vector<Test> ct;
        float *p = ct.Hello1<float>();
    }

    /* 类模板和(虚)继承 */
    {
        Test1 t;                         // 普通继承模板
        t.Hello();

        Test2<Test> it;                  // 模板继承“普通”
        it.Hello1<int>();

        Test3<float, int, double> ft;    // 模板继承模板
        ft.Hello2();

        Test6 t1;                        // 虚继承
        t1.Hello();

        Test7 t2;                        // 友元
        t2.Hello();
    }

    /* 类模板和多态 */
    {
        hello1 a;
        hello<int> *p = &a;
        p->Init();

        p->Hello();
        p->Hello(1);

        hello1 *p2 = &a;
        p2->Hello(10);
        p2->Hello(0, 1024);
    }

    /* 高级宏 */
    {

    }

    /*  */
    {
        int a1 = 1;
        int a2 = 2;
        int a3 = 4;
        int a5 = 6;
        int sum = FunValue<int>(a1, a2, a3, a5);
        printf("sum = %d\n", sum);
    }
}

}
#endif //__CPP_CH_4_HPP__
