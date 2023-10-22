
#ifndef __CPP_PRIMER_CH_13_HPP__
#define __CPP_PRIMER_CH_13_HPP__

#include <iostream>
#include <algorithm>
#include <vector>

#include "../common/has_ptr.h"

using namespace std;

class Point
{
public:
    Point() {}
    Point(const Point &rhs) { cout << "call Point copy construct func ..." << endl; }
};

class X
{
public:
    X() { cout << "construct func." << endl;}
    X(const X &x) { cout << "copy construct func." << endl; }
    X& operator= (const X &x) { cout << "assign construct func." << endl; return *this;}
    ~X() { cout << "distruct func." << endl; }
};

struct Numbered
{
    Numbered() : my_sn_(sn_++){}
    Numbered(const Numbered &rhs) : my_sn_(sn_++) {}

    static size_t   sn_;
    size_t          my_sn_;
};

size_t Numbered::sn_ = 0;

struct NoCopy
{
    NoCopy() = default;
    NoCopy(const NoCopy &) = delete;
    NoCopy& operator=(const NoCopy &) = delete;
    void Print() = delete;
    ~NoCopy() = default;
};

struct NoDtor
{
    NoDtor() = default;
    ~NoDtor() = delete;
};

class PrivateCopy
{
    PrivateCopy(const PrivateCopy &);
    PrivateCopy& operator=(const PrivateCopy &);
public:
    PrivateCopy() = default;
    ~PrivateCopy() = default;
};

class Employee
{
public:
    Employee() { my_sn_ = sn++; }
    Employee(const std::string &s) : name_(s) { my_sn_ = sn++; }
    Employee(const Employee &e) { name_ = e.name_; my_sn_ = sn++; }
    Employee& operator=(const Employee &e) { name_ = e.name_; my_sn_ = sn++; return *this; }//
public:
    const std::string&  GetName() const { return name_; }
    int                 GetMySn() const { return my_sn_; }
private:
    std::string name_;
    int         my_sn_;
    static int  sn;
};

int Employee::sn = 0;
void PrintEmployee(const Employee &e)
{
    cout << e.GetName() << ", " << e.GetMySn() << endl;
}

class Foo
{
    friend void swap(Foo &lhs, Foo &rhs);
public:
    explicit Foo(const string &s) : s_(s), hp_(s) {}
    string PrintVal() const { return s_; }
private:
    string s_;
    HasPtr hp_;
};

namespace chapter_13{

// 编译器会为X和hasX合成移动构造函数
struct X
{
    int     i;
    string  s;
};

struct hasX
{
    X mem;
};

struct Y
{
    int     i;
    string  s;
    Y(const Y&){}
};

struct hasY
{
    //hasY() = default;
    hasY(hasY &&) = default;

    Y mem;
};

class Foo2
{
public:
    Foo2() {cout << "Foo construct func." << endl;}
    Foo2(const Foo2 &rhs) { cout << "Foo copy construct func." << endl; }

    Foo2& operator=(const Foo2 &) &;
    //Foo AntherMem() const &;

    // 重载和引用函数
    Foo2 Sorted() &&;
    Foo2 Sorted() const &;
    ~Foo2(){}
private:
    vector<int> data;
};

Foo2& Foo2::operator=(const Foo2 &rhs) & { return *this; }

Foo2 Foo2::Sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo2 Foo2::Sorted() const &
{
    Foo2 ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}

};
#endif // __CPP_PRIMER_CH_13_HPP__
