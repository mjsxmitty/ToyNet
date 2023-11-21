
#ifndef __EFFECTIVE_CPP_ITEM_10_H__
#define __EFFECTIVE_CPP_ITEM_10_H__

namespace effective_item_10 {

class Widget
{
public:
    Widget& operator=(const Widget &rhs)
    {
        return *this;
    }

    Widget& operator+=(const Widget &rhs)
    {
        return *this;
    }

    Widget& operator-=(const Widget &rhs)
    {
        return *this;
    }
};

}

#endif // __EFFECTIVE_CPP_ITEM_10_H__
