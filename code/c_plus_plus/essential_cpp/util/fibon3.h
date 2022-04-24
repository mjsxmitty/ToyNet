

#ifndef __ESSENTIAL_CPP_CHAPTER_05_FIBON3_H__
#define __ESSENTIAL_CPP_CHAPTER_05_FIBON3_H__

#include <vector>

#include "num_seq3.h"

class Fibon3 : public NumSeq3
{
public:
    Fibon3(const Fibon3 &rhs);
    Fibon3& operator=(const Fibon3 &rhs);
public:
    Fibon3(int len = 1, int beg = 1);
    // const char* WhatAmI() const { return "fibonacci"; }
    //const char* WhatAmI() { return "fibonacci"; }

    Fibon3* Clone() { return new Fibon3(*this); }
private:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

#endif //