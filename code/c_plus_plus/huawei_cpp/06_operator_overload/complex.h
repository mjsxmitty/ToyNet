
#ifndef __HUAWEI_CHAPTER_06_COMPLEX_H__
#define __HUAWEI_CHAPTER_06_COMPLEX_H__

#include <iostream>

class GZComplex
{
    friend GZComplex operator+(const GZComplex &lhs, const GZComplex &rhs);
    friend std::istream& operator>>(std::istream &is, GZComplex &item);
    friend std::ostream& operator<<(std::ostream &os, const GZComplex &item);
public:
    GZComplex(float xx, float yy) : x(xx), y(yy) {}
public:
    GZComplex& operator+=(const GZComplex &rhs);
    GZComplex operator+(const GZComplex &rhs);
    GZComplex operator-();
    GZComplex& operator++();
    GZComplex operator++(int);
public:
    void GetXY();
private:
    float  x, y;
};

GZComplex operator+(const GZComplex &lhs, const GZComplex &rhs);
std::istream& operator>>(std::istream &is, GZComplex &item);
std::ostream& operator<<(std::ostream &os, const GZComplex &item);

#endif // __HUAWEI_CHAPTER_06_COMPLEX_H__
