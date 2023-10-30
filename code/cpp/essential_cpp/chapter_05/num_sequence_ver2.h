

#ifndef __ESSENTIAL_CPP_NUM_SEQUENCE_VER2_H__
#define __ESSENTIAL_CPP_NUM_SEQUENCE_VER2_H__

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
    NumSequence(int len, int beg, std::vector<int> &re, const std::string &s);
    virtual ~NumSequence() {}
public:
    virtual NumSequence* Clone() = 0;
public:
    //virtual const char* WhatAmI() const = 0;
    virtual const char* WhatAmI() const
    {
        return typeid(*this).name();
        //return name_.c_str();
    }
    int                 Elem(int pos) const;
    std::ostream&       Print(std::ostream &os = std::cout) const;
    int                 Length() const { return length_; }
    int                 BegPos() const { return beg_pos_; }
    
    static int          MaxElems() { return 64; }
protected:
    virtual void        GenElems(int pos) const = 0;                // 
    bool                CheckIntegrity(int pos, int size) const;
protected:
    int                 length_;
    int                 beg_pos_;
    std::vector<int>    &relems_;   // 另一种实现(指针);但是需要检查指针是否为空;引用不需要检查
protected:
    std::string         name_;

    NumSequence& operator=(const NumSequence &rhs);
    NumSequence(const NumSequence &rhs);
};

inline void Display(std::ostream &os, const NumSequence &ns, int pos)
{
    os << "the element at position: " << pos
        << " for the " << ns.WhatAmI() << " sequence is "
        << ns.Elem(pos) << std::endl;
}

}
}
#endif // __ESSENTIAL_CPP_NUM_SEQUENCE_VER2_H__
