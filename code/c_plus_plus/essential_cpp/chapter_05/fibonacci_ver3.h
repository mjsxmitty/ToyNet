

#ifndef __ESSENTIAL_CPP_CHAPTER_05_FibonacciVer3_H__
#define __ESSENTIAL_CPP_CHAPTER_05_FibonacciVer3_H__

#include <vector>

#include "num_sequence_ver3.h"

class FibonacciVer3 : public NumSequenceVer3
{
public:
    FibonacciVer3(int len = 1, int beg = 1);
    // const char* WhatAmI() const { return "fibonacci"; }
    // const char* WhatAmI() { return "fibonacci"; }
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
public:
    FibonacciVer3(const FibonacciVer3 &rhs);
    FibonacciVer3& operator=(const FibonacciVer3 &rhs);

public:    
    FibonacciVer3* Clone() { return new FibonacciVer3(*this); }
};

#endif //
