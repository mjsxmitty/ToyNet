
#ifndef __CPP_CHAPETR_11_HPP__
#define __CPP_CHAPETR_11_HPP__

#include <iostream>
#include <stdio.h>
#include <functional>

using namespace std;

namespace chapter_11
{

int FuncHello(int a, int b);

auto Lambda = [](int a, int b) -> int
{
    printf("Lambda->param: %d, %d\n", a, b);
    return a + b;
};

class Hello
{
public:
    int hello(int a, int b)
    {
        printf("Hello::hello()->param: %d, %d\n", a, b);
        return a + b;
    }

    static int StaticHello(int a, int b)
    {
        printf("Hello::StaticHello->param: %d, %d\n", a, b);
        return a + b;
    }
};

class OperatorHello
{
public:
    int operator()(int a, int b)
    {
        printf("operator->param: %d, %d\n", a, b);
        return a + b;
    }
};

int FuncHello1(int a, int b, int c);
//int (*FunctionPtr)(int i, int j);

template <typename T>
T FuncTemplate(T a, T b)
{
    printf("template func param: %d, %d\n", a, b);
    return a + b;
}

void Call(function<int(int, int)> func);

void Test1();
void Test2();
}

#endif //__CPP_CHAPETR_11_HPP__
