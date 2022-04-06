


#ifndef __CPP_PRIMER_CHAPTER_16_H__
#define __CPP_PRIMER_CHAPTER_16_H__

#include <functional>
#include <string.h>
#include <iostream>
#include <algorithm>

void Chapter_16();

void Practice_16_1_1();
void Practice_16_1_2();

void Homework_16_4();
void Homework_16_5();


// template <typename T>
// int Compare(const T &v1, const T &v2)
// {
//     if (std::less<T>()(v1, v2)) return -1;
//     if (std::less<T>()(v2, v1)) return 1;
//     return 0;
// }

template <unsigned N, unsigned M>
int Compare(const char (&p1)[N], const char (&p2)[M])
{
    std::cout << "array compare ... " << std::endl;
    // std::cout << p1 << " " << p2 << std::endl;
    // std::cout <<strlen(p1) << " " << strlen(p2) << std::endl;
    // std::cout << sizeof(p1) << ", " << sizeof(p2) << std::endl;
    // std::cout << strcmp(p1, p2) << std::endl;
    return strcmp(p1, p2);
}

template <typename T, typename F = std::less<T>>
int Compare(const T &lhs, const T &rhs, F f = F())
{
    if (f(lhs, rhs)) return -1;
    if (f(lhs, rhs)) return 1;
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
    // for (auto iter = Begin(a) ;iter != End(a); iter++)
    // //for (auto iter = std::begin(a); iter != std::end(a); iter++)
    //     std::cout << *iter << " ";

    for (size_t i = 0; i != ArrSize(a); i++)
        std::cout << a[i] << " ";
    
    std::cout << std::endl;
}

/*
template <typename T> class Pal;
class C
{
    friend class Pal<C>;

    template <typename T> friend class Pal2;
};

template <typename T>
class C2
{
    friend T;

    friend class Pal<T>;

    template <typename Y> friend class Pal2;

    friend class Pal3;
};
*/
template <typename T>
class TFoo
{
public:
    static std::size_t Count() { return ctr; }
private:
    static std::size_t  ctr;
};

template <typename T>
std::size_t TFoo<T>::ctr = 0;

#endif //
