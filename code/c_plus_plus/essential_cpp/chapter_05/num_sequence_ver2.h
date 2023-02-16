

#ifndef __ESSENTIAL_CPP_CHAPTER_05_NUM_SEQUENCE_VER2_H__
#define __ESSENTIAL_CPP_CHAPTER_05_NUM_SEQUENCE_VER2_H__

#include <vector>
#include <iostream>
#include <typeinfo>

namespace chapter_05
{

namespace ver2
{

class NumSequence
{
public:
    virtual ~NumSequence() { }
public:
    //virtual const char* WhatAmI() const = 0;
    virtual const char* WhatAmI() const { return typeid(*this).name(); }
    int                 Elem(int pos) const;
    std::ostream&       Print(std::ostream &os = std::cout) const;

    int                 Length() const { return length_; }
    int                 BegPos() const { return beg_pos_; }
    
    static int          MaxElems() { return 64; }
protected:
    virtual void        GenElems(int pos) const = 0;                // 
    bool                CheckIntegrity(int pos, int size) const;

    NumSequence(int len, int beg, std::vector<int> &re, const std::string &s) :
                    length_(len), beg_pos_(beg), relems_(re), name_(s) { }
protected:
    int                 length_;
    int                 beg_pos_;
    std::vector<int>    &relems_;   // 另一种实现（指针）
protected:
    std::string         name_;

    NumSequence& operator=(const NumSequence &rhs);

public:
    virtual NumSequence* Clone() = 0;
};

}

}
#endif //
