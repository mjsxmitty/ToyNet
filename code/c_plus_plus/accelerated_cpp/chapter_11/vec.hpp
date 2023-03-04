

#ifndef __CHAPTER11_VEC_H__
#define __CHAPTER11_VEC_H__

#include <cstddef>
#include <memory>

namespace chapter_11
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

    Vec(const Vec &v) { Create(v.Begin(), v.End()); }
    Vec& operator=(const Vec &v);
    ~Vec() { UnCreate(); }
public:
    size_type   Size() const { return limit - data;}
    T&          operator[](size_type i) { return data[i]; }
    const T&    operator[](size_type i) const { return data[i]; }

    iterator        Begin() { return data; }
    const_iterator  Begin() const { return data; }
    iterator        End() { return limit; }
    const_iterator  End() const { return limit; }

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

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
    if (&rhs != this) {
        UnCreate();
        Create(rhs.Begin(), rhs.End());
    }
    return *this;
}

template<typename T>
void Vec<T>::PushBack(const T &val)
{
    if (avail == limit)
        Grow();

    UncheckedAppend();
}

template<typename T>
void Vec<T>::Create()
{
    data = avail = limit = 0;
}

template<typename T>
void Vec<T>::Create(size_type n, const T &val)
{
    data = Alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template<typename T>
void Vec<T>::Create(const_iterator i, const_iterator j)
{
    data = Alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template<typename T>
void Vec<T>::UnCreate()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
        {
            Alloc.destroy(--it);
        }
        Alloc.destroy(data, limit - data);
    }
    data = avail = limit = 0;
}

template<typename T>
void Vec<T>::Grow()
{
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = Alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    UnCreate();

    data = new_data;
    avail = new_avail;
    limit = new_data + new_size;
}

template<typename T>
void Vec<T>::UncheckedAppend(const T &val)
{
    Alloc.construct(avail++, val);
}

} // namespace chapter_11


#endif //__CHAPTER11_VEC_H__
