
#include <iostream>
#include "chapter_07.h"
#include "ida.h"

using namespace std;

void Chapter_07()
{
    //Practice_7_3();
    //Practice_7_9();
    Practice_7_11();
}

void Practice_7_3()
{
    IDC c;
    cout<<"&c "<< &c <<endl;
    cout<<"*************"<<endl;
    c.func();
}

/* 派生类友元使用基类友元 */
//void Practice_7_7()
//{
////     Student a;
////     cout<<a<<endl;
//}

/* 同名成员被屏蔽 */
void Practice_7_9()
{
    Drive d;
    //d.func();
    d.Base::func(2);
}

/* 多继承 */
void Practice_7_11()
{
//    Sofa s;
//    s.sit();

//    Bed b;
//    b.sleep();

//    SofaBed sb;
//    sb.sit();
//    sb.sleep();

    //系统中有多个数据备份-->虚继承
//    Z z;
    Z z(1,2);
    z.dis();
    z.setData(200);
    z.dis();
    cout << z.getData() << endl;
}
