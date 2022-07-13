

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

void Chapter_07();
void Practice_7_5_4();
void Practice_7_6();
void Practice_7();
void Homework_7_11();
void Homework_7_32();

/***************************7.3.4*********************************/
// 友元声明和作用域
struct GZX
{
    friend void f() {}
    //GZX() { f(); }

    void g();
    void h();
};

//void GZX::g() { return f(); }
void f();

/*****************************************************************/
/***************************7.32*********************************/
//声明友元函数
class ZGWindowMgr
{
public:
    void clear();
};

class ZGScreen
{
    friend void ZGWindowMgr::clear();
private:
    std::string contents_;
};

typedef double Money;
class Acc
{
    typedef int Money;  //未被使用 ---> 正确
public:
    Money balance() {return bal;}
private:
    /* 7-4-1 名字查找与类的作用域 */
    //已使用不可以重新定义
    //编译器不做检查,不报错
    //typedef int Money;
    Money bal;
};
/*****************************************************************/
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
