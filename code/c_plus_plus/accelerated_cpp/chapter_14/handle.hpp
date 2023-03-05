
#ifndef __ACCELERATED_CPp_HANDLE_H__
#define __ACCELERATED_CPp_HANDLE_H__

#include <iostream>
#include <exception>

namespace chapter_14 {

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

}

#endif //