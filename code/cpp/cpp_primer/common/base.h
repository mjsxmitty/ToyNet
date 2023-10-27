
#ifndef __CPP_PRIMER_BASE_H__
#define __CPP_PRIMER_BASE_H__

#include <string>
#include <iostream>

namespace chapter_15 {

class Base
{
public:
    static void Statmem();
protected:
    int prot_mem_;
public:
    void pub_mem(){};
private:
    char priv_mem_;

public:
    friend class Paul;
public:
    std::size_t Size() { return n_; }
protected:
    std::size_t n_;

public:
    //Base() : mem_(0){}
    int mem_;
public:
    void MemFcn() {}
public:
    virtual int fcn() { std::cout << "Base::fcn()" << std::endl; }
};

struct PubDrev : public Base
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct ProDrev : protected Base
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct PriDrev : private Base
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct DrivedFromPublic : public PubDrev
{
    int UseBase() { return prot_mem_; }
};

struct DrivedFromProtected : public ProDrev
{
    int UseBase() { return prot_mem_; }
};

struct DrivedFromPrivate : public PriDrev
{
    //int UseBase() { return prot_mem_; }
};

// 派生类向基类转换的可访问性
// https://blog.csdn.net/monster_acm/article/details/81200777
// https://www.cnblogs.com/FdWzy/p/12596238.html
// homework18~20


// 改变个别成员的可访问性
class Derived1 : private Base
{
public:
    using Base::Size;
    int f() { return  Size(); }
protected:
    using Base::n_;
};

struct Derived2 : Base
{
public:
    Derived2(int i) : mem_(i) {}
    int GetMem(){ return mem_;}
    int GetMem2() { return Base::mem_; }
protected:
    int mem_;   //
public:
    void MemFcn(int i) {}
};

class D1 : public Base
{
public:
    // 隐藏了Base::fcn()
    int fcn(int i) {std::cout << "D1::fcn(int)" << std::endl;};
    virtual void fcn2() {std::cout << "D1::fcn2()" << std::endl;}
};

class D2 : public D1
{
public:
    int fcn(int i) {std::cout << "D2::fcn(int)" << std::endl;} //隐藏了D1::fcn(int i)
    int fcn(){std::cout << "D2::fcn()" << std::endl;}       //覆盖了Base::fcn()
    void fcn2() {std::cout << "D2::fcn2()" << std::endl;}    //覆盖了D1::fcn()
};


};
//https://blog.csdn.net/norman_irsa/article/details/102873065
//https://blog.csdn.net/feng__shuai/article/details/120253401

#endif // __CPP_PRIMER_BASE_H__
