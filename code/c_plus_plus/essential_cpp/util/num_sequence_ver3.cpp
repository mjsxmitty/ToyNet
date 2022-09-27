

#include "num_sequence_ver3.h"

using namespace std;

NumSequenceVer3& NumSequenceVer3::operator=(const NumSequenceVer3 &rhs)
{
    if (this != &rhs)
    {
        length_ = rhs.length_;
        beg_pos_ = rhs.beg_pos_;
        relems_ = rhs.relems_;

        name_ = rhs.name_;
    }

    return *this;
}

bool NumSequenceVer3::CheckIntegrity(int pos, int size) const
{
    if (pos <=0 || pos >= MaxElems())
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

int NumSequenceVer3::Elem(int pos) const
{
    if (!CheckIntegrity(pos, relems_.size()))
        return 0;

    return relems_[pos - 1];
}

ostream &NumSequenceVer3::Print(ostream &os) const
{
    size_t elem_pos = beg_pos_ - 1;
    size_t elem_cnt = elem_pos + length_;

    if (elem_cnt > relems_.size())
        GenElems(elem_cnt);

    while (elem_pos < elem_cnt)
        os << relems_[elem_pos++]
           << ' ';
    os << endl;

    return os;
}
