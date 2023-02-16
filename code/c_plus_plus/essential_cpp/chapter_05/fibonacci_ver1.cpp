
#include <vector>
#include <iostream>
#include "fibonacci_ver1.h"

using namespace std;
namespace chapter_05
{

namespace ver1
{

vector<int> Fibonacci::elems_;

void Fibonacci::GenElems(int pos) const
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

    //length_ = elems_.size();
}

int Fibonacci::Elem(int pos) const
{
    if (!CheckIntegrity(pos, elems_.size()))
        return 0;
    
    return elems_[pos - 1];
}

const char* Fibonacci::WhatAmI() const
{
    return "Fibonacci";
}

ostream& Fibonacci::Print(ostream &os) const
{
    size_t elem_pos = beg_pos_ - 1;
    size_t elem_cnt = elem_pos + length_;

    if (elem_cnt > elems_.size())
        Fibonacci::GenElems(elem_cnt);

    while (elem_pos < elem_cnt)
        os << elems_[elem_pos++] 
            << ' ';

    return os;
}

}
}
