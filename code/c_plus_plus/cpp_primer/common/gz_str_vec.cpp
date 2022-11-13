

#include "gz_str_vec.h"
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

allocator<string> GZStrVec::alloc;

void GZStrVec::PushBack(const string &s)
{
    CheckAlloc();
    alloc.construct(first_free++, s);
}

pair<string*, string *>
GZStrVec::AllocCopy(const string *beg, const string *end)
{
    auto data = alloc.allocate(end - beg);
    //return {data, uninitialized_copy(beg, end, data)};
    return make_pair(data, uninitialized_copy(beg, end, data));
}

void GZStrVec::Free()
{
    if (!elements)
        return ;

    // for (auto p = first_free; p != elements; )
    //     alloc.destroy(--p);

    for_each(first_free, elements, [](string &s) { alloc.destroy(&s); });
    alloc.deallocate(elements, cap - elements);
}

GZStrVec::GZStrVec(const std::initializer_list<string> &il)
{
    auto new_data = AllocCopy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

GZStrVec::GZStrVec(const GZStrVec &rhs)
{
    cout << "GZStrVec copy construct func." << endl;
    auto new_data = AllocCopy(rhs.Begin(), rhs.End());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

GZStrVec::GZStrVec(GZStrVec &&rhs) noexcept : 
                    elements(rhs.elements),
                    first_free(rhs.first_free),
                    cap(rhs.cap)
{
    cout << "GZStrVec move construct func." << endl;
    elements = first_free = cap = nullptr;
}

GZStrVec& GZStrVec::operator=(GZStrVec &&rhs) noexcept
{
    cout << "GZStrVec move assign func." << endl;
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

GZStrVec::~GZStrVec()
{
    Free();
}

GZStrVec& GZStrVec::operator=(const GZStrVec &rhs)
{
    cout << "copy construct ..."<< endl;
    auto new_data = AllocCopy(rhs.Begin(), rhs.End());
    Free();

    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

GZStrVec& GZStrVec::operator=(const initializer_list<string> &il)
{
    auto ret = AllocCopy(il.begin(), il.end());
    Free();
    elements = ret.first;
    first_free = cap = ret.second;
    return *this;
}

void GZStrVec::Reallocate()
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


void GZStrVec::Reallocate(size_t n)
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

void GZStrVec::Reserve(size_t n)
{
    if (Capacity() > n)
        return ;

    Reallocate(n);
}

void GZStrVec::Resize(size_t n)
{
    if (n > Size())
        while (n > Size())
            PushBack("");
    else
        while (Size() > n)
            alloc.destroy(--first_free);    // 析构对象
}

void GZStrVec::Resize(size_t n, const string &s)
{
    if (n > Size())
        while (n > Size())
            PushBack(s);
    else
        while (Size() > n)
            alloc.destroy(--first_free);
}

/* 13.6.3 */
void GZStrVec::PushBack(std::string &&s)
{
    CheckAlloc();
    alloc.construct(first_free++, std::move(s));
}

/***************************************************************/
/***************************14.2********************************/

bool operator==(const GZStrVec &lhs, const GZStrVec &rhs)
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

bool operator!=(const GZStrVec &lhs, const GZStrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const GZStrVec &lhs, const GZStrVec &rhs)
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

bool operator<=(const GZStrVec &lhs, const GZStrVec &rhs)
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

bool operator>(const GZStrVec &lhs, const GZStrVec &rhs)
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

bool operator>=(const GZStrVec &lhs, const GZStrVec &rhs)
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