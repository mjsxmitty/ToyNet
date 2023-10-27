

#ifndef __ACCELERATED_CPP_CHAPTER_06_STR_H__
#define __ACCELERATED_CPP_CHAPTER_06_STR_H__

#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>

namespace chapter_06
{
inline bool IsSpace(char c) { return isspace(c); }
inline bool NotSpace(char c) { return !IsSpace(c); }

std::vector<std::string> Split(const std::string& str);
bool IsPalindram(const std::string &s);
std::vector<std::string> FindUrls(const std::string& s);


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

} // namespace chapter_06



#endif //__ACCELERATED_CPP_CHAPTER_06_STR_H__
