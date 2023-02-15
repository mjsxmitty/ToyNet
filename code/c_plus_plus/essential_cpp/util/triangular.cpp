
#include <vector>
#include <algorithm>

#include "triangular.h"
#include "triangular_iterator.h"

using namespace std;

Triangular::Triangular(int len, int bp) :
    beg_pos_(bp > 1 ? bp : 1), length_(len > 1 ? len : 1)
{
    next_ = beg_pos_ - 1;
    unsigned int elem_cnt = length_ + beg_pos_ + 1;

    if (elems_.size() < elem_cnt)
        GenElements(elem_cnt);
}

Triangular::Triangular(const Triangular &rhs) :
                        beg_pos_(rhs.beg_pos_),
                        length_(rhs.length_),
                        next_(rhs.beg_pos_ - 1)
{ }

int Sum(const Triangular &item)
{
    // int beg_pos = item.BegPos();
    // int len = item.Length();
    // int sum = 0;

    // for (int i = 0; i < len; ++i)
    // {
    //     sum += item.Elem(beg_pos + i);
    // }
    // return sum;

    if (!item.Length()) 
        return 0;

    item.NextReset();

    int val = 0, sum = 0;
    while (item.Next(val))
        sum += val;

    return sum;
}

bool Triangular::Next(int &val) const
{
    if (next_ < beg_pos_ + length_ - 1)
    {
        val = elems_[next_++];
        return true;
    }

    next_ = 0;
    return false;
}

Triangular& Triangular::Copy(const Triangular &rhs)
{
    if (this != &rhs)
    {
        beg_pos_ = rhs.beg_pos_;
        length_ = rhs.length_;
        next_ = rhs.beg_pos_ - 1;
    }

    return *this;
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

vector<int> Triangular::elems_;
int         Triangular::init_size_ = 1024;

void Triangular::GenElemsToValue(int value)
{
    int size = elems_.size();
    if (!size)
    {
        elems_.push_back(1);
        size = 1;
    }

    while (elems_[size - 1] < value && size < max_size_)
    {
        ++size;
        elems_.push_back(size * (size + 1) / 2);
    }

    if (size == max_size_)
    {
        cerr << "Triangular sequence: value to large: "
                << value << " --- exceeds max size of "
                << max_size_ << endl;
    }
}

bool Triangular::IsElem(int val)
{
    if (!elems_.size() || elems_[elems_.size() - 1] < val)
        GenElemsToValue(val);

    return find(elems_.begin(), elems_.end(), val) != elems_.end();
}

void Triangular::GenElements(int length)
{
    if (length < 0 || length > max_size_)
    {
        cerr << "Triangular sequence: invalid size: "
                << length << " --- max size is: " << max_size_
                << endl;
        return;
    }

    int size = elems_.size() ? elems_.size() + 1 : 1;
    for (; size <= length; ++size)
        elems_.push_back(size * (size + 1) / 2);
}

void Triangular::Display(int len, int bp, ostream &os)
{
    if (len <= 0 || bp <= 0)
    {
        cerr << "invalid parameters, can't handle request: "
                << len << ", " << bp << endl;
        return ;
    }

    unsigned int elems = len + bp - 1;  // 元素个数
    if (elems_.size() < elems)
        GenElements(elems);

    for (unsigned int ix = bp - 1; ix < elems; ++ix)
        os << elems_[ix] << ' ';
}

Triangular::Iterator Triangular::Begin() const
{
    return Iterator(beg_pos_);
}

Triangular::Iterator Triangular::End() const
{
    return Iterator(beg_pos_ + length_);    // 不需要-1
}

ostream &operator<<(ostream &os, const Triangular &rhs)
{
    os << "( " << rhs.length_ << ", " << rhs.beg_pos_ << " ) ";
    rhs.Display(rhs.length_, rhs.beg_pos_, os);

    return os;
}

istream& operator>>(istream& in, Triangular& rhs)
{
    int bp, len;

    in >> bp >> len;
    rhs.BegPos(bp);
    rhs.Length(len);
    rhs.NextReset();

    return in;
}
