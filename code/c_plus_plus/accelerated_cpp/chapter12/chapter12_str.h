

#ifndef __CHAPTER12_STR_H__
#define __CHAPTER12_STR_H__

#include "../chapter11/chapter11_vec.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using chapter11::Vec;

namespace chapter12
{
class Str
{
public:
    typedef Vec<char>::size_type size_type;

    Str(){}
    Str(size_type n, char c) : data(n, c){}
    Str(const char *cp) { std::copy(cp, cp + strlen(cp), std::back_inserter(data)); }

    template<typename In>
    Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }
private:
    Vec<char>   data;
};     
} // namespace chapter12




#endif //__CHAPTER12_STR_H__
