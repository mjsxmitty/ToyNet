
#ifndef __ESSENTIAL_CPP_NUM_SEQUENCE_VER1_H__
#define __ESSENTIAL_CPP_NUM_SEQUENCE_VER1_H__

#include <iostream>

namespace chapter_05
{

namespace ver1
{

class NumSequence
{
    friend std::ostream& operator<<(std::ostream &os, const NumSequence &ns);
public:
    virtual ~NumSequence(){}
public:
    virtual int             Length() const = 0;
    virtual int             BegPos() const = 0;
    virtual int             Elem(int pos) const = 0;
    virtual const char*     WhatAmI() const = 0;
    virtual std::ostream&   Print(std::ostream &os = std::cout) const = 0;

    static int              max_elems() { return max_elems_; }
protected:
    virtual void            GenElems(int pos) const = 0;
    bool                    CheckIntegrity(int pos, int size) const;
protected:
    enum { max_elems_ = 1024 };
};

std::ostream& operator<<(std::ostream &os, const NumSequence &ns);

inline void Display(std::ostream &os, const NumSequence &ns, int pos)
{
    os << "the element at position: " << pos
        << " for the " << ns.WhatAmI() << " sequence is "
        << ns.Elem(pos) << std::endl;
}

}
}
#endif // __ESSENTIAL_CPP_NUM_SEQUENCE_VER1_H__
