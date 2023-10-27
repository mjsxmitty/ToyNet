
#include "chapter_15.h"
#include "ch_15.hpp"
#include "../common/quote.h"
#include "../common/bulk_quote.h"

#include <iostream>

using namespace std;
using namespace chapter_15;

void ch_15()
{
    /* 定义基类和派生类 */
    //ch_15_2();

    //ch_15_5();
}

void ch_15_2()
{
    /* 定义派生类 */
    ch_15_2_2();
}

void ch_15_2_2()
{
    /* 派生类对象及派生类向基类的类型转换 */
    {
        Quote     quote;
        BulkQuote bulk;

        Quote *p = &quote;
        p = &bulk;

        Quote &r = bulk;
        r.isbn();
    }

    /*继承与静态函数*/
    {
         Derived d;
         d.f(Derived());
    }

    /* 派生类声明 */
    {
        //class BulkQuote : public Quote;
        class BulkQuote;
    }

    // 被用作基类的类
    {
        class D1 : public Base {};
        class D2 : public D1 {};
    }

    /* 防止继承的发生 */
    {
        class NoDerived final {};
        //class Bad : public NoDerived {};
        class Last final : public Base {};
        //class Bad2 : public Last {};
    }
}

void ch_15_5()
{
    /* 公有、私有和受保护继承 */
    PubDrev d1;
    ProDrev d2;
    PriDrev d3;
    d1.f();
    d1.pub_mem();
    d2.f();
    //d2.pub_mem();
    d3.f();
    //d3.pub_mem();
}
