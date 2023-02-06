
#include "chapter_02.h"

int hello()
{
    return 1 + 3;
}

namespace chapter_02
{

void Test1()
{
    Hello t;
    t.a = 0;            // 使用成员
    int k = t.a;
    //t.m = 10;
    t.hello();
}

int Monster::b = 1024;

void Hello::SHello(){}

Monster::Monster()
{
    int cc = ::hello();    // 使用全局成员
    cout << cc << endl;
}

Monster::~Monster(){}

void Test2()
{
    Hello::SHello();    // 调用静态成员

    Monster monster;

    Monster::SHello();
    monster.SHello();
    monster.Hello();

    monster.GetP();     // 内联
}

void Test3()
{
    ComponentWorkers workers;
    workers.Work();
//        workers.Work1();
//        workers.Work2();

    SpliceWorkers workers2;
    workers2.Hello();
//        workers2.Work();
//        workers2.Work1();
//        workers2.Work2();
}

bool IsSimulate(Physics *p)
{
    if (p)
    {
        p->Simulate();
    }

    return true;
}

void Test4()
{
    Attackor attackor;
    attackor.Start();
    attackor.Simulate();        // 多继承分块

    Attackor attackor1;
    attackor.AttackTarget(&attackor1);

    Physics *p = &attackor;
    Attack *a = &attackor;

    IsSimulate(&attackor);      // 只关心底层(基类)就好
    IsSimulate(&attackor1);
}

void Test5()
{
    HelloD d;
    d.Hello();

    d.HelloB::Hello1();

    d.HelloC::Hello2();
    HelloD::HelloC::Hello2();
}

void Test6()
{
    HelloTest2 t;
    t.Init();
}

void Test7()
{
    Test t;
    Test::Print2(t);

    Print(t);
}

void Test8()
{
    TestA t;
    cout << t.a << endl;

    TestA t1(0);
    cout << t1.a << endl;
}

void Test9()
{
    TestA t1;
    TestA t2(t1);
}

void Test10()
{
    ch_02::Hello o = ch_02::Hello_A;
    ch_02::Hello o2 = ch_02::Hello::Hello_B;

    ch_02::Interface *p = new ch_02::Interface();

    ch_02::GetHello();
}

void Test11()
{
    Operator::GZstream << "HELLO" << Operator::GZendl;
    Operator::GZstream << "HELLO" << "123" << Operator::GZendl;
    Operator::GZstream << 1.024f << Operator::GZendl;
    Operator::GZstream << 1.00000123 << Operator::GZendl;
}

void Test12()
{
    (Operator::GZstream = "GZ").Print() << Operator::GZendl;

    Operator::Stream a, b;
    a.ptr = (char *)malloc(20);
    strcpy(a.ptr, "nihao");
    b = a;
    b.Print();
}

}

namespace ch_02
{
    Hello* GetHello()
    {
        return NULL;
    }
}

namespace Operator
{
    Stream GZstream;
    Stream GZendl;
}
