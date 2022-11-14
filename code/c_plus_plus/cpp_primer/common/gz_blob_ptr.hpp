
#ifndef __CPP_PRIMER_COMMON_GZ_BLOB_PTR_H__
#define __CPP_PRIMER_COMMON_GZ_BLOB_PTR_H__

#include "gz_blob.hpp"

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr_(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) :
            wptr_(a.data_), curr_(sz) {}
public:
    T& operator*() const;
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
private:
    std::shared_ptr<std::vector<T>>
    Check(std::size_t i, const std::string &msg) const;
private:
    std::weak_ptr<std::vector<T>>   wptr_;
    std::size_t                     curr_;
};

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::Check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr_.lock();
    if (!ret)
        throw std::out_of_range("unbound Blob.");

    if (i >= ret->size())
        throw std::out_of_range(msg);

    return ret;
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
    auto p = Check(curr_, "dereference past end.");
    return (*p)[curr_];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    Check(curr_, "increment past end BlobPtr");
    curr_++;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    curr_--;
    Check(curr_, "decrement past end BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;    // 调用前置运算符
    return ret;
}


#endif //
