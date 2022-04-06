

#include "str_vec.h"

#include <memory>
#include <algorithm>

using std::initializer_list;
using namespace std;

allocator<string> StrVec::alloc;

StrVec::StrVec(const std::initializer_list<string> &il)
{
    auto new_data = AllocCopy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

StrVec::StrVec(const StrVec &rhs)
{
    auto new_data = AllocCopy(rhs.Begin(), rhs.End());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept : 
                    elements(rhs.elements),
                    first_free(rhs.first_free),
                    cap(rhs.cap)
{
    elements = first_free = cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
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

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
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

void StrVec::PushBack(const std::string &s)
{
    CheckAlloc();
    alloc.construct(first_free++, s);
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
            alloc.destroy(--first_free);
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

void StrVec::Reallocate()
{
    auto new_size = (Size() > 0 ? Size() * 2 : 1);
    auto new_data = alloc.allocate(new_size);

    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != Size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    Free();

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

void StrVec::Free()
{
    if (!elements)
        return ;

    // for (auto it = first_free; it != elements; )
    //     alloc.destroy(it--);
    for_each(first_free, elements, [](string &s) {alloc.destroy(&s);});
    alloc.deallocate(elements, cap - elements);
}

pair<string*, string *> StrVec::AllocCopy(const string *beg, const string *end)
{
    auto data = alloc.allocate(end - beg);
    //return {data, uninitialized_copy(beg, end, data)};
    return make_pair(data, uninitialized_copy(beg, end, data));
}
