
#ifndef __ESSENTIAL_CPP_COMMON_H__
#define __ESSENTIAL_CPP_COMMON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <map>

#include "num_sequence.h"

namespace common
{

extern bool PrintFibon(int pos);

extern void Swap(int &val1, int &val2, std::ostream &out = std::cout);
extern void BubbleSort(std::vector<int> &vec, std::ostream &out = std::cout);
extern void Display(const std::vector<int> &vec, std::ostream &out = std::cout);

extern void Swap(int &val1, int &val2, std::ostream *out = 0);
extern void BubbleSort(std::vector<int> *vec, std::ostream *out = 0);
extern void Display(const std::vector<int> *vec, std::ostream *out = 0);

extern const std::vector<int>* FibonSeq(int size);
extern bool FibonElem(int size, int &elem);

extern void DisplayMsg(const std::string &);
extern void DisplayMsg(const std::string &, int);

inline bool IsSizeOk(int size)
{
    const int           max_elems = 1024;
    const std::string   msg("requested size is not supported.");

    if (size <= 0 || size > max_elems)
    {
        DisplayMsg(msg, size);
        return false;
    }

    return true;
}

template <typename ElemType>
void DisplayMessage(const std::string &msg, const std::vector<ElemType> &vec)
{
    std::cout << msg << " : ";
    for (auto &tmp : vec)
        std::cout << tmp << ' ';

    std::cout << std::endl;
}

template <typename T>
inline T Max(T t1, T t2) { return t1 > t2 ? t1 : t2; }

template <typename T>
inline T Max(const std::vector<T> &vec)
{
    return *std::max_element(vec.begin(), vec.end());   // max_element返回的是位置
}

template <typename T>
inline T Max(const T *arr, int size)
{
    return *std::max_element(arr, arr + size);
}

template <typename T>
inline const T* Begin(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}

template <typename T>
inline const T* End(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[vec.size()];
}

template <typename T, typename Y>
T Find(T first, T last, const Y &val)
{
    for (; first != last; ++first)
        if (val == *first)
            return first;

    return last;
}

extern std::vector<int> FilterVer(const std::vector<int> &vec, int filter_val, bool (*pred)(int, int));
extern std::vector<int> FilterVer(const std::vector<int> &vec, int val, const std::less<int> &lt);

template <typename It, typename Ot, typename ElemType,typename Comp>
Ot Filter( It first, It last, Ot at, const ElemType &val, Comp pred )
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    //while (( first = find_if( first, last, not1(bind2nd( pred, val )))) != last )
    {
        std::cout << "found val: " << *first << std::endl;
        *at++ = *first++;
    }

    return at;
}

extern std::vector<int> SubVec(const std::vector<int> &vec, int val);

template <typename T, typename V, typename Comp>
void SubVec(T beg, T end, V val, Comp cmp, T &first, T &last)
{
    //排序
    sort(beg, end); // 有局限性

    //找出第一满足要求值
    auto find_it = std::find_if(beg, end, std::bind2nd(cmp, val));

    first = beg;
    last = find_it;
}

extern void InitExclusionSet(std::set<std::string> &exs);
extern void ProcessFile(std::map<std::string, int> &word_map, const std::set<std::string> &exclude_set, std::ifstream &ifile);
extern void DisplayWordCount(const std::map<std::string, int> &word_map, std::ostream &out = std::cout);
extern void UserQuery(const std::map<std::string, int> &word_map);
class StrSizeComp
{
public:
    bool operator()(const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }
};

typedef std::vector<std::string> vstring;
typedef std::string::size_type ssize_type;
typedef std::map<std::string, vstring> svec_map;

extern void InitFamilyMap(std::ifstream &in, std::map<std::string, vstring> &family);
extern void DisplayMap(const std::map<std::string, vstring> &familes, std::ostream &out);
extern void QueryMap(const std::string &family, svec_map familes);

class EvenElem
{
public:
    bool operator()(const std::string &s)
    {
        return s.size() % 2 ? false : true;
    }
};

class LessThanObj
{
public:
    LessThanObj(int val) : val_(val) {}
    bool operator()(int nval) const;
private:
    int val_;
};

inline bool LessThanObj::operator()(int val) const
{
    return val < val_;
}

extern int CountLessThan(const std::vector<int> &vec, int comp);
extern int SumLessThan(const std::vector<int> &vec, int comp);
extern void PrintLessThan(const std::vector<int> &vec, int comp, std::ostream &os = std::cout);

}

#endif //__ESSENTIAL_CPP_COMMON_H__
