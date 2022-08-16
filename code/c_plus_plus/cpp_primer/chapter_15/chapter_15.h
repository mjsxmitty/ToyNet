

#ifndef __CPP_PRIMER_CHAPTER_15_H__
#define __CPP_PRIMER_CHAPTER_15_H__

void ch_15();
void ch_15_2();
void ch_15_2_2();
void exer_15_4();


void Chapter_15();

void Practice_15_1();
void Practice_15_6();

class Base
{
public:
    //Base() {}
    static void statmem();
};

class Derived : public Base
{
public:
    //Derived() {}
    void f(const Derived &driver);
};

//15-3
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

class Pal;
class Base1
{
    friend class Pal;
protected:
    int prot_mem;
};

class Sneaky : public Base1
{
    friend void clobber(Sneaky &);
    friend void clobber(Base1 &);
private:
    int     j;
};

void clobber(Sneaky &s);
void clobber(Base1 &b);

class Pal
{
public:
    int f(Base1 &b) { return b.prot_mem; }
    // int f2(Sneaky &s) { return s.j; }
    int f3(Sneaky &s) { return s.prot_mem; }
};

class D21 : public Pal
{
public:
    // int mem(Base1 b) { return b.prot_mem; }
};

#endif // __CPP_PRIMER_CHAPTER_15_H__
