
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__

#include <vector>
#include <iostream>

namespace chapter_06
{

namespace ver4
{

void fibonacci(int pos, std::vector<int> &seq);

template <void (*pf)(int pos, std::vector<int> &seq)>
class NumSequence
{
public:
    NumSequence(int len, int bp = 1)
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

}

}

#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
