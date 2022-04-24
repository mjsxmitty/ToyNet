
#include <vector>
#include <iostream>
#include "fibon.h"

using namespace std;

vector<int> Fibon::elems_;

void Fibon::GenElems(int pos) const
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
}

int Fibon::Elem(int pos) const
{
    if (!CheckIntegrity(pos, elems_.size()))
        return 0;

    // if (pos > elems_.size())
    //     Fibon::GenElems(pos);
    
    return elems_[pos - 1];
}

const char* Fibon::WhatAmI() const
{
    return "fibonacci";
}

ostream& Fibon::Print(ostream &os) const
{
    int beg_pos = beg_pos_ - 1;
    int end_pos = beg_pos + length_;

    if (end_pos > elems_.size())
        Fibon::GenElems(end_pos);

    while (beg_pos < end_pos)
        os << elems_[beg_pos++] << ' ';
    
    return os;
}