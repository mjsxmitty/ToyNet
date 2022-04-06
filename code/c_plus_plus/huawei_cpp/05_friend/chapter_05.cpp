
#include <iostream>

#include "chapter_05.h"
#include "point.h"

using namespace std;

void Chapter_05()
{
    Practice_5_2();
}

/* 异类对象间的友元 */
void Practice_5_2()
{
    /* 普通函数作为友元 */
    Point p1(3.0, 4.0), p2(6.0, 8.0);
    p1.GetXY();
    p2.GetXY();
    cout << Distance(p1, p2) << endl;

    /* 类成员函数作为友元 */
    ManagerPoint mp;
    cout << mp.Distance(p1, p2) << endl;
}
