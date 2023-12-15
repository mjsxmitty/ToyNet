

#include <iostream>
#include "num_sequence_ver2.h"

using namespace std;

namespace chapter_05
{

namespace ver2
{

NumSequence& NumSequence::operator=(const NumSequence &rhs)
{
    cout << "NumSequence::operator=(const NumSequence &r)" << endl;
    if (this != &rhs)
    {
        length_ = rhs.length_;
        beg_pos_ = rhs.beg_pos_;
        relems_ = rhs.relems_;          // ?

        name_ = rhs.name_;
    }

    return *this;
}

NumSequence::NumSequence(const NumSequence &rhs) :
    relems_(rhs.relems_), beg_pos_(rhs.beg_pos_),
    length_(rhs.length_), name_(rhs.name_)
{
    //cout << "NumSequence::NumSequence(const NumSequence &r)" << endl;
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

NumSequence::NumSequence(int len, int beg, std::vector<int> &re, const string &s) :
    length_(len), beg_pos_(beg), relems_(re), name_(s)
{

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
