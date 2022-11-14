

#ifndef __CPP_PRIMER_OBJECT_BLOB_H__
#define __CPP_PRIMER_OBJECT_BLOB_H__

#include <vector>
#include <memory>
#include <vector>
#include <stdexcept>

template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename> class BlobPtr;

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
public: 
    typedef T   ValueType;
    typedef typename std::vector<T>::size_type SizeType;
public:
    Blob();
    Blob(const std::initializer_list<T> &il);
public:
    SizeType    Size() const { return data_->size(); }
    bool        Empty() const { return data_->empty(); }
    void        PushBack(const T &val) { data_->push_back(val); }
    void        PushBack(T &&val) { data_->push_back(std::move(val)); }
    void        PopBack();

    T&  Back();
    T&  operator[](SizeType i); 
private:
    void Check(SizeType i, const std::string &msg) const ;
private:
    std::shared_ptr<std::vector<T>> data_;
};

//template <typename T>
//bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
//{
//    return lhs.data_ == rhs.data_;
//}

template <typename T>
Blob<T>::Blob() : data_(std::make_shared<std::vector<T>>()){}

template <typename T>
Blob<T>::Blob(const std::initializer_list<T> &il) : data_(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::Check(SizeType i, const std::string &msg) const
{
    if (i >= data_->size())
    throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::Back()
{
    Check(0, "back on empty Blob.");
    return data_->back();
}

template <typename T>
T& Blob<T>::operator[](SizeType i)
{
    Check(i, "out of range.");
    return (*data_)[i];
}

template <typename T>
void Blob<T>::PopBack()
{
    Check(0, "pop back on empty Blob.");
    data_->pop_back();
}

template <typename T>
using BLOB = Blob<T>;

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr_(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}
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
