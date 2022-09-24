
/* 面向对象的数列类 */

#ifndef __CHAPTER_05_NumSequenceVer2_H__
#define __CHAPTER_05_NumSequenceVer2_H__

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
    virtual void    GenElems(int pos) const = 0;
    virtual bool    CheckIntegrity(int pos, int size) const;
protected:
    //const static int max_elems_ = 1024;
    enum { max_elems_ = 1024 };
};

std::ostream& operator<<(std::ostream &os, const NumSequenceVer2 &ns);

#endif //
