

#ifndef __CHAPTER06_STR_H__
#define __CHAPTER06_STR_H__

#include <ctype.h>
#include <string>
#include <vector>

namespace Chapter06
{
std::vector<std::string> Split(const std::string& str);
bool IsPalindram(const std::string &s);
std::vector<std::string> FindUrls(const std::string& s);
} // namespace Chapter06



#endif //__CHAPTER06_STR_H__