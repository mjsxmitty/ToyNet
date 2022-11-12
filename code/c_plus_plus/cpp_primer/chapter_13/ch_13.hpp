

#ifndef __CPP_PRIMER_CH_13_H__
#define __CPP_PRIMER_CH_13_H__

#include <iostream>

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

struct GZNoCopy
{
    GZNoCopy() = default;
    GZNoCopy(const GZNoCopy &) = delete;
    GZNoCopy& operator=(const GZNoCopy &) = delete;
    void Print() = delete;
    ~GZNoCopy() = default;
};

struct GZNoDtor
{
    GZNoDtor() = default;
    ~GZNoDtor() = delete;
};

class GZPrivateCopy
{
    GZPrivateCopy(const GZPrivateCopy &);
    GZPrivateCopy& operator=(const GZPrivateCopy &);
public:
    GZPrivateCopy() = default;
    ~GZPrivateCopy() = default;
};

class GZEmployee
{
public:
    GZEmployee() { my_sn_ = sn++; }
    GZEmployee(const std::string &s) : name_(s) { my_sn_ = sn++; }
    GZEmployee(const GZEmployee &e) { name_ = e.name_; my_sn_ = sn++; }
    GZEmployee& operator=(const GZEmployee &e) { name_ = e.name_; return *this; }//
public:
    const std::string&  GetName() const { return name_; }
    int                 GetMySn() const { return my_sn_; }
private:
    std::string name_;
    int         my_sn_;
    static int  sn;
};

int GZEmployee::sn = 0;
void PrintEmployee(const GZEmployee &e)
{
    cout << e.GetName() << ", " << e.GetMySn() << endl;
}

#endif // __CPP_PRIMER_CH_13_H__
