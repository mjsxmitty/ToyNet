

#ifndef __ACCELERATED_CPP_REF_REF_Handle_H__
#define __ACCELERATED_CPP_REF_REF_Handle_H__

#include <iostream>
#include <exception>

namespace chapter_14 {

template <typename T>
class RefHandle
{
public:
    RefHandle() : ref_ptr_(new size_t(1)), p_(0) {}
    RefHandle(const RefHandle &rhs) : ref_ptr_(rhs.ref_ptr_), p_(rhs.p_)
    {
        ++*ref_ptr_;
    }
    RefHandle& operator=(const RefHandle &rhs);
    RefHandle(T *p) : ref_ptr_(new size_t(1)), p_(p) {}
    ~RefHandle();
public:
    operator bool() const { return p_; }
    T& operator*() const;
    T* operator->() const;
private:
    size_t      *ref_ptr_;
    T           *p_;
};

template<typename T>
RefHandle<T>& RefHandle<T>::operator=(const RefHandle &rhs)
{
    ++*ref_ptr_;
    if (--*ref_ptr_ == 0 )
    {
        delete p_;
        delete ref_ptr_;
    }

    ref_ptr_ = rhs.ref_ptr_;
    p_ = rhs.p_;
    return *this;
}

template<typename T>
T& RefHandle<T>::operator*() const
{
    if (p_)
        return *p_;
    
    throw std::runtime_error("unbound RefHandle.");
}

template<typename T>
T* RefHandle<T>::operator->() const
{
    if (p_)
        return p_;
    
    throw std::runtime_error("unbound RefHandle.");

}

template<typename T>
RefHandle<T>::~RefHandle()
{
    if (--*ref_ptr_ == 0)
    {
        delete ref_ptr_;
        delete p_;
    }
}

}

#endif //
