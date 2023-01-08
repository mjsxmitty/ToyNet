

#include <iostream> 
#include "ch_1.h"

#include "stdbool.h"    // C语言需要包含布尔

using namespace std;
using namespace gz_cpp_ch_01;

void Fun(GZHello &cc)    // C++支持传引用,C语言不支持传引用
{
    cc.a = 0;
}

void FunPtr(GZHello* cc) // C++ 支持传指针
{
    cc->a = 0;
}

GZHello* CreateObject()
{
    return NULL;
}

int ch_1()
{
    /* 1.打印方式不同 */
    {
        printf("Hello World \n");       // C
        cout << "Hello World" << endl;  // C++
    }

    /* 2.bool变量不同 */
    {
        bool bok = false;
    }


    /* 3.形参引用 */
    /*
     * 引用的特性
     * 引用必须初始化
     * 唯一性
     * 底层实现的方式是一样:指针方式实现
     */
    {
        GZHello o;
        Fun(o);

        GZHello &o1 = o;
        GZHello &o2 = o;
        //GZHello &o3 = NULL;

        int a = sizeof(o1);

        // 引用的指向不变
        GZHello o333;
        o2 = o333;

        // 指针可以修改指向
        GZHello *optr = &o;
        optr = &o333;
    }

    //
    if (CreateObject()) {}

    return 0;
}

/*

void Hello(int a, int b){}

struct FT
{
    void (*Hello1)(int, int);

    int a;
    int b;

} FTs;

void main()
{
    FTs.Hello1 = Hello;
}

*/
