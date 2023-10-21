
#include "str_blob_ptr.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

shared_ptr<vector<string>> StrBlobPtr::Check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if (!ret)
        throw runtime_error("unbound StrBlob.");

    if (i >= ret->size())
        throw out_of_range(msg);

    return ret;
}

string& StrBlobPtr::Deref() const
{
    auto p = Check(curr_, "dereference past end.");
    return (*p)[curr_];
}

StrBlobPtr& StrBlobPtr::Incr()
{
    Check(curr_, "increment past end StrBlobPtr");
    ++curr_;
    return *this;
}

StrBlobPtr& StrBlobPtr::Decr()
{
    --curr_;
    Check(curr_, "decrement past end StrBlobPtr");
    return *this;
}

string& StrBlobPtr::Deref(int index) const
{
    auto p = Check(curr_ + index, "dereference past end.");
    return (*p)[curr_ + index];
}

bool Equal(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);
    else
        return false;
}

bool NotEqual(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !Equal(lhs, rhs);
}

/****************************************************************/
/***************************14.3*********************************/

StrBlobPtr operator+(const StrBlobPtr &lhs, int n)
{
    StrBlobPtr ret(lhs);
    ret.curr_ += n;
    return ret;
}


StrBlobPtr operator-(const StrBlobPtr &lhs, int n)
{
    StrBlobPtr ret = lhs;
    ret.curr_ -= n;
    return ret;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data_ == rhs.data_;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);
    return false;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
    {
        if (!r)
            return false;   // 指向空
        return (lhs.curr_ < rhs.curr_);
    }
    else
        return false;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ <= rhs.curr_);
    else
        return false;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
    {
        if (!r)
            return false;   // 指向空
        return (lhs.curr_ > rhs.curr_);
    }
    else
        return false;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ <= rhs.curr_);
    else
        return false;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    Check(curr_, "increment past end StrBlobPtr");
    ++curr_;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr_;
    Check(curr_, "decrement past begin of StrBlobPtr.");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --(*this);
    return ret;
}

string& StrBlobPtr::operator*() const
{
    auto ret = Check(curr_, "xxxxx");
    return (*ret)[curr_];
}

string* StrBlobPtr::operator->() const
{
    return &(this->operator*());
}


