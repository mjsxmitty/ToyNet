
#include <iostream>
#include "has_ptr.h"

using namespace std;

// HasPtr& HasPtr::operator=(const HasPtr &rhs)
// {
//     auto new_ptr = new string(*rhs.ps_);
//     delete ps_;

//     ps_ = new_ptr;
//     i_ = rhs.i_;

//     return *this;
// }

HasPtr& HasPtr::operator=(HasPtr h)
{
    swap(*this, h);
    return *this;
}

HasPtr& HasPtr::operator=(const string &s)
{
    *ps_ = s;
    return *this;
}

string &HasPtr::operator*()
{
    return *ps_;
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps_ < *rhs.ps_;
}

HasPtr::~HasPtr()
{
    cout << *ps_ << " destruction func." << endl;
    delete ps_;
}

/************************************************************/

HasPtrRef &HasPtrRef::operator=(const HasPtrRef &p)
{
    ++*p.use_;
    if (--*use_ == 0)
    {
        delete ps_;
        delete use_;
    }

    ps_ = p.ps_;
    i_ = p.i_;
    use_ = p.use_;

    return *this;
}

HasPtrRef& HasPtrRef::operator=(const string &rhs)
{
    *ps_ = rhs;
    return *this;
}

string& HasPtrRef::operator*()
{
    return *ps_;
}

HasPtrRef::~HasPtrRef()
{
    if (--*use_ == 0)
    {
        cout << *ps_ <<" destruction func." << endl;
        delete use_;
        delete ps_;
    }
}

HasPtrRef& HasPtrRef::operator=(HasPtrRef &&rhs)
{
    if (this != &rhs)
    {
        if (--*use_ == 0)
        {
            delete ps_;
            delete use_;
        }
        
        ps_ = rhs.ps_;
        i_ = rhs.i_;
        use_ = rhs.use_;
        ps_ = 0;
        use_ = 0;
    }
    return *this;   
}



