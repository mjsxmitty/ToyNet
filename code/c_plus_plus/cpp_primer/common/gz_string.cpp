
#include "gz_string.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

allocator<char> GZString::alloc;

ostream& operator<<(ostream &os, const GZString &rhs)
{
    os << rhs.p_;
    return os;
}

GZString& GZString::operator=(const GZString &rhs)
{
    auto new_ptr = alloc.allocate(rhs.sz_);
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = new_ptr;
    sz_ = rhs.sz_;

    return *this;
}

GZString& GZString::operator=(GZString &&rhs) noexcept
{
    if (this != &rhs)
    {
        if (p_)
            alloc.deallocate(p_, sz_);
        
        p_ = rhs.p_;
        sz_ = rhs.sz_;

        rhs.p_ = 0;
        rhs.sz_ = 0;
    }

    return *this;   
}

GZString& GZString::operator=(const char *p)
{
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = alloc.allocate(strlen(p));
    uninitialized_copy(p, p + strlen(p), p_);
    sz_ = strlen(p);

    return *this;
}

GZString& GZString::operator=(char c)
{
    if (p_)
        alloc.deallocate(p_, sz_);
    
    p_ = alloc.allocate(1);
    *p_ = c;
    sz_ = 1;

    return *this;
}

GZString& GZString::operator=(const initializer_list<char> &il)
{
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = alloc.allocate(il.size());
    uninitialized_copy(il.begin(), il.end(), p_);
    sz_ = il.size();

    return *this;
}

void GZString::Swap(GZString &rhs)
{
    auto p = p_;
    p_ = rhs.p_;
    rhs.p_ = p;

    auto sz = sz_;
    sz_ = rhs.sz_;
    rhs.sz_ = sz;
}


GZString operator+(const GZString &lhs, const GZString &rhs)
{
    GZString ret;
    ret.sz_ = lhs.sz_ + rhs.sz_;
    ret.p_ = GZString::alloc.allocate(ret.sz_);
    uninitialized_copy(lhs.Begin(), lhs.End(), ret.p_);
    uninitialized_copy(rhs.Begin(), rhs.End(), ret.p_ + lhs.sz_);
    return ret;
}
std::ostream& operator<=(std::ostream &os, const GZString &item)
{
    auto p = item.Begin();
    while (p != item.End())
        os << *p++;
    return os;
}
