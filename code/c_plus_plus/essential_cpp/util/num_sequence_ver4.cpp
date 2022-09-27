

#include "num_sequence_ver4.h"

using namespace std;

template<int len, int beg_pos>
ostream &operator<<(ostream &os, const NumSequenceVer4<len, beg_pos> &ns)
{
    return ns.Print(os);
}

template<int len, int beg_pos>
int NumSequenceVer4<len, beg_pos>::Elem(int pos)
{
    if (!CheckIntegrity(pos, pelems_->size()))
        return 0;

    return (*pelems_)[pos - 1];
}

template<int len, int beg_pos>
const char *NumSequenceVer4<len, beg_pos>::WhatAmI() const
{
    return typeid (*this).name();
}

template<int len, int beg_pos>
ostream &NumSequenceVer4<len, beg_pos>::Print(ostream &os) const
{
    int elem_cnt = len + beg_pos - 1;
    if (elem_cnt > pelems_->size())
        GenElems(elem_cnt);

    int elem_pos = beg_pos - 1;
    os << " (" << len << ", " << beg_pos << "): ";
    while (elem_pos < elem_cnt)
        os << (*pelems_)[elem_pos++] << ' ';
    os << endl;

    return os;
}

template<int len, int beg_pos>
bool NumSequenceVer4<len, beg_pos>::CheckIntegrity(int pos, int size) const
{
    if (pos <= 0 || pos >= max_elems_)
    {
        cerr << "invalid position: " << pos
             << " can not handle request!!"
             << endl;
        return false;
    }

    if (pos > size) GenElems(pos);

    return true;
}
