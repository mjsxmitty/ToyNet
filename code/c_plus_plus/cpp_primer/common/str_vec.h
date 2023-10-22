
#ifndef __CPP_PRIMER_STR_VEC_H__
#define __CPP_PRIMER_STR_VEC_H__

#include <string>
#include <memory>

class StrVec
{
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<std::string> &il);
    StrVec(const StrVec &rhs);
    StrVec(StrVec &&rhs) noexcept;
    StrVec& operator=(StrVec &&rhs) noexcept;
    StrVec& operator=(const StrVec &rhs);
    ~StrVec();
public:
    StrVec& operator=(const std::initializer_list<std::string> &il);

    std::string& operator[](std::size_t n) { return elements[n]; }
    const std::string& operator[](std::size_t n) const { return elements[n]; }
public:
    void            PushBack(const std::string &s);
    void            PushBack(std::string &&);
    size_t          Size()  const { return first_free - elements; }
    size_t          Capacity() const { return cap - elements; }
    std::string*    Begin() const { return elements; }
    std::string*    End() const { return first_free; }
public:
    void Reserve(size_t n);
    void Resize(size_t n);
    void Resize(size_t n, const std::string &s);
private:
    void CheckAlloc() { if (Size() == Capacity()) Reallocate(); }

    std::pair<std::string*, std::string*>
    AllocCopy(const std::string *beg, const std::string *end);
    void Free();
    void Reallocate();
    void Reallocate(size_t n);
private:
    static std::allocator<std::string> alloc;

    std::string *elements;      // 首元素位置
    std::string *first_free;    // 第一个空闲位置
    std::string *cap;           // 容量
};

bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator<=(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);
bool operator>=(const StrVec &lhs, const StrVec &rhs);

#endif // __CPP_PRIMER_STR_VEC_H__
