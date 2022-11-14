
#ifndef __CPP_PRIMER_ZGBASE_H__
#define __CPP_PRIMER_ZGBASE_H__

#include <string>
#include <iostream>

class ZGBase
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
    friend class ZGPaul;
public:
    std::size_t Size() { return n_; }
protected:
    std::size_t n_;

public:
    //ZGBase() : mem_(0){}
    int mem_;
public:
    void MemFcn() {}
public:
    virtual int fcn() { std::cout << "Base::fcn()" << std::endl; }
};

class ZGDerived : public ZGBase
{
public:
    void f(const ZGDerived &);
};

class ZGSneaky : public ZGBase
{
    friend void Clobber(ZGSneaky &);
    friend void Clobber(ZGBase &);
    int j;
};

//void Clobber(ZGSneaky &s)
//{
//    s.j = s.prot_mem_ = 0;
//}

////// 受保护的成员
//void Clobber(ZGBase &b)
//{
//    //b.prot_mem_ = 0;
//}

struct ZGPubDrev : public ZGBase
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct ZGProDrev : protected ZGBase
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct ZGPriDrev : private ZGBase
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct DrivedFromPublic : public ZGPubDrev
{
    int UseBase() { return prot_mem_; }
};

struct DrivedFromProtected : public ZGProDrev
{
    int UseBase() { return prot_mem_; }
};

struct DrivedFromPrivate : public ZGPriDrev
{
    //int UseBase() { return prot_mem_; }
};

// 派生类向基类转换的可访问性
// https://blog.csdn.net/monster_acm/article/details/81200777
// https://www.cnblogs.com/FdWzy/p/12596238.html
// homework18~20

// 友元与继承
class ZGPaul
{
public:
    int f(ZGBase b){ return b.prot_mem_; }
    //int f2(ZGSneaky s) { return s.j; }
    int f3(ZGSneaky s) { return s.prot_mem_; }
};

class ZGDerivedFromPaul : public ZGPaul
{
public:
    //int mem(ZGBase b) { return b.prot_mem_; }
};

// 改变个别成员的可访问性
class ZGDerived1 : private ZGBase
{
public:
    using ZGBase::Size;
    int f() { return  Size(); }
protected:
    using ZGBase::n_;
};

struct ZGDerived2 : ZGBase
{
public:
    ZGDerived2(int i) : mem_(i) {}
    int GetMem(){ return mem_;}
    int GetMem2() { return ZGBase::mem_; }
protected:
    int mem_;   //
public:
    void MemFcn(int i) {}
};

class ZGD1 : public ZGBase
{
public:
    // 隐藏了ZGBase::fcn()
    int fcn(int i) {std::cout << "ZGD1::fcn(int)" << std::endl;};
    virtual void fcn2() {std::cout << "ZGD1::fcn2()" << std::endl;}
};

class ZGD2 : public ZGD1
{
public:
    int fcn(int i) {std::cout << "ZGD2::fcn(int)" << std::endl;} //隐藏了ZGD1::fcn(int i)
    int fcn(){std::cout << "ZGD2::fcn()" << std::endl;}       //覆盖了ZGBase::fcn()
    void fcn2() {std::cout << "ZGD2::fcn2()" << std::endl;}    //覆盖了ZGD1::fcn()
};

//https://blog.csdn.net/norman_irsa/article/details/102873065
//https://blog.csdn.net/feng__shuai/article/details/120253401
#endif // __CPP_PRIMER_ZGBASE_H__
