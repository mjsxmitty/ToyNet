

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

extern void ch_07();

extern void ch_7_3();
extern void ch_7_3_1();
extern void ch_7_3_2();
extern void ch_7_5_4();
extern void ch_7_6();
void Practice_7();
void Homework_7_11();
void Homework_7_32();

/***************************7.5.1*********************************/
// 7.5.1 构造函数初始值列表
// 构造函数初始值有时必不可少
class ConstRef
{
public:
//    ConstRef(int i)
//    {
//        ci = i;
//        ri = i;
//    }
    ConstRef(int i) : ci(i), ri(i) {}
private:
    const int   ci;
    int         ri;
};

// 成员初始化顺序
class xx
{
public:
    //xx(int val) : j(val), i(j) {}   //error
    xx(int val) : i(val), j(val) {}     //尽可能用参数初始化
private:
    int i, j;
};

/*****************************************************************/
/***************************7.5.3*********************************/

// 7.5.3 默认构造函数的作用
class NoDefault
{
public:
    NoDefault(int i){}
};

struct gza
{
    NoDefault my_mem;
};

//gza aaa;

class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};

struct B
{
    //B(){}
    NoDefault no;
};

/*****************************************************************/
/***************************7.6*********************************/
//静态成员可以运用在某种场景,普通成员不行
class Bar
{
public:
    //Bar() {}
    static Bar mem1;
    Bar *mem2;
    //Bar mem3;
};

class Example
{
public:
    //Example() {}
    //static const double rate = 6.5;
    static constexpr double rate = 6.5;
    static const int vec_size = 20;
    static const std::vector<int> ivec;
};

void Homework_7_58();


#endif // __CPP_PRIMER_CHAPTER_07_H__
