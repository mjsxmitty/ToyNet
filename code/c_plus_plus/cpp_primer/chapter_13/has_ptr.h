

#ifndef __CPP_PRIMER_CHAPTER_13_HASPTR_H__
#define __CPP_PRIMER_CHAPTER_13_HASPTR_H__

#include <string>
#include <iostream>

/* 13.2.1 行为像值的类 */
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps_(new std::string(s)), i_(0) {}
    HasPtr(const HasPtr &h) : ps_(new std::string(*h.ps_)), i_(h.i_) {}
    //HasPtr& operator=(const HasPtr &h);
    ~HasPtr();

    // test
    std::string PrintVal() const { return *ps_; }
private:
    std::string *ps_;
    int         i_;
public:
    /* 13.3 */
    friend void swap(HasPtr &lhs, HasPtr &rhs);

    // 在赋值运算符中使用swap
    HasPtr& operator=(HasPtr h);


    HasPtr& operator=(const std::string &s);
    std::string& operator*();
    bool operator<(const HasPtr &rhs) const;

    HasPtr(HasPtr &&rhs) noexcept : ps_(rhs.ps_), i_(rhs.i_) {rhs.ps_ = 0;}
};

/* 13.3 交换操作 */
void swap(HasPtr &lhs, HasPtr &rhs);


/* 13.2.2 行为像指针的类 */
class HasPtrRef
{
public:
    HasPtrRef(const std::string &s = std::string()) : ps_(new std::string(s)), i_(0), use_(new size_t(1)){}
    HasPtrRef(const HasPtrRef &p) : ps_(p.ps_), i_(p.i_),use_(p.use_){ ++*use_; }
    HasPtrRef& operator=(const HasPtrRef &p);
    ~HasPtrRef();
private:
    std::string *ps_;
    int         i_;
    size_t      *use_;
public:
    HasPtrRef(HasPtrRef &&p) noexcept : ps_(p.ps_), use_(p.use_),i_(p.i_) {p.ps_ = 0; p.use_ = 0;}
    HasPtrRef& operator=(HasPtrRef &&rhs);  //hp = std::move(hp1)
};

#endif // __CPP_PRIMER_CHAPTER_13_HASPTR_H__
