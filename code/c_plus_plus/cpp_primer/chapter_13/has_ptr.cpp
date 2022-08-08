

#include "has_ptr.h"

using namespace std;

HasPtr &HasPtr::operator=(const HasPtr &h)
{
    auto p = new string(*h.ps_);
    delete ps_;

    ps_ = p;
    i_ = h.i_;
    return *this;
}

HasPtr::~HasPtr()
{
    delete ps_;
}

//HasPtr &HasPtr::operator=(HasPtr h)
//{
//    Swap(*this, h);
//    return *this;
//}

HasPtr &HasPtr::operator=(const string &s)
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


void Swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}


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


HasPtrRef::~HasPtrRef()
{
    if (--*use_ == 0)
    {
        delete use_;
        delete ps_;
    }
}
