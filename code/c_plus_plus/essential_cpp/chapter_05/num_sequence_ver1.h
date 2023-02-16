
#ifndef __CHAPTER_05_NumSequence_H__
#define __CHAPTER_05_NumSequence_H__

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
    virtual bool            CheckIntegrity(int pos, int size) const;
protected:
    //const static int max_elems_ = 1024;
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
#endif //
