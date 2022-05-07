

#ifndef __ESSENTIAL_CPP_CHAPTER_05_NUM_SEQ3_H__
#define __ESSENTIAL_CPP_CHAPTER_05_NUM_SEQ3_H__

#include <vector>
#include <iostream>
#include <typeinfo>
class NumSeq3
{
    //friend std::ostream& operator<<(std::ostream &os, const NumSeq2 &ns);
public:
    NumSeq3& operator=(const NumSeq3 &rhs);
    virtual ~NumSeq3(){}
public:
    int             Length() const { return length_; }
    int             BegPos() const { return beg_pos_; }
    int             Elem(int pos) const;
    virtual const char* WhatAmI() const { return typeid(*this).name(); }
    // virtual const char*     WhatAmI() const = 0;//绾櫄鍑芥暟
    static int              max_elems() { return 64; }
    std::ostream&   Print(std::ostream &os = std::cout) const;

    virtual NumSeq3* Clone() = 0;
//protected:
public:
    virtual void    GenElems(int pos) const = 0; //绾櫄鍑芥暟
    bool    CheckIntegrity(int pos, int size) const;
protected:
    NumSeq3(int len, int beg, std::vector<int> &re, const std::string &s) : 
        length_(len), beg_pos_(beg), relems_(re), name_(s){}
private:
    int     length_;
    int     beg_pos_;

    std::string         name_;
    std::vector<int>    &relems_;   //point???
};


#endif //
