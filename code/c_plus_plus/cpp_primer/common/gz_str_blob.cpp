
#include "gz_str_blob.h"

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

/*****************************************************************/
/***************************12.1********************************/

GZStrBlob::GZStrBlob() : data_(make_shared<vector<string>>()){}
GZStrBlob::GZStrBlob(const initializer_list<string> &il) : 
                    data_(make_shared<vector<string>>(il)) { }

GZStrBlob::GZStrBlob(vector<string> *p) : data_(p){}

// GZStrBlob::GZStrBlob(const GZStrBlob &rhs) : 
//                     data_(make_shared<vector<string>>(*rhs.data_)){ }

// GZStrBlob& GZStrBlob::operator=(const GZStrBlob &rhs)
// {
//    data_ = make_shared<vector<string>>(*rhs.data_);
//    return *this;
// }

GZStrBlob::GZStrBlob(const GZStrBlob &rhs) : data_(rhs.data_){}
GZStrBlob& GZStrBlob::operator=(const GZStrBlob &rhs)
{
    data_ = rhs.data_;
    return *this;
}

void GZStrBlob::CheckSize(size_type i, const string &msg) const
{
    if (i >= data_->size())
        throw out_of_range(msg);
}

string& GZStrBlob::Back()
{
    CheckSize(0, "back on empty GZStrBlob.");
    return data_->back();
}

string& GZStrBlob::Front()
{
    CheckSize(0, "front on empty GZStrBlob.");
    return data_->front();
}

void GZStrBlob::PopBack()
{
    CheckSize(0, "pop back on empty GZStrBlob.");
    return data_->pop_back();
}

const string& GZStrBlob::Front() const
{
    CheckSize(0, "front on empty GZStrBlob.");
    return data_->front();
}

const string& GZStrBlob::Back() const
{
    CheckSize(0, "back on empty GZStrBlob.");
    return data_->back();
}

bool operator<(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return *lhs.data_ < *rhs.data_;
}

bool operator<=(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return *lhs.data_ <= *rhs.data_;
}
bool operator>(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return *lhs.data_ > *rhs.data_;
}
bool operator>=(const GZStrBlob &lhs, const GZStrBlob &rhs)
{
    return *lhs.data_ >= *rhs.data_;
}
////////////////////////////////////////////////////////

