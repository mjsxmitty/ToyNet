
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__

#include <vector>

#include "num_sequence_ver4.h"

template<int len, int beg_pos = 1>
class FibonacciVer4 : public NumSequenceVer4<len, beg_pos>
{
public:
    FibonacciVer4() : NumSequenceVer4<len, beg_pos>(&elems_) { }
    // TODO ...copy
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

template<int len, int beg_pos>
std::vector<int>  FibonacciVer4<len, beg_pos>::elems_;

template<int len, int beg_pos>
void FibonacciVer4<len, beg_pos>::GenElems(int pos) const
{
    if (elems_.empty())
    {
        elems_.push_back(1);
        elems_.push_back(1);
    }

    if(elems_.size() <= pos)
    {
        int ix = elems_.size();
        int n2 = elems_[ix - 2];
        int n1 = elems_[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            elems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}


#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__
