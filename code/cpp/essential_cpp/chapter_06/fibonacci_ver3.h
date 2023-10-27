
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__

#include <vector>

#include "num_sequence_ver3.h"

namespace chapter_06
{

namespace ver3
{


template<int len, int beg_pos = 1>
class Fibonacci : public NumSequence<len, beg_pos>
{
public:
    Fibonacci() : NumSequence<len, beg_pos>(&elems_) { }
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

template<int len, int beg_pos>
std::vector<int>  Fibonacci<len, beg_pos>::elems_;

template<int len, int beg_pos>
void Fibonacci<len, beg_pos>::GenElems(int pos) const
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

}

}

#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_FIBONACCI_4_H__
