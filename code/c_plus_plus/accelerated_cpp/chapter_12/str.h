
#ifndef __CHAPTER12_STR_H__
#define __CHAPTER12_STR_H__

#include "../chapter_11/Vec.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

namespace chapter_12
{

class Str
{
public:
    typedef chapter_11::Vec<char>::size_type size_type;

    Str(){}
    Str(size_type n, char c) : data(n, c){}
    Str(const char *cp) { std::copy(cp, cp + strlen(cp), std::back_inserter(data)); }

    template<typename In>
    Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }
public:
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
private:
    chapter_11::Vec<char>   data;
};

} // namespace chapter12

#endif //__CHAPTER12_STR_H__
