

#ifndef __CHAPTER11_VEC_H__
#define __CHAPTER11_VEC_H__

#include <cstddef>
#include <memory>

namespace chapter11
{
template<typename T>
class Vec
{
public:
    typedef T*          iterator;
    typedef const T*    const_iterator;
    typedef size_t      size_type;
    typedef T           value_type;
public:
    Vec() { Create(); }
    explicit Vec(size_type n, const T &val = T()) { Create(n, val); }

    Vec(const Vec &v) { Creat(v.Begin(), v.End()); }
    Vec& operator=(const Vec &v);
    ~Vec() { UnCreate(); }
public:
    size_type Size() const { return limit - data;}
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    iterator Begin() { return data; }
    const_iterator Begin() const { return data; }
    iterator End() { return limit; }
    const_iterator End() const { return limit; }

    void PushBack(const T &val);
private:
    void Create();
    void Create(size_type n, const T &val);
    void Create(const_iterator, const_iterator);

    void UnCreate();
    
    void Grow();
    void UncheckedAppend(const T &val);

    std::allocator<T>   Alloc;
private:
    T*  data;
    T*  avail;
    T*  limit;
};

} // namespace chapter11




#endif //__CHAPTER11_VEC_H__