
#ifndef __CHAPTER_05_FibonacciVer2ACCI_H__
#define __CHAPTER_05_FibonacciVer2ACCI_H__

#include <vector>
#include <iostream>

#include "num_sequence_ver2.h"

class FibonacciVer2 : public NumSequenceVer2
{
public:
    FibonacciVer2(int len = 1, int beg = 1) :
                    length_(len), beg_pos_(beg) { }
public:
    int             Length() const { return length_; }
    int             BegPos() const { return beg_pos_; }

    int             Elem(int pos) const;
    const char*     WhatAmI() const;
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    void            GenElems(int pos) const;
protected:
    static std::vector<int> elems_;
    int                     length_;
    int                     beg_pos_;    
};

#endif //
