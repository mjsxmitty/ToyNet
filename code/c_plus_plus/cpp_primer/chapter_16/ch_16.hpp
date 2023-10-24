
#ifndef __CPP_PRIMER_CH_16_HPP__
#define __CPP_PRIMER_CH_16_HPP__

#include <functional>
#include <iostream>

#if 0
template <typename T>
int Compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}
#endif

template <unsigned N, unsigned M>
int Compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

#if 0
template <typename T>
int Compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2)) return -1;
    if (std::less<T>()(v2, v1)) return 1;
    return 0;
}
#endif

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
    for (auto iter = std::begin(a); iter != std::end(a); iter++)
    for (auto iter = Begin(a) ;iter != End(a); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;


    for (size_t i = 0; i != ArrSize(a); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

namespace chapter_16 {

template <typename T>
class Foo
{
public:
    static std::size_t Count() { return ctr; }
private:
    static std::size_t  ctr;
};

template <typename T>
std::size_t Foo<T>::ctr = 0;

template <typename T>
typename T::value_type Top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
}

template <typename T, typename F = std::less<T>>
int Compare(const T &lhs, const T &rhs, F f = F())
{
    if (f(lhs, rhs)) return -1;
    if (f(lhs, rhs)) return 1;
    return 0;
}

template <typename T = int>
class Numbers
{
public:
    Numbers(T v = 0) : val_(v) {}
private:
    T   val_;
};

class DebugDelete
{
public:
    DebugDelete(std::ostream &os = std::cerr) : os_(os) {}

    template<typename T>
    void operator()(T *p) const {
        os_ << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os_;
};

};

#endif //__CPP_PRIMER_CH_16_HPP__
