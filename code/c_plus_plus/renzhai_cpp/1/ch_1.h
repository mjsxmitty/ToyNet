
#ifndef __GZ_CPP_CH_1_HPP__
#define __GZ_CPP_CH_1_HPP__

#include <stdio.h>

struct GZHello
{
    int         a;
    int         b;
    long int    c;
};

struct GZF
{
    int     q;
    int     w;
};

struct GZFTest : public GZF
{
    void Hello(int a,int b) {}
};

int ch_1();

#endif // __GZ_CPP_CH_1_HPP__
