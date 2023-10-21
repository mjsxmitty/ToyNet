
#include "str_blob.h"
#include "str_blob_ptr.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

StrBlob::StrBlob() : data_(make_shared<vector<string>>()){}
StrBlob::StrBlob(const initializer_list<string> &il) :
                    data_(make_shared<vector<string>>(il)) { }

StrBlob::StrBlob(vector<string> *p) : data_(p){}

#if 0
StrBlob::StrBlob(const StrBlob &rhs) :
                 data_(make_shared<vector<string>>(*rhs.data_)){ }

StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data_ = make_shared<vector<string>>(*rhs.data_);
    return *this;
}
#endif

StrBlob::StrBlob(const StrBlob &rhs) : data_(rhs.data_){}
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data_ = rhs.data_;
    return *this;
}

void StrBlob::CheckSize(size_type i, const string &msg) const
{
    if (i >= data_->size())
    {
        throw out_of_range(msg);
    }
}

string& StrBlob::Back()
{
    CheckSize(0, "back on empty StrBlob.");
    return data_->back();
}

string& StrBlob::Front()
{
    CheckSize(0, "front on empty StrBlob.");
    return data_->front();
}

void StrBlob::PopBack()
{
    CheckSize(0, "pop back on empty StrBlob.");
    return data_->pop_back();
}

const string& StrBlob::Front() const
{
    CheckSize(0, "front on empty StrBlob.");
    return data_->front();
}

const string& StrBlob::Back() const
{
    CheckSize(0, "back on empty StrBlob.");
    return data_->back();
}

StrBlobPtr StrBlob::Begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::Begin() const { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::End() { return StrBlobPtr(*this, data_->size()); }
StrBlobPtr StrBlob::End() const { return StrBlobPtr(*this, data_->size()); }

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data_ < *rhs.data_;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data_ <= *rhs.data_;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data_ > *rhs.data_;
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data_ >= *rhs.data_;
}
