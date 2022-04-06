

#ifndef __CHAPTER05_STR_H__
#define __CHAPTER05_STR_H__

#include <vector>
#include <string>

namespace Chapter05
{
    std::vector<std::string> Split(const std::string &s);
    std::string::size_type Width(const std::vector<std::string>& v);
    std::vector<std::string> Frame(const std::vector<std::string>& v);

    std::vector<std::string> Vcat(const std::vector<std::string> &top, const std::vector<std::string> &bottom);
    std::vector<std::string> Hcat(const std::vector<std::string> &left, const std::vector<std::string> &right);
} // namespace Chapter05


#endif //__CHAPTER05_STR_H__