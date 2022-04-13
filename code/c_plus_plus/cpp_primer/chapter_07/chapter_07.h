

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

void Chapter_07();
void Practice_7_5_4();
void Practice_7_6();

void Homework_7_11();

/* 7-3-4 友元声明和作用域 */
struct Xxx
{
    Xxx();
    friend void f() { }     //友元可以定义在类内
    //X() { f(); }            //error: 未声明
    void g();
    void k();
};

//void Xxx::g() {f();}        //error: 未声明
void f();
//k()实现在源文件...

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

class ConstRef
{
public:
    /* 7-5-1 构造函数初始值列表 */
    //构造函数初始值有时候必不可少
    //const,引用,未提供默认构造函数...
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

class xx
{
public:
    /* 7-5-1 成员初始化顺序 */
    //避免使用同一个对象的其他成员初始化
    //xx(int val) : j(val), i(j) {}   //error
    xx(int val) : i(val), j(val) {}
private:
    int i, j;
};

/* 7-5-3 默认构造函数的作用 */
class NoDefault
{
public:
    NoDefault(int i){}
};

class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};

//TODO: 定义的时候可以？？？
struct B
{
    NoDefault no;
};

/* 7-6 静态成员可以运用在某种场景,普通成员不行 */
//默认参数...
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
    //static constexpr std::vector<int> vec(vec_size);
};

void Homework_7_58();


#endif // __CPP_PRIMER_CHAPTER_07_H__
