

#ifndef __ACCELERATED_CPP_STR_H__
#define __ACCELERATED_CPP_STR_H__

#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

extern std::vector<std::string> Split(const std::string &s);
extern std::string::size_type Width(const std::vector<std::string>& v);
extern std::vector<std::string> Frame(const std::vector<std::string>& v);

extern std::vector<std::string> Vcat(const std::vector<std::string> &top, const std::vector<std::string> &bottom);
extern std::vector<std::string> Hcat(const std::vector<std::string> &left, const std::vector<std::string> &right);

inline bool IsSpace(char c) { return isspace(c); }
inline bool NotSpace(char c) { return !IsSpace(c); }

extern bool IsPalindrome(const std::string &s);

extern std::string::const_iterator UrlEnd(std::string::const_iterator b, std::string::const_iterator e);
extern std::string::const_iterator UrlBeg(std::string::const_iterator b, std::string::const_iterator e);
extern std::vector<std::string> FindUrls(const std::string &s);

extern std::map<std::string, std::vector<int>>
Xref(std::istream &in, std::vector<std::string> (*FindWords)(const std::string &str) = Split);

template<typename Out>
void Split(const std::string& str, Out out)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end())
    {
        i = std::find_if(i, str.end(), NotSpace);
        iter j = std::find_if(i, str.end(), IsSpace);

        if (i != str.end())
            *out++ = std::string(i, j);

        i = j;
    }
}

template<typename T>
T Max(const T &left, const T &right)
{
    return left > right ? left : right;
}

template<typename In, typename X>
In Find(In begin, In end, const X &x)
{
    while (begin != end && *begin != x)
        ++begin;

    return begin;
}

template<typename In, typename Out>
Out Copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;

    return dest;
}

template<typename For, typename X>
void Replace(For begin, For end, const X &x, const X &y)
{
    while (begin != end)
    {
        if ( *begin == x )
            *begin = y;

        ++begin;
    }
}

template<typename Bi>
void Reverse(Bi begin, Bi end)
{
    while ( begin != end)
    {
        --end;
        if ( begin != end )
            std::swap( *begin++, *end );
    }
}

template<typename Ran, typename X>
bool BinarySearch(Ran begin, Ran end, const X &x)
{
    while (begin < end)
    {
        Ran mid = begin + (end - begin) / 2;
        if (x < *mid)
            end = mid;
        else if (x > *mid)
            begin = mid + 1;
        else
            return true;
    }

    return false;
}

#endif //__ACCELERATED_CPP_STR_H__
