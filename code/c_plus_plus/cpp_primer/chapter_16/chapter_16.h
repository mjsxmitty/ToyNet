


#ifndef __CPP_PRIMER_CHAPTER_16_H__
#define __CPP_PRIMER_CHAPTER_16_H__

#include <functional>
#include <string.h>
#include <iostream>
#include <algorithm>

extern void ch_16();

extern void ch_16_1();
extern void ch_16_1_1();
extern void hw_16_4();
extern void hw_16_7();

extern void ch_16_1_2();


//template <typename T, typename F = std::less<T>>
//int Compare(const T &lhs, const T &rhs, F f = F())
//{
//    if (f(lhs, rhs)) return -1;
//    if (f(lhs, rhs)) return 1;
//    return 0;
//}


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
