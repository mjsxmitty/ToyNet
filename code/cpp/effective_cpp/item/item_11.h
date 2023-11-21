

#ifndef __EFFECTIVE_CPP_ITEM_11_H__
#define __EFFECTIVE_CPP_ITEM_11_H__

namespace effective_item_11 {

class BitMap {};
class Widget
{
    void Swap(Widget &rhs)
    {
        BitMap *tmp = pb_;
        pb_ = rhs.pb_;
        rhs.pb_ = tmp;
    }
public:
    Widget& operator=(const Widget &rhs)
    {
#if 0
        if (this == &rhs)   return *this;
        delete pb_;

        pb_ = new BitMap(*rhs.pb_);         // 可能引发异常
        return *this;
#endif
#if 0
        BitMap *pb = pb_;
        pb_ = new BitMap(*rhs.pb_);
        delete pb;
        return *this;
#endif
#if 1
        Widget temp(rhs);
        Swap(temp);
        return *this;
#endif
    }
public:
    BitMap *pb_;
};

}

#endif // __EFFECTIVE_CPP_ITEM_11_H__
