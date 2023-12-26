
#ifndef __ACCELERATED_CPP_STR_H__
#define __ACCELERATED_CPP_STR_H__

#include "vec.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

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

#include "handle.hpp"

class Str2
{
    friend std::ostream& operator<<(std::ostream &, const Str&);
    friend std::istream& operator>>(std::istream &, Str &);
public:
    typedef Vec<char>::size_type size_type;

    Str2() : data(new Vec<char>){}
    Str2(size_type n, char c) : data(new Vec<char>(n, c)){}
    Str2(const char *cp) : data(new Vec<char>) { std::copy(cp, cp + strlen(cp), std::back_inserter(*data)); }
    template<typename In>
    Str2(In b, In e) : data(new Vec<char>) { std::copy(b, e, std::back_inserter(*data)); }
    Str2& operator=(const Str2 &rhs)
    {
        data.make_unique();
        std::copy(rhs.data->Begin(), rhs.data->End(), std::back_inserter(*data));
        return *this;
    }
public:
    char& operator[](size_type i)
    {
        data.make_unique();
        return (*data)[i];
    }
    const char& operator[](size_type i) const { return (*data)[i]; }

    size_type Size() const { return data->Size(); }

    operator void*()
    {
        return (*data).Begin();
    }
private:
    Ptr<Vec<char>>   data;
};

#endif //__ACCELERATED_CPP_STR_H__
