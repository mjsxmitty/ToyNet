
#ifndef __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__
#define __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__

#include <string>
#include <memory>
#include <vector>
#include <utility>

#include "str_blob.h"

class StrBlobPtr
{
public:
    StrBlobPtr(): curr_(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
                wptr_(a.data_), curr_(sz) { }
public:
    StrBlobPtr&   Incr();
    std::string&    Deref() const;
private:
    std::shared_ptr<std::vector<std::string>>
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t                             curr_;

public:
    friend bool Equal(const StrBlobPtr&, const StrBlobPtr&);
    friend bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);

    std::string&    Deref(int index) const;
public:
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend StrBlobPtr operator+(const StrBlobPtr&, int);
    friend StrBlobPtr operator-(const StrBlobPtr&, int);
public:
    std::string& operator[](size_t n) { return (*wptr_.lock())[n]; }
    const std::string& operator[](size_t n) const { return  (*wptr_.lock())[n]; }
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr  operator++(int);
    StrBlobPtr  operator--(int);

    std::string& operator*() const;
    std::string* operator->() const;
public:
    StrBlobPtr&     Decr();
};

bool Equal(const StrBlobPtr&, const StrBlobPtr&);
bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

StrBlobPtr operator+(const StrBlobPtr&, int);
StrBlobPtr operator-(const StrBlobPtr&, int);

#endif //
