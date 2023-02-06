

#include "chapter_04.h"
#include <stdio.h>
#include <iostream>
#include <type_traits>

using namespace std;

namespace chapter_04
{

void Test11()
{
    Vector<int>     ivec;
    Vector<float>   fvec;
    Vector<Test>    hvec;

    CallArray(ivec);
    CallArray(hvec);        // 可以自行推断
    CallArray<float>(fvec); //
}

void Test22()
{
    Vector<Test> ct;
    float *p = ct.Hello1<float>();
}

void Test33()
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

void Test44()
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

//HELLO_CLASS(NIHAO, {std::cout << "WWW" << std::endl;})

//void Test55()
//{
//    FNIHAO<int> nihao;
//    nihao.Work();
//}

void Test66()
{
    int i = 14;
    float f = 3.14f;
    double d = 2.222;
    char a = 'a';
    char arr[] = "hello";

    Func(i, f, d, a);
    PrintVal(i, f, d, a, arr);

    int a1 = 1;
    int a2 = 2;
    int a3 = 4;
    int a5 = 6;
    Func1(a1, a2, a3, a5);
    int sum = FunValue<int>(a1, a2, a3, a5);
    printf("sum = %d\n", sum);
}

void Test77()
{
    TestLen<int, float, char> tl;
    cout << tl.Number << endl;
}

void Test88()
{
    cout << typeid (SpawnIndex<3>::Type).name() << endl;
}

void Test99()
{
    // 创建对象（包含参数）
    TestA *p = CreateObj<TestA>(10, "nihao");
    p->Print(1,2);
}

void Test101()
{
    TestA *p = CreateObj<TestA>(10, "nihao");
    auto func = CreateObject(p, &TestA::Print);
    if (func(1,2))
    {

    }
}

void Test102()
{
    cout << std::is_same<int, float>::value << endl;
    cout << std::is_class<int>::value << endl;
    cout << std::is_class<TestA>::value << endl;

    cout << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << endl;

    std::conditional<true, int, double>::type a;
    std::conditional<(2 > 22), int, double>::type a1;

    std::decay<int&>::type a3;
    std::decay<const int>::type a4;

}

}
