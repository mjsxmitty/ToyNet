
#ifndef __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__
#define __CPP_PRIMER_COMMON__STR_BLOB_PTR_H__

#include <string>
#include <memory>
#include <vector>
#include <utility>

#include "str_blob.h"

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend StrBlobPtr operator+(const StrBlobPtr&, int);
    friend StrBlobPtr operator-(const StrBlobPtr&, int);
public:
    StrBlobPtr(): curr_(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
                wptr_(a.data_), curr_(sz) { }
public:
    std::string& operator[](size_t n) { return (*wptr_.lock())[n]; }
    const std::string& operator[](size_t n) const { return  (*wptr_.lock())[n]; }

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr  operator++(int);
    StrBlobPtr  operator--(int);

    std::string& operator*() const;
    std::string* operator->() const;
private:
    std::shared_ptr<std::vector<std::string>>
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t                             curr_;
#if 0
    friend bool Equal(const StrBlobPtr&, const StrBlobPtr&);
    friend bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);
    StrBlobPtr&     Incr();
    StrBlobPtr&     Decr();
    std::string&    Deref() const;
    std::string&    Deref(int index) const;
#endif
};

#if 0
bool Equal(const StrBlobPtr&, const StrBlobPtr&);
bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);
#endif
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

StrBlobPtr operator+(const StrBlobPtr&, int);
StrBlobPtr operator-(const StrBlobPtr&, int);

#endif //
