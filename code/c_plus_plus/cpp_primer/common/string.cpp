
#include "string.h"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

allocator<char> String::alloc;

ostream& operator<<(ostream &os, const String &rhs)
{
    os << rhs.p_;
    return os;
}

String& String::operator=(const String &rhs)
{
    auto new_ptr = alloc.allocate(rhs.sz_);
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = new_ptr;
    sz_ = rhs.sz_;

    return *this;
}

String& String::operator=(String &&rhs) noexcept
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

String& String::operator=(const char *p)
{
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = alloc.allocate(strlen(p));
    uninitialized_copy(p, p + strlen(p), p_);
    sz_ = strlen(p);

    return *this;
}

String& String::operator=(char c)
{
    if (p_)
        alloc.deallocate(p_, sz_);
    
    p_ = alloc.allocate(1);
    *p_ = c;
    sz_ = 1;

    return *this;
}

String& String::operator=(const initializer_list<char> &il)
{
    if (p_)
        alloc.deallocate(p_, sz_);

    p_ = alloc.allocate(il.size());
    uninitialized_copy(il.begin(), il.end(), p_);
    sz_ = il.size();

    return *this;
}

void String::Swap(String &rhs)
{
    auto p = p_;
    p_ = rhs.p_;
    rhs.p_ = p;

    auto sz = sz_;
    sz_ = rhs.sz_;
    rhs.sz_ = sz;
}


String operator+(const String &lhs, const String &rhs)
{
    String ret;
    ret.sz_ = lhs.sz_ + rhs.sz_;
    ret.p_ = String::alloc.allocate(ret.sz_);
    uninitialized_copy(lhs.Begin(), lhs.End(), ret.p_);
    uninitialized_copy(rhs.Begin(), rhs.End(), ret.p_ + lhs.sz_);
    return ret;
}
std::ostream& operator<=(std::ostream &os, const String &item)
{
    auto p = item.Begin();
    while (p != item.End())
        os << *p++;
    return os;
}
