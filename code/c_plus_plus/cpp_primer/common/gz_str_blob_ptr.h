
#ifndef __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__
#define __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__

#include <string>
#include <memory>
#include <vector>
#include <utility>

#include "gz_str_blob.h"

class GZStrBlobPtr
{
public:
    GZStrBlobPtr(): curr_(0) { }
    GZStrBlobPtr(const GZStrBlob &a, size_t sz = 0): 
                wptr_(a.data_), curr_(sz) { }
public:
    GZStrBlobPtr&   Incr();
    std::string&    Deref() const;
private:
    std::shared_ptr<std::vector<std::string>>
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t                             curr_;

public:
    friend bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
    friend bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);

    std::string&    Deref(int index) const;
public:
    friend bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator<(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator<=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator>(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator>=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
    friend GZStrBlobPtr operator-(const GZStrBlobPtr&, int);
public:
    std::string& operator[](size_t n) { return (*wptr_.lock())[n]; }
    const std::string& operator[](size_t n) const { return  (*wptr_.lock())[n]; }
    GZStrBlobPtr& operator++();
    GZStrBlobPtr& operator--();
    GZStrBlobPtr  operator++(int);
    GZStrBlobPtr  operator--(int);

    std::string& operator*() const;
    std::string* operator->() const;
public:
    GZStrBlobPtr&     Decr();
};

bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);

bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator<(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator<=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator>(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator>=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);

GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
GZStrBlobPtr operator-(const GZStrBlobPtr&, int);

#endif //