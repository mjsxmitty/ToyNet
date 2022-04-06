
#include "str_blob.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

StrBlob::StrBlob() : data_(make_shared<vector<string>>()){}
StrBlob::StrBlob(const initializer_list<string> &il) : data_(make_shared<vector<string>>(il)){}
StrBlob::StrBlob(vector<string> *p) : data_(p){}
StrBlob::StrBlob(const StrBlob &rhs) : data_(rhs.data_){}
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data_ = rhs.data_;
    return *this;   
}

void StrBlob::CheckSize(size_type i, const string &msg) const
{
    if (i >= data_->size())
        throw out_of_range(msg);
}

string& StrBlob::Back()
{
    CheckSize(0, "back on empty StrBlob.");
    return data_->back();
}

const string& StrBlob::Back() const
{
    CheckSize(0, "back on empty StrBlob.");
    return data_->back();
}

string& StrBlob::Front()
{
    CheckSize(0, "front on empty StrBlob.");
    return data_->front();
}

const string& StrBlob::Front() const
{
    CheckSize(0, "front on empty StrBlob.");
    return data_->front();
}

void StrBlob::PopBack()
{
    CheckSize(0, "pop back on empty StrBlob.");
    return data_->pop_back();
}

StrBlobPtr StrBlob::Begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::End() { return StrBlobPtr(*this, data_->size()); }

StrBlobPtr StrBlob::Begin() const { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::End() const { return StrBlobPtr(*this, data_->size()); }

shared_ptr<vector<string>> StrBlobPtr::Check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");

    if (i >= ret->size())
        throw out_of_range(msg);

    return ret;
}

string& StrBlobPtr::Deref() const
{
    auto p = Check(curr_, "dereference past end.");
    return (*p)[curr_];
}

string& StrBlobPtr::Deref(int index) const
{
    auto p = Check(curr_ + index, "dereference past end.");
    return (*p)[curr_ + index];
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
    Check(curr_, "decrement past begin of StrBlobPtr.");
    return *this;
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