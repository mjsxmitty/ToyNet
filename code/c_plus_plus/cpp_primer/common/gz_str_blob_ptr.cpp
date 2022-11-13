
#include "gz_str_blob_ptr.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

GZStrBlobPtr GZStrBlob::Begin() { return GZStrBlobPtr(*this); }
GZStrBlobPtr GZStrBlob::End() { return GZStrBlobPtr(*this, data_->size()); }
GZStrBlobPtr GZStrBlob::Begin() const { return GZStrBlobPtr(*this); }
GZStrBlobPtr GZStrBlob::End() const { return GZStrBlobPtr(*this, data_->size()); }

shared_ptr<vector<string>> GZStrBlobPtr::Check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if (!ret)
        throw runtime_error("unbound GZStrBlobPtr");

    if (i >= ret->size())
        throw out_of_range(msg);

    return ret;
}

string& GZStrBlobPtr::Deref() const
{
    auto p = Check(curr_, "dereference past end.");
    return (*p)[curr_];
}

GZStrBlobPtr& GZStrBlobPtr::Incr()
{
    Check(curr_, "increment past end GZStrBlobPtr");
    ++curr_;    // �˴���������,�������������У��
    return *this;
}

string& GZStrBlobPtr::Deref(int index) const
{
    auto p = Check(curr_ + index, "dereference past end.");
    return (*p)[curr_ + index];
}

GZStrBlobPtr& GZStrBlobPtr::Decr()
{
    --curr_;
    Check(curr_, "decrement past begin of GZStrBlobPtr.");
    return *this;
}

bool Equal(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);  // ��ָ�����ָ����ͬ��vector
    else
        return false;
}

bool NotEqual(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    return !Equal(lhs, rhs);
}

/****************************************************************/
/***************************14.3*********************************/

GZStrBlobPtr operator+(const GZStrBlobPtr &lhs, int n)
{
    GZStrBlobPtr ret(lhs);
    ret.curr_ += n;
    return ret;
}


GZStrBlobPtr operator-(const GZStrBlobPtr &lhs, int n)
{
    GZStrBlobPtr ret = lhs;
    ret.curr_ -= n;
    return ret;
}

bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return lhs.data_ == rhs.data_;
}

bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ == rhs.curr_);
    return false;
}

bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
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
bool operator<=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ <= rhs.curr_);
    else
        return false;
}
bool operator>(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
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
bool operator>=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs)
{
    auto l = lhs.wptr_.lock(), r = rhs.wptr_.lock();
    if (l == r)
        return (!r || lhs.curr_ <= rhs.curr_);
    else
        return false;
}

GZStrBlobPtr& GZStrBlobPtr::operator++()
{
    Check(curr_, "increment past end GZStrBlobPtr");
    ++curr_;
    return *this;
}

GZStrBlobPtr& GZStrBlobPtr::operator--()
{
    --curr_;
    Check(curr_, "decrement past begin of GZStrBlobPtr.");
    return *this;
}

GZStrBlobPtr GZStrBlobPtr::operator++(int)
{
    GZStrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

GZStrBlobPtr GZStrBlobPtr::operator--(int)
{
    GZStrBlobPtr ret = *this;
    --(*this);
    return ret;
}

string& GZStrBlobPtr::operator*() const
{
    auto ret = Check(curr_, "xxxxx");
    return (*ret)[curr_];
}

string* GZStrBlobPtr::operator->() const
{
    return &(this->operator*());
}


