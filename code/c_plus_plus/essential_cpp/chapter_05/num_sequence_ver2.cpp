

#include "num_sequence_ver2.h"

using namespace std;

namespace chapter_05
{

namespace ver2
{

NumSequence& NumSequence::operator=(const NumSequence &rhs)
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

bool NumSequence::CheckIntegrity(int pos, int size) const
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

int NumSequence::Elem(int pos) const
{
    if (!CheckIntegrity(pos, relems_.size()))
        return 0;

    return relems_[pos - 1];
}

ostream &NumSequence::Print(ostream &os) const
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

}

}
