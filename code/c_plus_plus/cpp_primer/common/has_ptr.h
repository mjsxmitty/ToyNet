

#ifndef __CPP_PRIMER_HASPTR_H__
#define __CPP_PRIMER_HASPTR_H__

#include <string>
#include <iostream>

class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    HasPtr(const std::string &s = std::string()) : 
            ps_(new std::string(s)), i_(0) {}       // 调用s的拷贝构造函数
    HasPtr(const HasPtr &p) : 
            ps_(new std::string(*p.ps_)), i_(p.i_) {}
    HasPtr(HasPtr &&p) noexcept : ps_(p.ps_), i_(p.i_) { p.ps_ = 0; }
    //HasPtr& operator=(const HasPtr &p);
    HasPtr& operator=(HasPtr p);
    HasPtr& operator=(const std::string &s);
    std::string& operator*();
    bool operator<(const HasPtr &) const;
    ~HasPtr();
private:
    std::string *ps_;
    int         i_;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    std::cout << "swap HasPtr: " << *lhs.ps_ 
              << ", " << *rhs.ps_ 
            << std::endl;

    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

class HasPtrRef
{
public:
    HasPtrRef(const std::string &s = std::string()) : 
            ps_(new std::string(s)), i_(0), use_(new size_t(1)){}
    HasPtrRef(const HasPtrRef &p) : 
            ps_(p.ps_), i_(p.i_), use_(p.use_) { ++*use_; }
    HasPtrRef& operator=(const HasPtrRef &p);
    HasPtrRef& operator=(const std::string &rhs);
    std::string& operator*();
    ~HasPtrRef();
private:
    std::string *ps_;
    int         i_;
    size_t      *use_;
public:
    HasPtrRef(HasPtrRef &&p) noexcept : 
                ps_(p.ps_), use_(p.use_),i_(p.i_) { p.ps_ = 0; p.use_ = 0;}
    HasPtrRef& operator=(HasPtrRef &&rhs);  //hp = std::move(hp1)
};

#endif // __CPP_PRIMER_HASPTR_H__
