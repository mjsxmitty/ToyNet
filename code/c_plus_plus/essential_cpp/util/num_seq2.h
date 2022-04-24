
#ifndef __CHAPTER_05_NUMSEQ2_H__
#define __CHAPTER_05_NUMSEQ2_H__

#include <iostream>

class NumSeq2
{
    friend std::ostream& operator<<(std::ostream &os, const NumSeq2 &ns);
public:
    virtual ~NumSeq2(){}
public:
    virtual int             Length() const = 0;
    virtual int             BegPos() const = 0;
    virtual int             Elem(int pos) const = 0;
    virtual const char*     WhatAmI() const = 0;
    static int              max_elems() { return max_elems_; }
    virtual std::ostream&   Print(std::ostream &os = std::cout) const = 0;
protected:
    virtual void    GenElems(int pos) const = 0;
    virtual bool    CheckIntegrity(int pos, int size) const;
protected:
    const static int max_elems_ = 1024;
};

std::ostream& operator<<(std::ostream &os, const NumSeq2 &ns);

#endif //
