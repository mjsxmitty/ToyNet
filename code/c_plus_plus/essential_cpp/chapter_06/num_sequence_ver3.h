
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_3_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_3_H__

#include <vector>
#include <iostream>

namespace chapter_06
{

namespace ver3
{

template <int len, int beg_pos>
class NumSequence
{
public:
    virtual ~NumSequence() {}
public:
    int             Elem(int pos);
    const char*     WhatAmI() const;
    static int      MaxElems() { return max_elems_; }
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    std::vector<int>    *pelems_;
    static const int    max_elems_ = 1024;
protected:
    NumSequence(std::vector<int> *pv) : pelems_(pv){}
protected:
    virtual void    GenElems(int pos) const = 0;
    bool            CheckIntegrity(int pos, int size) const;
};

template <int len, int beg_pos>
std::ostream& operator<<(std::ostream &os, const NumSequence<len, beg_pos> &ns)
{
    ns.Print(os);
    return os;
}

template<int len, int beg_pos>
int NumSequence<len, beg_pos>::Elem(int pos)
{
    if (!CheckIntegrity(pos, pelems_->size()))
        return 0;

    return (*pelems_)[pos - 1];
}

template<int len, int beg_pos>
const char *NumSequence<len, beg_pos>::WhatAmI() const
{
    return typeid (*this).name();
}

template<int len, int beg_pos>
std::ostream &NumSequence<len, beg_pos>::Print(std::ostream &os) const
{
    int elem_cnt = len + beg_pos - 1;
    if (elem_cnt > pelems_->size())
        GenElems(elem_cnt);

    int elem_pos = beg_pos - 1;
    os << " (" << len << ", " << beg_pos << "): ";
    while (elem_pos < elem_cnt)
        os << (*pelems_)[elem_pos++] << ' ';
    os << std::endl;

    return os;
}

template<int len, int beg_pos>
bool NumSequence<len, beg_pos>::CheckIntegrity(int pos, int size) const
{
    if (pos <= 0 || pos >= max_elems_)
    {
        std::cerr << "invalid position: " << pos
             << " can not handle request!!"
             << std::endl;
        return false;
    }

    if (pos > size) GenElems(pos);

    return true;
}

}

}

#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
