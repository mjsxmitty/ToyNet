

#ifndef __ACCELERATED_CPP_REF_PTR_H__
#define __ACCELERATED_CPP_REF_PTR_H__

#include <iostream>
#include <exception>

#include "../chapter_11/vec.hpp"

namespace chapter_14 {

template <typename T>
T* clone(T* tp)
{
    return tp->clone();
}

template <typename T>
class Ptr
{
public:
    Ptr() : ref_ptr_(new size_t(1)), p_(0) {}
    Ptr(const Ptr &rhs) : ref_ptr_(rhs.ref_ptr_), p_(rhs.p_)
    {
        ++*ref_ptr_;
    }
    Ptr& operator=(const Ptr &rhs);
    Ptr(T *p) : ref_ptr_(new size_t(1)), p_(p) {}
    ~Ptr();
public:
    operator bool() const { return p_; }
    T& operator*() const;
    T* operator->() const;
public:
    void make_unique() 
    {
        if (*ref_ptr_ != 1)
        {
            --*ref_ptr_;
            ref_ptr_ = new size_t(1);
            //p_ = p_ ? p_->clone() : 0;
            //p_ = p_ ? clone(p_) : 0;
        }
    }
private:
    size_t      *ref_ptr_;
    T           *p_;
};

template<typename T>
Ptr<T>& Ptr<T>::operator=(const Ptr &rhs)
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
T& Ptr<T>::operator*() const
{
    if (p_)
        return *p_;
    
    throw std::runtime_error("unbound Ptr.");
}

template<typename T>
T* Ptr<T>::operator->() const
{
    if (p_)
        return p_;
    
    throw std::runtime_error("unbound Ptr.");

}

template<typename T>
Ptr<T>::~Ptr()
{
    if (--*ref_ptr_ == 0)
    {
        delete ref_ptr_;
        delete p_;
    }
}

}

#endif //
