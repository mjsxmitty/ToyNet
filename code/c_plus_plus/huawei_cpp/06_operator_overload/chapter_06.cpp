
#include <iostream>
#include <algorithm>
#include <vector>

#include "chapter_06.h"
#include "complex.h"
#include "../05_friend/point.h"
#include "../04_class_object/a.h"

using namespace std;

void Chapter_06()
{
    //Practice_6_1();
    //Practice_6_4();
    Practice_6_5();
}

/* 友元重载 */

void Practice_6_1()
{
//    GZComplex c1(3, 4), c2(6,8);
//    c1.GetXY();
//    c2.GetXY();
//    GZComplex c3 = c1 + c2;
//    //GZComplex c3 = operator+(c1, c2);
//    c3.GetXY();

//    c3 += c1;
//    c3.GetXY();
//    GZComplex c4 = -c3;
//    c4.GetXY();

    GZComplex c5(1, 2);
    c5.GetXY();
//    ++c5;
//    c5.GetXY();
    ++++c5;
    c5.GetXY();

    GZComplex c6(6, 7);
    GZComplex c7 = c6++++;
    c6.GetXY();
    c7.GetXY();
    int n = 1;
    //n++++;
    cout << n << endl;

    GZComplex c(2,2);
    cin >> c;
    cout << c;
}

/* 转换构造函数 */
void Practice_6_4()
{
    Point2D p2(1,3);
    p2.Dis();

    Point3D p3(2,3,4);
    p3.Dis();

    //Point3D p3a = p2;
    Point3D p3a = static_cast<Point3D>(p2);
    p3a.Dis();
}

bool FunCom(int i, int j) { return i > j; }

//void *operator new(size_t i)
//{
//    cout<<"new "<<i<<endl;
//    return malloc(i);
//}

//void operator delete(void *p)
//{
//    cout<<"delete"<<endl;
//    free(p);
//}

//void *operator new[](size_t i)
//{
//    cout<<"new "<<i<<endl;
//    return malloc(i);
//}

//void operator delete[](void *p)
//{
//    cout<<"delete"<<endl;
//    free(p);
//}

/* 运算符重载--> 仿函数 */
void Practice_6_5()
{
//    Com p;
//    cout << p(4) << " " << p(3.2) << endl;

//    //主要应用与STL
//    int array[] = {100,89,23,56,12,200,22,500};
//    vector<int> vi(array, array+8);

//    //sort(vi.begin(), vi.end(), FunCom);
//    sort(vi.begin(), vi.end(), Com());

//    for(vector<int>::iterator itr = vi.begin(); itr != vi.end(); ++itr)
//        cout<<*itr<<endl;

//    int *pi = new int;
//    delete pi;

//    Com *pc = new Com;
//    delete pc;

//    B* cp = new B;
//    cout << "b object end.." << endl;
//    delete cp;

//    B* cpa = new B[20];
//    cout << "b object end.." << endl;
//    delete []cpa;

    A *p = new A;
    //delete p;

    PmA pa(p);
    //(*pa).func();
    pa->func();
}


