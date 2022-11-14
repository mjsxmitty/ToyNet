

#ifndef __CPP_PRIMER_OBJECT_BLOB_H__
#define __CPP_PRIMER_OBJECT_BLOB_H__

#include <vector>
#include <memory>
#include <vector>
#include <stdexcept>


template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T> class BlobPtr;
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
    template<typename It>
    Blob(It b, It e) : data_(std::make_shared<std::vector<T>>(b, e)) {}
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

template <typename T>
using BLOB = Blob<T>;

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


#endif //
