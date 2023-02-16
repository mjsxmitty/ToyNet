

#ifndef __ESSENTIAL_CPP_CHAPTER_06_H__
#define __ESSENTIAL_CPP_CHAPTER_06_H__

#include <functional>

namespace chapter_06
{

extern void ch_6_4();
extern void ch_6_6();

template<typename ElemType, typename Comp = std::less<ElemType>>
class LessThanPred
{
public:
    LessThanPred(const ElemType &val): val_(val){}

    bool operator()(const ElemType &val) const
    {
        return Comp(val, val_);
    }

    ElemType val() const
    {
        return val_;
    }

    void Val(const ElemType &val)
    {
        val_ = val;
    }

private:
    ElemType    val_;
};

class StringLess
{
public:
    bool operator()(const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }
};

//LessThanPred<int> ltpi(1024);
//LessThanPred<std::string, StringLess> ltps("1024");

template<typename NumSeq>
class NumSequenceVer6
{
public:
    NumSequenceVer6(int len = 1, int bp = 1) : ns_(len, bp) { }
    //
    bool IsElem(int pos) const { return ns_.IsElem(pos); }
protected:
    NumSeq    ns_;
};

template <typename OutStream>
class PrintIt
{
public:
    PrintIt(OutStream &os) : os_(os) {}

    template <typename ElemType>
    void Print(const ElemType &val, char ch = '\n')
    {
        os_ << val << ch;
    }
private:
    OutStream   &os_;
};

extern void ch_6_8();

}

#endif // __ESSENTIAL_CPP_CHAPTER_06_H__
