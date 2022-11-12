

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

#endif // __CPP_PRIMER_CH_13_H__
