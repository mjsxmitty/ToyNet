
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iterator>

#include "chapter_02.h"
#include "a.h"
#include "b.h"

using namespace std;

void Chapter_02()
{
    //Chapter_2_1();
    //Chapter_2_2();
    //Chapter_2_4();
    //Chapter_2_5();
    //Chapter_2_6();
    //Chapter_2_7();
    //Chapter_2_8();
    //Chapter_2_9();
    //Chapter_2_10();
    Chapter_2_13();
}

enum SEASON {SPR, SUM, AUT, WIN};

/* 类型扩展 */
void Chapter_2_1()
{
    /* 类型检查更严格, 不可以将const指针赋值给非const类型(C语言可以) */
    const int   a = 100;
    int         b = 200;

    const int   *pa = &a;
    //int         *pb = &a;

    /* C++逻辑真有具体类型, C语言通过非0值判断 */
    bool flag = true;
    if (flag)
        cout << "i know bool type!" << endl;

    /* C++枚举类型只能被枚举元素初始化, C枚举类型本质是整数,可以用任意整数赋值
     * 定义方式有区别：C必须使用关键字enum, C++枚举类型可以作为类型
     */
    SEASON s = AUT;
    //s = 2;        //invalid conversion from 'int' to 'SEASON'
    //enum SEASON ss = SPR;

    /* C语言表达式不能作为左值(不可以被赋值), C++某些表达式可以 */
    int x,y = 1;
    (x = y) = 100;  //x = 100
    cout << "x = " << x << ", y = " << y << endl;

    (x < y ? x : y) = 200;  //y = 200
    cout << "x = " << x << ", y = " << y << endl;
}

/* 输入&输出 */
void Chapter_2_2()
{
    /* C中printf有强大的格式化控制,C++比较复杂 */
    printf("%c|%d|%f\n", 'a', 100, 31.34);
    printf("%5c|%5d|%6.3f\n", 'a', 100, 31.34);

    //setprecision 也是C++操作符,该操作符的作用是设定浮点数
    //setiosflags(ios::fixed)：用定点方式表示实数
    cout << setw(5) << 'a' << '|'
         << setw(5) << 100 << '|'
         << setw(5) << setprecision(6) << setiosflags(ios::fixed) << 31.34123
         //<< 31.34123
         //<< setprecision(6) << setiosflags(ios::fixed) << setiosflags(ios::right)<< 31.34123
         << endl;

    /* 按进制输出 */
    int i = 123;
    cout << i << endl;
    cout << dec << i << " " << hex << i << " " << oct << i << endl;
    cout << setbase(16) << i << " " << setbase(10) << i << " " << setbase(8) << i << endl;
    //cout << setbase(32) << i << endl; //setbase(0)

    /* 设置宽度 */
    cout << setw(10) << setbase(10) << 1234 << endl;
    cout << setw(10) << setfill('*') << setbase(10) << 1234 << endl;
    cout << setw(10) << setfill('*') << setiosflags(ios::left) << setbase(10) << 1234 << endl;
}


struct COMP
{
    float   real;
    float   image;
};

COMP operator+(COMP lhs, COMP rhs)
{
    lhs.real += rhs.real;
    lhs.image += rhs.image;
    return lhs;
}

/* 操作符重载 */
void Chapter_2_4()
{
    /* 操作符重载本质就是函数调用 */
    COMP c1 = {1, 2}, c2 = {3, 4};
    COMP csum = c1 + c2;
    cout << csum.real << ", " << csum.image << endl;
}

//单个参数
void WeatherForCast(const char *p = "sunny")
{
    time_t now(0);
    char tmp[64];
    strftime(tmp, sizeof (tmp), "%Y/%m/%d %X %A", localtime(&now));
    cout << tmp << ", today is " << p << endl;
}

//多个参数
float Volume(float length, float weight = 4, float high = 5)
{
    return length * weight * high;
}

void print(int i) {}
void print(int i, char c = ' ') {}

/* 默认参数 */
void Chapter_2_5()
{
    WeatherForCast();
    WeatherForCast("rainny");
    WeatherForCast();

    cout << Volume(3) << endl;
    cout << Volume(1, 2) << endl;
    cout << Volume(1, 2, 3) << endl;

    /* 一个函数不能既重载又默认 */
    //print(10);
}

//void Swap(int a, int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}

//开辟新的空间
void Swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

//传值并不发生改变
//void Swap(int *pa, int *pb)
//{
//    int *temp = pa;
//    pa = pb;
//    pb = temp;
//}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap1(char *pa, char *pb)
{
    char* temp = pa;
    pa = pb;
    pb = temp;
}

void Swap2(char **pa, char **pb)
{
    char* temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void Swap3(char *&pa, char *&pb)
{
    char* temp = pa;
    pa = pb;
    pb = temp;
}

struct TypeP { char *p; };
struct TypeC { char c; };
struct TypeR { char &c; };

/* 引用 */
void Chapter_2_6()
{
    int a = 1, b = 2;
    int &r = a;
    //int &r = b; //一经初始化不可以更改引用关系

    //引用不分配内存
    cout << "&a = " << &a << ", &r = " << &r << endl;

    int &rr = r;    //可对引用再次引用,表示原始变量有多个用户名
    // &前边为类型则表示引用,其它皆表示未取地址
    cout << "&a = " << &a
         << ", &r = " << &r
         << ", &rr = " << &rr
         << endl;

    /* 应用 */
    Swap(a, b);
    cout << "a = " << a
         << ", b = " << b
         << endl;

    Swap(&a, &b);
    cout << "a = " << a
         << ", b = " << b
         << endl;

    /* 引用提高: 可以定义指针的引用,不可以定义引用的引用 */
    int *pa = &a;
    int *&rp = pa;
    cout << "&a = " << &a
         << ", pa = " << pa
         << ", rp = " << rp
         << endl;
    //int &&rrr = r;

    char *sa = "hello";
    char *sb = "hi";

    Swap1(sa, sb);
    cout << "sa = " << sa
         << ", sb = " << sb
         << endl;

    Swap2(&sa, &sb);
    cout << "sa = " << sa
         << ", sb = " << sb
         << endl;

    Swap3(sa, sb);
    cout << "sa = " << sa
         << ", sb = " << sb
         << endl;

    /* 可以定义多级指针,不可以定义指向引用的指针 */
    int **ppa = &pa;
    //int &*rpp = r;

    /* 可以定义指针的数组,不可以定义引用的数组 */
    int ia, ib, ic;
    int* parr[] = {&ia, &ib, &ic};
    //int& rarr[] = {ia, ib, ic;};

    /* 可以定义数组的引用 */
    int arr[] = {1, 2, 3};
    int (&rarr)[3] = arr;   //注意引用数组的大小

    /* const 引用 */
    double val = 3.14;
    const int &ref = val;   //1.ref绑定的是一个临时无名对象
    double &ref2 = val;
    cout << "ref = " << ref << ", ref2 = " << ref2 << endl;
    val = 4.14;             //2.对引用绑定对象修改不会改变引用的临时对象
    cout << "ref = " << ref << ", ref2 = " << ref2 << endl;

    int i = 1;
    const int &iref = i + 5;
    cout << "iref = " << iref << endl;

    /* 引用的本质: 封装了的指针(type * const P)*/
    printf("%d %d %d\n", sizeof (TypeP), sizeof (TypeC), sizeof (TypeR));
}

/* new/delete */
void Chapter_2_7()
{
    int *p = new int(100);
    cout << "*p = " << *p << endl;
    delete p;

    char *pc = new char[10];
    strcpy(pc, "hello");
    cout << "*pc = " << pc << endl;
    delete [] pc;

    string *ps = new string("world");
    cout << "*ps = " << *ps << endl;
    delete ps;

//    cout << sizeof(char*[5]) << endl;
//    cout << sizeof(char [5]) << endl;
//    cout << sizeof(int [5]) << endl;
    char **pps = new char*[5];
    memset(pps, 0, sizeof(char*[5]));   //sizeof(char*[5])
    pps[0] = "hello";
    pps[2] = "world";
    pps[3] = "for the future.";
    char **ptr = pps;
    while (*ptr)
        cout << *ptr++ << endl;
    delete [] pps;

    int (*parr)[3] = new int[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            parr[i][j] = i + j;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cout<< parr[i][j] << " ";
        cout << endl;
    }

    delete [] parr;

    int (*pppp)[5][6] = new int [3][5][6];
    delete [] pppp;

    //因为pps,parr,pppp为连续分配的空间,所以可以直接释放,否则需要单独释放

    /* new/delete 效率更高;优势主要体现在类 类型的分配内存(构造)*/
    char *cptr = (char *)malloc(100);
    if (cptr == NULL)
        return;
    free(cptr);

    try {
        char *sp = new char[100];
        delete [] sp;
    } catch (const bad_alloc &e) {
        cout << e.what() << endl;
        return ;
    }

    /* 正常分配内存可能会报异常 */
    char *ssp = new (nothrow) char [100];
    delete [] ssp;
}

#define SQR(x) ((x) * (x))
inline int sqr(int x) { return x * x; }

/*
 * 宏替换发生在预处理阶段,不会进行类型检查,代码体积变大,逻辑不好梳理;内嵌代码,避免压栈出栈的开销
 * 内联函数处理在编译阶段; 避免重复开发，相反~~
 */
void Chapter_2_8()
{
    cout << SQR(10) << endl;
    cout << sqr(10) << endl;
}

void Func(int &ref) { }

/* 强制类型转换 */
void Chapter_2_9()
{
    /* static_cast */
    int a = 10, b = 3;
    cout << "after cover a type value: " << static_cast<double>(a) / b << endl;

    void *pv = &a;
    int *pi = static_cast<int *>(pv);
    *pi = 100;
    cout << "after cover pv type value: " << *pi
         << "\n\tpv pointer value: " << pv
         << "\n\tpi pointer value: " << pi
         << endl;

    char *pc = static_cast<char *>(malloc(10));

    /* reinterpret_cast */
    int x = 0x12345678;
    char *px = reinterpret_cast<char *>(&x);
    //char *px = static_cast<char *>(&x);
    printf("%x\n", *(px+1));

    int arr[5] = {1,2,3,4,5};
    //cout << reinterpret_cast<int>(arr)<< endl;
    //int *parr = reinterpret_cast<int *>(reinterpret_cast<int>(arr) + 1);

    /* const_cast */
    const int m = 123;
    Func(const_cast<int &>(m));
    //Func(const_cast<int>(m));     //error:const_cast转型的类型必须是指针、引用。

    //尽量不要利用返回回来的指针修改指向的内容(内置类型)
    int &ref = const_cast<int &>(m);    //int &ref = m;
    ref = 456;
    cout << "ref = " << ref << ", m = " << m
         << ", ref addr: " << &ref << ", m addr: " << &m
         << endl;

    int *pp = const_cast<int *>(&m);    //int *pp = &m;
    *pp = 789;
    cout << "ref = " << ref << ", m = " << m << ", *pp = " << *pp
         << ", p value: " << &ref << ", m addr: " << &m
         << endl;

    int *qq = pp;
    *qq = 345;
    cout << "ref = " << ref << ", m = " << m
         << ", *pp = " << *pp
         << ", *qq = " << *qq
         << endl;

    //可以改变自定义类型对象
    struct AA
    {
        int data;
    };

    const AA xxx = {111};
    AA &aa = const_cast<AA &>(xxx);
    aa.data = 222;
    cout << "xxx data: " << xxx.data << ", aa data: " << aa.data << endl;

    AA *pxxx = const_cast<AA *>(&xxx);
    pxxx->data = 333;
    cout << "xxx data: " << xxx.data << ", pxxx data: " << pxxx->data << endl;
}

namespace my_namespace
{
    int value = 5;
    int x, y, z;

    /* 支持嵌套 */
    namespace other
    {
        int m, n;
    }
}

namespace my_namespace2
{
    int x;
}

int val = 200;
void Funcc()
{
    cout << ::val << endl;
}

/* 命名空间 */
void Chapter_2_10()
{
    int *p = &val;
    int val = 100;
    cout << val << " " << *p  << " " << ::val << endl;
    //::Funcc(); //::没意义

    /* 命名空间的三种使用 */
//    my_namespace::value = 123;
//    cout << my_namespace::value << endl;

//    using my_namespace::x;
//    using my_namespace::y;
//    x = 1;
//    y = 2;
//    cout << x << " " << y << endl;

//    using namespace my_namespace;
//    z = 521;
//    cout << z << endl;

    //避免同名冲突
    my_namespace::x = 111;
    my_namespace2::x = 222;
    cout << my_namespace::x << " " << my_namespace2::x << endl;
    {
        using namespace my_namespace;
        x = 4444;
        cout <<x << endl;
    }
    {
        using namespace my_namespace2;
        x = 4334;
        cout <<x << endl;
    }

    //嵌套使用
    using namespace my_namespace::other;
    m = 1;
    n = 3;
    cout << m << " " << n <<endl;

    /* 协作开发 */
    using namespace NAME_A;
    using namespace NAME_B;

    A a;
    B b;
}

/* 练习 */
void Chapter_2_13()
{
    time_t now(0);
    char tmp[64];
    strftime(tmp, sizeof (tmp), "%X", localtime(&now));
    cout << tmp << endl;

    char buf[100] = "xxxx:yyyy:zzzz:aaaa:bbb";
    string buffer(begin(buf), end(buf));
}
