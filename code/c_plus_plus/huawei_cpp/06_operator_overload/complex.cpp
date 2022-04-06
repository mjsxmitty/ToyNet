
#include <iostream>
#include "complex.h"

using namespace std;

GZComplex GZComplex::operator+(const GZComplex &rhs)
{
    cout << "成员重载" << endl;
    return GZComplex(x + rhs.x, y + rhs.y);
}

GZComplex GZComplex::operator-()
{
    return GZComplex(-x, -y);
}

GZComplex &GZComplex::operator++()
{
    x++;
    y++;
    return *this;
}

GZComplex GZComplex::operator++(int)
{
    GZComplex t = *this;
    x++;
    y++;
    return t;
}

GZComplex &GZComplex::operator+=(const GZComplex &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

void GZComplex::GetXY()
{
    cout << "( " << x << ", " << y << " )" << endl;
}

GZComplex operator+(const GZComplex &lhs, const GZComplex &rhs)
{
    cout << "友元重载" << endl;
    return GZComplex(lhs.x + rhs.x, lhs.y + rhs.y);
}

istream &operator>>(istream &is, GZComplex &item)
{
    is >> item.x >> item.y;
    return is;
}

ostream &operator<<(ostream &os, const GZComplex &item)
{
    os << "( " << item.x << ", " << item.y << " )";
    return os;
}
