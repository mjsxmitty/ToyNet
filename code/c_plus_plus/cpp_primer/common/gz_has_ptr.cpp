
#include <iostream>
#include "gz_has_ptr.h"

using namespace std;

// GZHasPtr& GZHasPtr::operator=(const GZHasPtr &rhs)
// {
//     auto new_ptr = new string(*rhs.ps_);
//     delete ps_;

//     ps_ = new_ptr;
//     i_ = rhs.i_;

//     return *this;
// }

GZHasPtr& GZHasPtr::operator=(GZHasPtr h)
{
    swap(*this, h);
    return *this;
}

GZHasPtr& GZHasPtr::operator=(const string &s)
{
    *ps_ = s;
    return *this;
}

string &GZHasPtr::operator*()
{
    return *ps_;
}

bool GZHasPtr::operator<(const GZHasPtr &rhs) const
{
    return *ps_ < *rhs.ps_;
}

GZHasPtr::~GZHasPtr()
{
    cout << *ps_ << " destruction func." << endl;
    delete ps_;
}

/************************************************************/

GZHasPtrRef &GZHasPtrRef::operator=(const GZHasPtrRef &p)
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

GZHasPtrRef& GZHasPtrRef::operator=(const string &rhs)
{
    *ps_ = rhs;
    return *this;
}

string& GZHasPtrRef::operator*()
{
    return *ps_;
}

GZHasPtrRef::~GZHasPtrRef()
{
    if (--*use_ == 0)
    {
        cout << *ps_ <<" destruction func." << endl;
        delete use_;
        delete ps_;
    }
}

GZHasPtrRef& GZHasPtrRef::operator=(GZHasPtrRef &&rhs)
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



