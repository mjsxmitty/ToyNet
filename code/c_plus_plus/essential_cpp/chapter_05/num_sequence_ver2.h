
#ifndef __CHAPTER_05_NUMSEQUENCEVER2_H__
#define __CHAPTER_05_NUMSEQUENCEVER2_H__

#include <iostream>

class NumSequenceVer2
{
    friend std::ostream& operator<<(std::ostream &os, const NumSequenceVer2 &ns);
public:
    virtual ~NumSequenceVer2(){}
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

std::ostream& operator<<(std::ostream &os, const NumSequenceVer2 &ns);

inline void Display(std::ostream &os, const NumSequenceVer2 &ns, int pos)
{
    os << "the element at position: " << pos
       << " for the " << ns.WhatAmI() << " sequence is "
       << ns.Elem(pos) << std::endl;

    ns.Print();
}

#endif //
