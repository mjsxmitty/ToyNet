
#ifndef __CPP_CHAPTER_01_H__
#define __CPP_CHAPTER_01_H__

#include <stdio.h>

namespace chapter_01
{

struct Hello
{
    int         a;
    int         b;
    long int    c;
};

struct HelloA
{
    int     q;
    int     w;
};

struct HelloB : public HelloA
{
    void Hello(int a,int b)
    {
        printf("HelloB::Hello(): %d, %d", a, b);
    }
};

void Test1();
void Test2();
void Test3();
}

#endif // __CPP_CHAPTER_01_H__
