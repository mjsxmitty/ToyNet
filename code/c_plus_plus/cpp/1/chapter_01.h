
#ifndef __CPP_CHAPTER_01_H__
#define __CPP_CHAPTER_01_H__

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
    void Hello(int a,int b) {}
};

}

#endif // __CPP_CHAPTER_01_H__
