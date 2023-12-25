
#ifndef __CHAPTER12_STR_H__
#define __CHAPTER12_STR_H__

#include "../chapter_11/vec.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

namespace chapter_12
{

class Str
{
    friend std::ostream& operator<<(std::ostream &, const Str&);
    friend std::istream& operator>>(std::istream &, Str &);
public:
    typedef Vec<char>::size_type size_type;

    Str(){}
    Str(size_type n, char c) : data(n, c){}
    Str(const char *cp) { std::copy(cp, cp + strlen(cp), std::back_inserter(data)); }

    template<typename In>
    Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }
public:
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type Size() const { return data.Size(); }
public:
    Str& operator+=(const Str &s)
    {
        std::copy(s.data.Begin(), s.data.End(), std::back_inserter(data));
        return *this;
    }

    operator void*()
    {
        return data.Begin();
    }
private:
    Vec<char>   data;
};

std::ostream& operator<<(std::ostream &, const Str&);
std::istream& operator>>(std::istream &, Str &);
Str operator+(const Str &lhs, const Str &rhs);

} // namespace chapter_12

#endif //__CHAPTER12_STR_H__
