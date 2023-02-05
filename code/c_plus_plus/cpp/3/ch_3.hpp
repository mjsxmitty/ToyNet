
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
    {
        B b;
        b.Func1();
//        b.Func1(1);
//        b.Func1(1, 2);
    }

    /* 虚函数和普通函数调用执行区别 */
    {
        B b;
        A *ptr_a = &b;
        ptr_a->Func1();
//        ptr_a->Func1(1,2,3,4);

        ptr_a->Func();

        B *ptr_b = &b;
        //ptr_b->Func();
//        ptr_b->Func1(1, 2);
        ptr_b->Func1(1,2,3,4);
    }

    /* 纯虚函数 */
    {
        NewObject1 obj;
        Interface *ptr = &obj;
        ptr->Init();
        ptr->Destroy();

        obj.Init();
        NewObject1 *p = &obj;
        p->Init();
    }

    /* 普通函数内使用lambda */
    char buff1[1024] = "hello world！";
    {
        char buff[1024] = "hello world";
        auto hello = [&](char *buf)
        {
            auto hello1 = [](char *buf1)
            {
                printf("%s\n", buf1);
            };

            hello1(buf);
            hello1(buff);
            hello1(buff1);
        };

        hello(buff);
    }

    /* 类中使用lambda */
    {
        HelloTest test;
        test.Init();
    }

    /* c/cpp库封装 */
    {
        // todo...
    }

    /* 强制转换 */
    {
        // const_cast
        const HelloTest *ptr = new HelloTest();
        //ptr->Init();
        HelloTest *p = const_cast<HelloTest *>(ptr);  // 转换失败返回null
        p->Init();

        // C风格，容易产生野指针
        HelloTest *p1 = (HelloTest *)ptr;
        p1->Init();

        // reinterpret_cast
        int *a = reinterpret_cast<int *>(p);
        cout << "*a = " << *a << endl;
        HelloTest *p2 = reinterpret_cast<HelloTest *>(a);
        p2->Init();

        delete ptr;

        // dynamic_cast(虚函数)
        Hello *ph = new Hello();

        Hello1 *ph1 = dynamic_cast<Hello1 *>(ph);  // 向下转换
        ph1->Hello();

        Hello *ph2 = dynamic_cast<Hello *>(ph1);   // 向上转换
        //ph2->Init();

        Hello *ph3 = ph1;    // 隐式转换

        Hello2 *ph4 = dynamic_cast<Hello2 *>(ph);
        if (!ph4)
        {
            cout << "ph convert ph4 failed." << endl;
        }

        // static_cast(没有虚函数)
        Hello2 *ph5 = static_cast<Hello2 *>(ph);

        HelloA *pa = new HelloA();
        HelloB *pb = static_cast<HelloB *>(pa);

        delete pa;
        delete p;
    }

    /* const */
    {
        Const *pc = new Const();
        pc->m_ptr = new HelloTest();
        delete pc;

        const TestConst *ptc = new TestConst();
        ptc->Init();
        //ptc->Init2();

        TestConst c[10];
        for (int i = 0; i < 10; ++i)
        {
            const TestConst *p = &c[1];
            p->Init();
        }
    }
}

}

#endif // __CPP_CH_3_HPP__
