

#ifndef __ACCELERATED_CPP_CHAPTER_06_STR_H__
#define __ACCELERATED_CPP_CHAPTER_06_STR_H__

#include <ctype.h>
#include <string>
#include <vector>

namespace chapter_06
{

std::vector<std::string> Split(const std::string& str);
bool IsPalindram(const std::string &s);
std::vector<std::string> FindUrls(const std::string& s);

} // namespace chapter_06



#endif //__ACCELERATED_CPP_CHAPTER_06_STR_H__