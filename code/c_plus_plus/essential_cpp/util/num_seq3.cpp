

#include "num_seq3.h"

using namespace std;

NumSeq3& NumSeq3::operator=(const NumSeq3 &rhs)
{
    if (this != &rhs)
    {
        length_ = rhs.length_;
        beg_pos_ = rhs.beg_pos_;
        relems_ = rhs.relems_;
    }
    return *this;
}

bool NumSeq3::CheckIntegrity(int pos, int size) const
{
    if (pos <=0 || pos >= max_elems())
    {
        cerr << "invalid position: " << pos
             << " can not handle request!!"
             << endl;
        return false;
    }

    if (pos > size)
        GenElems(pos);

    return true;
}

int NumSeq3::Elem(int pos) const
{
    if (!CheckIntegrity(pos, relems_.size()))
        return 0;

    return relems_[pos - 1];
}