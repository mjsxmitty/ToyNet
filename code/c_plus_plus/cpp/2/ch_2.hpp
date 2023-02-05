
/**
 * 继承和操作符重载
 */

#ifndef __CPP_CH_2_HPP__
#define __CPP_CH_2_HPP__

#include "chapter_02.h"

using namespace std;

namespace chapter_02
{

void ch_2()
{
    /* 结构体成员权限 */
    {
        Hello t;
        t.a = 0;            // 使用成员
        int k = t.a;
        //t.m = 10;
        t.hello();
    }

    /* 类成员函数 */
    {
        Hello::SHello();    // 调用静态成员

        Monster monster;

        Monster::SHello();
        monster.SHello();
        monster.Hello();

        monster.GetP();     // 内联
    }

    /* 类的继承与成员函数 */
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

    /* 类的多继承与架构 */
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

    /* 类的虚继承 */
    {
        HelloD d;
        d.Hello();
    }

    /* 友元类 */
    {
        HelloTest2 t;
        t.Init();
    }

    /* 友元函数 */
    {
        Test t;
        Test::Print2(t);

        Print(t);
    }

    /* 构造函数和析构函数 */
    {
        TestA t;
        cout << t.a << endl;

        TestA t1(0);
        cout << t1.a << endl;
    }

    /* 浅拷贝,深拷贝 */
    {
        TestA t1;
        TestA t2(t1);
    }

    /* 命名空间 */
    {
        ch_02::Hello o = ch_02::Hello_A;
        ch_02::Hello o2 = ch_02::Hello::Hello_B;

        ch_02::Interface *p = new ch_02::Interface();

        ch_02::GetHello();
    }

    /* 重载<< >> */
    {
        Operator::GZstream << "HELLO" << Operator::GZendl;
        Operator::GZstream << "HELLO" << "123" << Operator::GZendl;
        Operator::GZstream << 1.024f << Operator::GZendl;
        Operator::GZstream << 1.00000123 << Operator::GZendl;
    }

    /* 重载操作符的深拷贝和浅拷贝 */
    {
        (Operator::GZstream = "GZ").Print() << Operator::GZendl;

        Operator::Stream a, b;
        a.ptr = (char *)malloc(20);
        strcpy(a.ptr, "nihao");
        b = a;
        b.Print();
    }
}

}

#endif //
