
#include <string>
#include <iostream>
#include "chapter_04.h"
#include "a.h"
#include "gzstring.h"
#include "gz_stu.h"
#include "gz_student.h"
#include "widget.h"

using namespace std;

void Chapter_04()
{
    //Chapter_4_9();
    //Chapter_4_10();
    //Chapter_4_12();
    //Chapter_4_15();
    Chapter_4_17();
}

void Foo(A a) {}
void Foo2(A &a) {}
A Foo3(A &a) {
    cout << "in Foo: " << (void *)&a << endl;
    return a;}

A Foo4()
{
    A b;
    cout << "in Foo4: " << (void *)&b << endl;
    return b;
}

/* 返回栈对象 */
void Chapter_4_9()
{
    //A a;
    //Foo(a);
    //Foo2(a);

//    Foo3(a);    //临时匿名对象
//    A t = Foo3(a);  //t接管匿名空间对象
//    cout << "t addr: " << (void *)&t << endl;

//    A t;
//    t = Foo3(a);
//    cout << "t addr: " << (void *)&t << endl;

    //linux 深层次优化
//    A t = Foo4();
//    cout << "in main: " << (void *)&t << endl;

    A t;
    cout << "in main: " << (void *)&t << endl;
    t = Foo4();
}

void Chapter_4_10()
{
    //GZString str = "china";
    GZString str("china");
    str.Display();

    GZString s = str;
    s.Display();

    GZString s3("for the feathre.");
    //s3 = str;
    s3.Display();

    if (str == s3)
    {
        cout << "str eq s3" << endl;
    }
    else {
        cout << "str not eq s3" << endl;
    }

    if (str > s3)
    {
        cout << "str > s3" << endl;
    }
    else {
        cout << "str < eq s3" << endl;
    }

    GZString s4 = str + s3;
    s4.Display();
}

/* 栈和堆上对象和对象数组 */
void Chapter_4_12()
{
    //GZStu stu;
    GZStu stu("gao");
    stu.Dis();
    cout << "stu size: " << sizeof (GZStu) << endl;
    //默认构造函数
    //GZStu s[5] = {GZStu("zhangsan"), GZStu("lisi")};
    GZStu s[] = {GZStu("zhangsan"), GZStu("lisi")};

    GZStu *ps = new GZStu[2]{GZStu("zhangsan"), GZStu("lisi")}; //c++11
    ps[0].Dis();
}

/* 静态变量 */
void Chapter_4_15()
{
    string  name;
    string  post_name;
    char    buf[64];

    for (int i = 0; i < 10; ++i)
    {
        name = "stu_";
        post_name = itoa(i, buf, 10);
        name += post_name;

        new GZStudent(name);
    }

    GZStudent::PrintStudentList();
    GZStudent::DeleteStudentList();
}

/* 指向成员(函数)的指针 */
void Chapter_4_17()
{
    GZStu s("zhangsan", 1);
    GZStu s2("lisi", 2);

//    string *p = &s.name_;
//    cout << *p << endl;

    //通过对象调用
    string GZStu::*ps = &GZStu::name_;
    cout << s.*ps << endl;
    cout << s2.*ps << endl;

    //通过指针调用
    GZStu *pp = new GZStu("wangwu", 3);
    cout << pp->*ps << endl;

    GZStu *pps = &s2;
    //指向函数的指针
    void (GZStu::*pf)() = &GZStu::Dis;
    (s.*pf)();
    (s2.*pf)();
    (pps->*pf)();

    Widget w;
    for (int i = 0; i < w.Count(); ++i)
        w.Select(i, 1);

    //指向静态成员函数的的指针
    int *pi = &GZStu::data_;
    cout << *pi << endl;

    void (*pfunc)() = &GZStu::Display;
    pfunc();
}
