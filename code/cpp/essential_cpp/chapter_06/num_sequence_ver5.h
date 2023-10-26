
#ifndef __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_5_H__
#define __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_5_H__

#include <vector>
#include <iostream>

namespace chapter_06
{

namespace ver5
{

template<typename NumSeq>
class NumSequence
{
public:
    NumSequence(int len = 1, int bp = 1) : ns_(len, bp) { }
    //
    bool IsElem(int pos) const { return ns_.IsElem(pos); }
protected:
    NumSeq    ns_;
    //NumSeq    *ptr_;
};
}

}

#endif // __ESSENTIAL_CPP_CHAPTER_UTIL_NUM_SEQUENCE_4_H__
