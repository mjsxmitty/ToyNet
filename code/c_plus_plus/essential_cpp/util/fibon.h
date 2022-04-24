
#ifndef __CHAPTER_05_FIBONACCI_H__
#define __CHAPTER_05_FIBONACCI_H__

#include <vector>
#include <iostream>

#include "num_seq2.h"

class Fibon : public NumSeq2
{
public:
    Fibon(int len = 1, int beg = 1) :
        length_(len), beg_pos_(beg){}
public:
    int             Length() const { return length_; }
    int             BegPos() const { return beg_pos_; }
    int             Elem(int pos) const;
    const char*     WhatAmI() const;
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    void            GenElems(int pos) const;
private:
    int                     length_;
    int                     beg_pos_;

    static std::vector<int> elems_;
};

#endif //