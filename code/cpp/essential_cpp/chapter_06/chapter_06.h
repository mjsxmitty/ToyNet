

#ifndef __ESSENTIAL_CPP_CHAPTER_06_H__
#define __ESSENTIAL_CPP_CHAPTER_06_H__

#include <functional>
#include <string>

namespace chapter_06
{
template<typename ElemType, typename Comp = std::less<ElemType> >
class LessThanPred
{
public:
    LessThanPred(const ElemType &val): val_(val){}

    bool operator()(const ElemType &val) const
    {
        return Comp()(val, val_);
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

}

#endif // __ESSENTIAL_CPP_CHAPTER_06_H__
