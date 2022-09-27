
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__

#include <vector>
#include <iostream>

template <int len, int beg_pos>
class NumSequenceVer4
{
public:
    virtual ~NumSequenceVer4() {}
public:
    int             Elem(int pos);
    const char*     WhatAmI() const;
    static int      MaxElems() { return max_elems_; }
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    std::vector<int>    *pelems_;
    static const int    max_elems_ = 1024;
protected:
    NumSequenceVer4(std::vector<int> *pv) : pelems_(pv){}
protected:
    virtual void    GenElems(int pos) const = 0;
    bool            CheckIntegrity(int pos, int size) const;
};

template <int len, int beg_pos>
std::ostream& operator<<(std::ostream &os, const NumSequenceVer4<len, beg_pos> &ns);


template <void (*pf)(int pos, std::vector<int> &seq)>
class NumSequenceVer5
{
public:
    NumSequenceVer5(int len, int bp = 1)
    {
        if (!pf) return;

        len_ = len > 0 ? len : 1;
        beg_pos_ = bp > 0 ? bp : 1;

        pf(len_ + beg_pos_ - 1, elems_);
    }
protected:
    int                 len_;
    int                 beg_pos_;
    std::vector<int>    elems_;
};

void fibonacci(int pos, std::vector<int> &seq);

//NumSequenceVer5<fibonacci> numx(1);
//NumSequenceVer5<fibonacci> numy(12, 1);

#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
