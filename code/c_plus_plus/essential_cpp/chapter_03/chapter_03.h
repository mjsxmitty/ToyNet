
#ifndef __ESSENTIAL_CPP_CHAPTER_03_H__
#define __ESSENTIAL_CPP_CHAPTER_03_H__

#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

extern void ch_3();

extern void ch_3_1();

extern const int* FindVec(const std::vector<int> &vec, int val);

template <typename T>
const T* FindVer1(const std::vector<T> &vec, T &val)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val)
            return &vec[i];

    return 0;
}

template <typename T>
const T* FindVer2(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++)
        if (array[ix] == val)
            return &array[ix];

    return 0;
}

template <typename T>
const T* FindVer3(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++, ++array)
        if (*array == val)
            return array;

    return 0;
}

template <typename T>
const T* FindVer4(const T *first, const T *last, T &val)
{
    if (!first || !last)
        return 0;

    for (;first != last; ++first)
        if (*first == val)
            return first;

    return 0;
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

extern void ch_3_2();

template <typename T, typename Y>
T FindVer5(T first, T last, const Y &val)
{
    for (; first != last; ++first)
        if (val == *first)
            return first;

    return last;
}

extern void ch_3_6();

std::vector<int> FilterVer1(const std::vector<int> &vec, int filter_val, bool (*pred)(int, int));
std::vector<int> FilterVer2(const std::vector<int> &vec, int val, const std::less<int> &lt);

template <typename It,          typename Ot,
          typename ElemType,    typename Comp>
Ot FilterVer3( It first, It last, Ot at, const ElemType &val, Comp pred )
{
    while (( first = find_if( first, last, not1(bind2nd( pred, val )))) != last )
    {
        std::cout << "found val: " << *first << std::endl;
        *at++ = *first++;
    }

    return at;
}

extern std::vector<int> SubVec(const std::vector<int> &vec, int val);

template <typename It,          typename Ot,
          typename ElemType,    typename Comp>
void Filter(It first, It last, Ot at, const ElemType &val, Comp pre)
{
    //排序
    std::vector<ElemType> local_vec(first, last);
    std::sort(local_vec.begin(), local_vec.end());

    //找出第一满足要求值
    auto it = find_if(local_vec.begin(), local_vec.end(), bind2nd(pre, val));
    while (it != local_vec.end() )
    {
        *at++ = *it++;
    }
}

extern void ch_3_9();

void Chapter_03();

void Practice_3_1();
void Practice_3_6();
void Practice_3_9();

void Homework_3_1();
void Homework_3_2();
void Homework_3_3();
void Homework_3_4();



#endif //
