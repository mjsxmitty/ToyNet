
#ifndef __CPP_PRIMER_CH_15_HPP__
#define __CPP_PRIMER_CH_15_HPP__

#include <iostream>

namespace chapter_15 {

class Base
{
public:
    static void statmem();
};

void Base::statmem()
{
    std::cout << "base static func ..." << std::endl;
}

class Derived : public Base
{
public:
    void f(const Derived &driver);
};

void Derived::f(const Derived &driver)
{
    Base::statmem();
    Derived::statmem();
    driver.statmem();
    statmem();
}

/**/
struct B1
{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
    virtual void f();
};

struct D1 : public B1
{
    void f1(int) const override;
    void f2() override;     //new func
    //void f3() override;
    //void f4() override;
    void f(int);        //new
};

struct D2 : public B1
{
    void f1(int) const final;
};

struct D3 : public D2
{
    void f2();
    //void f1(int) const;
};

/*15.5 访问控制与继承*/
class Pal;
/*受保护成员*/
class Base1
{
    friend class Pal;
protected:
    int prot_mem;
};

class Sneaky : public Base1
{
    friend void clobber(Sneaky &) {}
    friend void clobber(Base1 &) {}
private:
    int     j;
};

/*公有、私有、受保护继承*/
class Base2
{
public:
    static void Statmem(){}
protected:
    int prot_mem_;
public:
    void pub_mem(){};
private:
    char priv_mem_;
};

struct PubDrev : public Base2
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct ProDrev : protected Base2
{
    int     f() { return prot_mem_; }
    //char    g() { return priv_mem_; }
};

struct PriDrev : private Base2
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

/*不能继承友元*/
class Pal
{
public:
    int f(Base1 &b) { return b.prot_mem; }
    // int f2(Sneaky &s) { return s.j; }
    int f3(Sneaky &s) { return s.prot_mem; }
};

class Pal2 : public Pal
{
public:
    // int mem(Base1 b) { return b.prot_mem; }
};


};

// https://blog.csdn.net/monster_acm/article/details/81200777
// https://www.cnblogs.com/FdWzy/p/12596238.html

//https://blog.csdn.net/norman_irsa/article/details/102873065
//https://blog.csdn.net/feng__shuai/article/details/120253401

#endif // __CPP_PRIMER_CH_15_HPP__
