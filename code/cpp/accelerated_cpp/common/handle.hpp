
#ifndef __ACCELERATED_CPP_HANDLE_H__
#define __ACCELERATED_CPP_HANDLE_H__

#include <iostream>
#include <exception>

/*值版本*/
template <typename T>
class Handle
{
public:
    Handle() : p_(0) {}
    Handle(const Handle &rhs) : p_(0)
    {
        if (rhs.p_)
            p_ = rhs.p_->clone();
    }
    Handle& operator=(const Handle &rhs);
    Handle(T *p) : p_(p) {}
    ~Handle() { delete p_; }
public:
    operator bool() const { return p_; }
    T& operator*() const;
    T* operator->() const;
private:
    T* p_;
};

template<typename T>
Handle<T>& Handle<T>::operator=(const Handle &rhs)
{
    if (&rhs != this)
    {
        delete p_;
        p_ = rhs.p_ ? rhs.p_->clone() : 0;
    }

    return *this;
}

template<typename T>
T& Handle<T>::operator*() const
{
    if (p_)
        return *p_;
    
    throw std::runtime_error("unbound Handle.");
}

template<typename T>
T* Handle<T>::operator->() const
{
    if (p_)
        return p_;
    
    throw std::runtime_error("unbound Handle.");

}

/*引用计数版*/
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

#include "vec.hpp"

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
            p_ = p_ ? clone(p_) : 0;
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

template <class T>
T* clone(T* tp)
{
    return new T(*tp);
    //return tp->clone();
}

//Vec<char>* clone(const Vec<char>* vp)
//{
//    return new Vec<char>(*vp);
//}

#endif // __ACCELERATED_CPP_HANDLE_H__
