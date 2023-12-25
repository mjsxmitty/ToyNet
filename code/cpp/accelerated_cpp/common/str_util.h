

#ifndef __ACCELERATED_CPP_STR_H__
#define __ACCELERATED_CPP_STR_H__

#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

std::vector<std::string> Split(const std::string &s);
std::string::size_type Width(const std::vector<std::string>& v);
std::vector<std::string> Frame(const std::vector<std::string>& v);

std::vector<std::string> Vcat(const std::vector<std::string> &top, 
                                const std::vector<std::string> &bottom);
std::vector<std::string> Hcat(const std::vector<std::string> &left, 
                                const std::vector<std::string> &right);

inline bool IsSpace(char c) { return isspace(c); }
inline bool NotSpace(char c) { return !IsSpace(c); }

bool IsPalindrome(const std::string &s);

std::string::const_iterator UrlEnd(std::string::const_iterator b, std::string::const_iterator e);
std::string::const_iterator UrlBeg(std::string::const_iterator b, std::string::const_iterator e);
std::vector<std::string> FindUrls(const std::string &s);

template<typename Out>
void Split(const std::string& str, Out out)
{
    typedef std::string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end())
    {
        i = std::find_if(str.begin(), str.end(), NotSpace);
        iter j = std::find_if(str.begin(), str.end(), IsSpace);

        if (i != j)
            *out++ = std::string(i, j);

        i = j;
    }
}

std::map<std::string, std::vector<int>> Xref(std::istream &in,
        std::vector<std::string> (*FindWords)(const std::string &str) = Split);


#endif //__ACCELERATED_CPP_STR_H__
