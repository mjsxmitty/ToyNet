
#include "chapter_03.h"

#include <iostream>

using namespace std;

namespace chapter_03
{

void Test1()
{
    B b;
    b.Func1();
    b.A::Func1();
//        b.Func1(1);
//        b.Func1(1, 2);
}

void Test2()
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

void Test3()
{
    NewObject1 obj;
    Interface *ptr = &obj;
    ptr->Init();
    ptr->Destroy();

    obj.Init();
    NewObject1 *p = &obj;
    p->Init();
}

void Test4()
{
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
}

HelloTest::HelloTest() {}

void Test5()
{
    HelloTest test;
    test.Init();
}

void HelloTest::Init()
{
    auto Hello = [&]() -> bool
    {
        a = 0;
        b = 10;
        aa = 10.f;

        return true;
    };

    bool init = Hello();
    if (init)
    {
        printf("init succeed, a = %d, "
               "b = %d, aa = %f\n", a, b, aa);
    }
}

void Test6()
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

TestConst TestConst::NULLConst;

void Test7()
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
