
#include <iostream>
#include <typeinfo>
#include <vector>

#include "chapter_08.h"
#include "shape.h"
#include "animal.h"
#include "story.h"
#include "computer.h"

using namespace std;

void Chapter_08()
{
    //Practice_8_2();
    //Practice_8_4();
    Practice_8_5();
}

/* 赋值兼容原则: 只能使用继承来的成员 */
void Practice_8_2()
{
    //无虚函数情况
//    Shape s(3, 5);
//    s.Draw();

    Circle c(1,2,3);
    //c.Draw();

//    s = c;
//    s.Draw();

//    Shape &sc = c;
//    sc.Draw();

//    Shape *ps = &c;
//    ps->Draw();
//    //cout << ps->r_ << endl;

    Rect r(6,7,8,9);
    Shape *ps;
    ps = &c;
    ps->Draw();

    ps = &r;
    ps->Draw(); //重写函数可以为任意访问类型
}

void Practice_8_4()
{
    Animal *pa = new Dog;
    pa->Voice();
    delete pa;

    Animal *pb = new Cat;
    pb->Voice();
    delete pb;

    Person p;

    Book *b = new Book;
    p.TellStory(b);

    Newspaper *n = new Newspaper;
    p.TellStory(n);

//    IntelCpu *c = new IntelCpu;
//    kingStonMem *k = new kingStonMem;
//    WDHardDisk *w = new WDHardDisk;
    Cpu *c = new IntelCpu;
    Memory *k = new kingStonMem;
    HardDisk *w = new WDHardDisk;

    Computer cc(c,k,w);
    cc.Work();

    delete c;
    delete k;
    delete w;

    VD d;
    d.func();
    VB *pvb = &d;
    pvb->func();

    VA *pva = &d;
    pva->func();

    VC *pvc = &d;
    pvc->func();

    VC vc;
    pva = &vc;
    pva->func();
}

typedef void (*Funccc)(int);
typedef int (*pA)[5];
typedef vector<int>* (*ppp[3])(int, char);
typedef vector<int>& (*pfunccc)(int, double);

/* 运行时类型信息 */
void Practice_8_5()
{
//    cout << typeid(int).name() << endl;
//    cout << typeid(double).name() << endl;
//    cout << typeid(float).name() << endl;

//    cout << typeid(int *).name() << endl;
//    cout << typeid(const int *).name() << endl;
//    cout << typeid(int * const).name() << endl;
//    cout << typeid(const char *).name() << endl;
//    cout << typeid(const char * const).name() << endl;

//    cout << typeid(Funccc).name() << endl;
//    cout << typeid(pA).name() << endl;
//    cout << typeid(ppp).name() << endl;
//    cout << typeid(pfunccc).name() << endl;

    cout << typeid(VBase).name() << endl;
    cout << typeid(VDerive).name() << endl;

    VDerive d;
    VBase &b = d;
    cout << typeid(d).name() << endl;
    cout << typeid(b).name() << endl;

    VBase *p = &d;
    cout << typeid(d).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(*p).name() << endl;
}
