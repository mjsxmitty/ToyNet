
#include <iostream>
#include "has_ptr.h"

using namespace std;

/***************************************************************/
/***************************13.2********************************/

//HasPtr &HasPtr::operator=(const HasPtr &h)
//{
//    auto p = new string(*h.ps_);
//    delete ps_;

//    ps_ = p;
//    i_ = h.i_;
//    return *this;
//}

HasPtr::~HasPtr()
{
    cout << "HasPtr disfunc: " << PrintVal() << endl;
    delete ps_;
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

HasPtrRef::~HasPtrRef()
{
    if (--*use_ == 0)
    {
        cout << "HasPtrRef disfunc ..." << endl;
        delete use_;
        delete ps_;
    }
}

/***************************************************************/
/***************************13.3********************************/

void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap HasPtr object: " << lhs.PrintVal() <<
            " and "  << rhs.PrintVal() << endl;
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

// 在赋值运算符中是用swap
HasPtr &HasPtr::operator=(HasPtr h)
{
    cout << PrintVal() << endl;
    swap(*this, h);
    cout << PrintVal() << endl;
    return *this;
}

/***************************************************************/
/***************************13.6********************************/

//HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
//{
//    if (this != &rhs)
//    {
//        delete ps_;

//        ps_ = rhs.ps_;
//        i_ = rhs.i_;

//        rhs.ps_ = nullptr;
//        rhs.i_ = 0;
//    }
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



