
#ifndef __CHAPTER14_STR_H__
#define __CHAPTER14_STR_H__

#include "../chapter_11/vec.hpp"
#include "ptr.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

namespace chapter_14
{

// template<>
// chapter_11::Vec<char>* clone(const chapter_11::Vec<char> *vp)
// {
//     return new chapter_11::Vec<char>(*vp);
// }

class Str
{
    friend std::ostream& operator<<(std::ostream &, const Str&);
    friend std::istream& operator>>(std::istream &, Str &);
public:
    typedef chapter_11::Vec<char>::size_type size_type;

    Str() : data(new chapter_11::Vec<char>){}
    Str(size_type n, char c) : data(new chapter_11::Vec<char>(n, c)){}
    Str(const char *cp) : data(new chapter_11::Vec<char>)
    {
        std::copy(cp, cp + strlen(cp), std::back_inserter(*data)); 
    }

    template<typename In>
    Str(In b, In e) : data(new chapter_11::Vec<char>)
    {
        std::copy(b, e, std::back_inserter(*data)); 
    }
public:
    char& operator[](size_type i) 
    {
        return (*data)[i]; 
    }
    const char& operator[](size_type i) const { return (*data)[i]; }

    size_type Size() const { return data->Size(); }
public:
    Str& operator+=(const Str &s)
    {
        data.make_unique();
        std::copy(s.data->Begin(), s.data->End(), std::back_inserter(*data));
        return *this;
    }

    // operator void*()
    // {
    //     return data->Begin();
    // }
private:
    Ptr<chapter_11::Vec<char>>   data;
};

std::ostream& operator<<(std::ostream &, const Str&);
std::istream& operator>>(std::istream &, Str &);
Str operator+(const Str &lhs, const Str &rhs);

} // namespace chapter_12

#endif //__CHAPTER12_STR_H__
