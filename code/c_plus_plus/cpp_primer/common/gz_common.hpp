
#ifndef __CPP_PRIMER_GZ_COMMON_H__
#define __CPP_PRIMER_GZ_COMMON_H__

#include <functional>
#include <iostream>

//template <typename T>
//int Compare(const T &v1, const T &v2)
//{
//    if (v1 < v2) return -1;
//    if (v1 > v2) return 1;
//    return 0;
//}

// 特定类型名;表示一个值;常量表达式初始化
template <unsigned N, unsigned M>
int Compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template <typename T>
int Compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}

template <typename I, typename T>
I Find(I b, I e, const T &v)
{
    while (b != e && *b != v)
        b++;

    return b;
}

template <typename T, size_t N>
const T* Begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
const T* End(const T (&a)[N])
{
    return &a[0] + N;
}

template <typename T, size_t N>
constexpr size_t ArrSize(const T (&a)[N])
{
    return N;
}

template <typename T, size_t N>
void Print(const T (&a)[N])
{
//     for (auto iter = std::begin(a); iter != std::end(a); iter++)
//     for (auto iter = Begin(a) ;iter != End(a); iter++)
//         std::cout << *iter << " ";

    for (size_t i = 0; i != ArrSize(a); i++)
        std::cout << a[i] << "\n";
    std::cout << std::endl;
}

#endif //__CPP_PRIMER_GZ_COMMON_H__
