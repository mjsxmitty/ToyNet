

#include "str_vec.h"
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

allocator<string> StrVec::alloc;

void StrVec::PushBack(const string &s)
{
    CheckAlloc();
    alloc.construct(first_free++, s);
}

pair<string*, string *>
StrVec::AllocCopy(const string *beg, const string *end)
{
    auto data = alloc.allocate(end - beg);
    //return {data, uninitialized_copy(beg, end, data)};
    return make_pair(data, uninitialized_copy(beg, end, data));
}

void StrVec::Free()
{
    if (!elements)
        return ;

    // for (auto p = first_free; p != elements; )
    //     alloc.destroy(--p);

    for_each(first_free, elements, [](string &s) { alloc.destroy(&s); });
    alloc.deallocate(elements, cap - elements);
}

StrVec::StrVec(const std::initializer_list<string> &il)
{
    auto new_data = AllocCopy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

StrVec::StrVec(const StrVec &rhs)
{
    cout << "StrVec copy construct func." << endl;
    auto new_data = AllocCopy(rhs.Begin(), rhs.End());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept : 
                    elements(rhs.elements),
                    first_free(rhs.first_free),
                    cap(rhs.cap)
{
    cout << "StrVec move construct func." << endl;
    elements = first_free = cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    cout << "StrVec move assign func." << endl;
    if (this != &rhs)
    {
        Free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    Free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    cout << "copy construct ..."<< endl;
    auto new_data = AllocCopy(rhs.Begin(), rhs.End());
    Free();

    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

StrVec& StrVec::operator=(const initializer_list<string> &il)
{
    auto ret = AllocCopy(il.begin(), il.end());
    Free();
    elements = ret.first;
    first_free = cap = ret.second;
    return *this;
}

void StrVec::Reallocate()
{
    auto new_size = (Size() > 0 ? Size() * 2 : 1);
    auto new_data = alloc.allocate(new_size);

    // auto dest = new_data;
    // auto elem = elements;
    // for (size_t i = 0; i != Size(); ++i)
    //     alloc.construct(dest++, std::move(*elem++));    // 显示调用string的移动构造函数(避免copy)

    auto dest = uninitialized_copy(make_move_iterator(Begin()),
                                    make_move_iterator(End()),
                                    new_data);

    Free();  // 释放远内存

    elements = new_data;
    first_free = dest;
    cap = elements + new_size;
}

void StrVec::Reallocate(size_t n)
{
    auto new_data = alloc.allocate(n);

    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != n; ++i)
        alloc.construct(dest++, std::move(*elem++));

    Free();

    elements = new_data;
    first_free = dest;
    cap = elements + n;
}

void StrVec::Reserve(size_t n)
{
    if (Capacity() > n)
        return ;

    Reallocate(n);
}

void StrVec::Resize(size_t n)
{
    if (n > Size())
        while (n > Size())
            PushBack("");
    else
        while (Size() > n)
            alloc.destroy(--first_free);    // 析构对象
}

void StrVec::Resize(size_t n, const string &s)
{
    if (n > Size())
        while (n > Size())
            PushBack(s);
    else
        while (Size() > n)
            alloc.destroy(--first_free);
}

void StrVec::PushBack(std::string &&s)
{
    CheckAlloc();
    alloc.construct(first_free++, std::move(s));
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.Size() != rhs.Size())
        return false;

    for (auto iter1 = lhs.Begin(), iter2 = rhs.Begin();
        iter1 != lhs.End() && iter2 != rhs.End();
        iter1++, iter2++)
    {
        if (*iter1 != *iter2)
            return false;
    }

    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
    for (;ps1 != lhs.End() && ps2 != rhs.End();
        ps1++, ps2++)
    {
        if (*ps1 < *ps2)
            return true;
        else
            return false;
    }

    if (ps1 == lhs.End() && ps2 != rhs.End()) 
        return true;

    return false; 
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
    for (;ps1 != lhs.End() && ps2 != rhs.End();
        ps1++, ps2++)
    {
        if (*ps1 < *ps2)
            return true;
        else
            return false;
    }

    if (ps1 == lhs.End()) 
        return true;

    return false; 
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
    for (;
         ps1 != lhs.End() && ps2 != rhs.End();
        ps1++, ps2++)
    {
        if (*ps1 > *ps2)
            return true;
        else
            return false;
    }

    if (ps1 != lhs.End() || ps2 == rhs.End()) 
        return true;

    return false; 
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    auto ps1 = lhs.Begin(), ps2 = rhs.Begin();
    for (;
         ps1 != lhs.End() && ps2 != rhs.End();
        ps1++, ps2++)
    {
        if (*ps1 > *ps2)
            return true;
        else
            return false;
    }

    if (ps2 == rhs.End()) 
        return true;

    return false; 
}