
#ifndef __ESSENTIAL_CPP_SEQUENCE4_H__
#define __ESSENTIAL_CPP_SEQUENCE4_H__

#include <vector>
#include <iostream>

namespace chapter_06
{
namespace ver4
{

template <void (*pf)(int pos, std::vector<int> &seq)>
class NumSequence
{
    friend std::ostream& operator<<(std::ostream &os, const NumSequence<pf> &ns);
public:
    NumSequence(int len, int bp = 1)
    {
        if (!pf) return;

        len_ = len > 0 ? len : 1;
        beg_pos_ = bp > 0 ? bp : 1;

        pf(len_ + beg_pos_ - 1, seq_);       //
    }

    std::ostream& Print(std::ostream &os = std::cout);
protected:
    int                 len_;
    int                 beg_pos_;
    std::vector<int>    seq_;
};

template<void (*pf)(int pos, std::vector<int> &seq)>
std::ostream& NumSequence<pf>::Print(std::ostream &os)
{
    os << " (" << len_ << ", " << beg_pos_ << "): ";
    int elem_pos = beg_pos_ - 1;
    int elem_cnt = len_ + beg_pos_ - 1;
    while (elem_pos < elem_cnt)
        os << seq_[elem_pos++] << ' ';
}

template<void (*pf)(int pos, std::vector<int> &seq)>
std::ostream& operator<<(std::ostream &os, NumSequence<pf> &ns)
{
    ns.Print(os);
    return os;
}

}
}

#endif // __ESSENTIAL_CPP_SEQUENCE4_H__
