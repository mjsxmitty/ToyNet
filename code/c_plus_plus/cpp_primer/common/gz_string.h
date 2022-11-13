
#ifndef __CPP_PRIMER_CHAPTER_13_GZString_H__
#define __CPP_PRIMER_CHAPTER_13_GZString_H__

#include <cstddef>
#include <memory>
#include <string.h>
#include <iostream>

class GZString
{
    friend bool operator>(const GZString &lhs, const GZString &rhs);
    friend bool operator>=(const GZString &lhs, const GZString &rhs);
    friend bool operator<(const GZString &lhs, const GZString &rhs);
    friend bool operator<=(const GZString &lhs, const GZString &rhs);
    friend bool operator==(const GZString &lhs, const GZString &rhs);
    friend bool operator!=(const GZString &lhs, const GZString &rhs);
    friend GZString operator+(const GZString &lhs, const GZString &rhs);
    friend std::ostream& operator<=(std::ostream &os, const GZString &item);

    friend std::ostream& operator<<(std::ostream &, const GZString &);
public:
    GZString() = default;
    GZString(const char *cp) : 
                sz_(strlen(cp)), p_(alloc.allocate(sz_))
                {std::uninitialized_copy(cp, cp + sz_, p_);}
    GZString(const GZString &s) : 
                sz_(s.sz_), p_(alloc.allocate(s.sz_))
                { std::uninitialized_copy(s.p_, s.p_ + sz_, p_); }
    GZString(GZString &&rhs) noexcept : sz_(rhs.Size()), p_(rhs.p_) { rhs.p_ = 0; rhs.sz_ = 0; }
    GZString(size_t n, char c) : sz_(n), p_(alloc.allocate(n)) { std::uninitialized_fill_n(p_, n, c); }
    ~GZString() noexcept {if (p_) alloc.deallocate(p_, sz_); }
    GZString& operator=(const GZString &rhs);
    GZString& operator=(GZString &&rhs) noexcept;
    GZString& operator=(const char *p);
    GZString& operator=(char c);
    GZString& operator=(const std::initializer_list<char> &il);
    char& operator[](std::size_t n) { return p_[n]; }
    const char& operator[](std::size_t n) const { return p_[n]; }
public:
    std::size_t Size() const { return sz_; }

    const char* Begin() const { return p_; }
    char* Begin() { return p_; }
    const char* End() const { return p_ + sz_; }
    char* End() { return p_ + sz_; }

    void Swap(GZString &rhs);
private:
    std::size_t sz_ = 0;
    char        *p_ = nullptr;

    static std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream &os, const GZString &s);

inline void Swap(GZString &lhs, GZString &rhs)
{
    lhs.Swap(rhs);
}


GZString operator+(const GZString &lhs, const GZString &rhs);
std::ostream& operator<=(std::ostream &os, const GZString &item);


bool operator==(const GZString &lhs, const GZString &rhs)
{
    return strcmp(lhs.p_, rhs.p_);
}

bool operator!=(const GZString &lhs, const GZString &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const GZString &lhs, const GZString &rhs)
{
    return !(lhs < rhs);
}
bool operator>=(const GZString &lhs, const GZString &rhs)
{
    return !(lhs <= rhs);
}

bool operator<(const GZString &lhs, const GZString &rhs)
{
    return strcmp(lhs.p_, rhs.p_) < 0;
}

bool operator<=(const GZString &lhs, const GZString &rhs)
{
    return strcmp(lhs.p_, rhs.p_) <= 0;
}

#endif
