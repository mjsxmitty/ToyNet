
#include <vector>
#include "triangular.h"

using namespace std;

vector<int> Triangular::elems_;

Triangular::Triangular(int len, int bp) :
    beg_pos_(bp > 1 ? bp : 1), length_(len > 1 ? len : 1)
{
    next_ = beg_pos_ - 1;
}

Triangular::Triangular(const Triangular &rhs) :
    beg_pos_(rhs.beg_pos_), length_(rhs.length_), next_(rhs.next_)
{

}

Triangular& Triangular::operator=(const Triangular &rhs)
{
    if (this != &rhs)
    {
        beg_pos_ = rhs.beg_pos_;
        length_ = rhs.length_;
        next_ = rhs.beg_pos_ - 1;
    }

    return *this;
}

bool Triangular::Next(int &val) const
{
    if (!next_) return false;

    if (next_ < beg_pos_ + length_)
    {
        val = elems_[next_++];
        return true;
    }

    next_ = 0;
    return false;
}

void Triangular::GenElements(int length)
{
    if (length < 0 || length > max_size)
    {
        cerr << "Triangular sequence: invalid szie: "
             << length << " --- max size is: " << max_size
             << endl;
        return;
    }

    int ix = elems_.size() ? elems_.size() + 1 : 1;
    for (; ix < length; ++ix)
        elems_.push_back(ix * (ix + 1) / 2);
}

int Sum(const Triangular &item)
{
    if (!item.Length()) return 0;

    int val, sum = 0;
    item.NextReset();
    while (item.Next(val))
        sum += val;

//    for (int ix = 0; ix < item.Length(); ++ix)
//        sum += item.Elem(item.BegPos() + ix);

    return sum;
}
