
#include <vector>
#include <iostream>
#include "fibonacci_ver2.h"

using namespace std;

vector<int> FibonacciVer2::elems_;

void FibonacciVer2::GenElems(int pos) const
{
    if (elems_.empty())
    {
        elems_.push_back(1);
        elems_.push_back(1);
    }
    
    if(elems_.size() <= pos)
    {
        int ix = elems_.size();
        int n2 = elems_[ix - 2];
        int n1 = elems_[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            elems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    // 是否应该调整一下pos length ???
}

int FibonacciVer2::Elem(int pos) const
{
    if (!CheckIntegrity(pos, elems_.size()))
        return 0;

    // 跳过虚函数机制
    // if (pos > elems_.size())
    //     FibonacciVer2::GenElems(pos);
    
    return elems_[pos - 1];
}

const char* FibonacciVer2::WhatAmI() const
{
    return "Fibonacci";
}

ostream& FibonacciVer2::Print(ostream &os) const
{
    size_t elem_pos = beg_pos_ - 1;
    size_t elem_cnt = elem_pos + length_;

    if (elem_cnt > elems_.size())
        FibonacciVer2::GenElems(elem_cnt);

    while (elem_pos < elem_cnt)
        os << elems_[elem_pos++] 
           << ' ';

    os << endl;
    
    return os;
}
