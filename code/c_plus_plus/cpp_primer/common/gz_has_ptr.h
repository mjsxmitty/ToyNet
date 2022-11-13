

#ifndef __CPP_PRIMER_CHAPTER_13_HASPTR_H__
#define __CPP_PRIMER_CHAPTER_13_HASPTR_H__

#include <string>
#include <iostream>

class GZHasPtr
{
    friend void swap(GZHasPtr &lhs, GZHasPtr &rhs);
public:
    GZHasPtr(const std::string &s = std::string()) : 
            ps_(new std::string(s)), i_(0) {}
    GZHasPtr(const GZHasPtr &p) : 
            ps_(new std::string(*p.ps_)), i_(p.i_) {}
    GZHasPtr(GZHasPtr &&p) noexcept : ps_(p.ps_), i_(p.i_) { p.ps_ = 0; }
    //GZHasPtr& operator=(const GZHasPtr &p);
    GZHasPtr& operator=(GZHasPtr p);
    GZHasPtr& operator=(const std::string &s);
    std::string& operator*();
    bool operator<(const GZHasPtr &) const;
    ~GZHasPtr();
private:
    std::string *ps_;
    int         i_;
};

inline void swap(GZHasPtr &lhs, GZHasPtr &rhs)
{
    using std::swap;
    std::cout << "swap GZHasPtr: " << *lhs.ps_ 
              << ", " << *rhs.ps_ 
              << std::endl;

    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
}

class GZHasPtrRef
{
public:
    GZHasPtrRef(const std::string &s = std::string()) : 
            ps_(new std::string(s)), i_(0), use_(new size_t(1)){}
    GZHasPtrRef(const GZHasPtrRef &p) : 
            ps_(p.ps_), i_(p.i_), use_(p.use_) { ++*use_; }
    GZHasPtrRef& operator=(const GZHasPtrRef &p);
    GZHasPtrRef& operator=(const std::string &rhs);
    std::string& operator*();
    ~GZHasPtrRef();
private:
    std::string *ps_;
    int         i_;
    size_t      *use_;
public:
    GZHasPtrRef(GZHasPtrRef &&p) noexcept : 
                ps_(p.ps_), use_(p.use_),i_(p.i_) { p.ps_ = 0; p.use_ = 0;}
    GZHasPtrRef& operator=(GZHasPtrRef &&rhs);  //hp = std::move(hp1)
};

#endif // __CPP_PRIMER_CHAPTER_13_HASPTR_H__
