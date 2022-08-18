
#include "chapter_15.h"
#include "../util/zg_quote.h"
#include "../util/zg_bulk_quote.h"
#include "../util/zg_base.h"
//
#include "quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"
//

#include <iostream>

using namespace std;

void ch_15()
{
    //ch_15_2();
    //ch_15_5();
    ch_15_6();
}

/* 定义基类和派生类 */
void ch_15_2()
{
    ch_15_2_2();
}

/* 定义派生类 */
void ch_15_2_2()
{
    // 派生类中的虚函数
    // double NetPrice(std::size_t n) const override;

    // 派生类对象及派生类向基类的类型转换
    {
        ZGQuote     quote;
        ZGBulkQuote bulk;

        ZGQuote *p = &quote;
        p = &bulk;

        ZGQuote &r = bulk;
    }

    // 派生类构造函数
    // ZGBulkQuote(const std::string &, double, std::size_t, double);

    // 派生类使用基类成员
    // double ZGBulkQuote::NetPrice(std::size_t n) const

    // 继承与静态成员
    // void ZGDerived::f(const ZGDerived &derived_obj)

    // 派生类声明
    {
        //class ZGBulkQuote : public ZGQuote;
        class ZGBulkQuote;
    }

    // 被用作基类的类
    {
        class ZGD1 : public ZGBase {};
        class ZGD2 : public ZGD1 {};
    }

    // 防止继承的发生
    {
        class ZGNoDerived final {};
        //class ZGBad : public ZGNoDerived {};
        class ZGLast final : public ZGBase {};
        //class ZGBad2 : public ZGLast {};
    }
}

void exer_15_7()
{
    class ZGLimitedQuote : public ZGQuote
    {
    public:
        double NetPrice(size_t cnt) const override
        {
            if (cnt <= min_qty_)
                return cnt * (1 - discount_) * price_;
            else
                return min_qty_ * (1 - discount_) * price_ + (cnt - min_qty_) * price_;
        }
    private:
        size_t min_qty_ = 0;
        double discount_ = 0.0;
    };
}


void ch_15_5()
{
    ZGPubDrev d1;
    ZGProDrev d2;
    ZGPriDrev d3;
    d1.f();
    d1.pub_mem();
    d2.f();
    //d2.pub_mem();
    d3.f();
    //d3.pub_mem();

    ZGDerived1 d4;
    d4.Size();
}

void ch_15_6()
{
//    ZGDerived2 d1(100);
//    cout << d1.GetMem() << endl;
//    cout << d1.GetMem2() << endl;

//    ZGBase b1;
//    b1.MemFcn();
//    d1.MemFcn(10);
//    //d1.MemFcn();
//    d1.ZGBase::MemFcn();

    ZGBase bobj;
    ZGD1 d1obj;
    ZGD2 d2obj;

    ZGBase *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    ZGD1 *d1p = &d1obj;
    ZGD2 *d2p = &d2obj;
    //bp2->fcn2();
    d1p->fcn2();
    d2p->fcn2();

    ZGD1 *d3p = &d2obj;
    d3p->fcn2();

    ZGBase  *p1 = &d2obj;
    ZGD1    *p2 = &d2obj;
    ZGD2    *p3 = &d2obj;
    //p1->fcn(1);
    p2->fcn(2);
    p3->fcn(3);
}

void Chapter_15()
{
    Practice_15_1();
}

void PrintTotal(ostream &os, const Quote &q, size_t n)
{
    os << "ISBN:  " << q.isbn() << " # sold: "
       << n << ", total due: " << q.NetPrice(n) << endl;
}

void Practice_15_1()
{
    Quote       q("gao", 10);
    BulkQuote   bq("gao zhuo", 10, 10, 0.3);

    //DiscQuote disc;

    PrintTotal(cout, q, 20);
    PrintTotal(cout, bq, 20);
}

void Base::statmem()
{
    cout << "base static func ..." << endl;
}

void Derived::f(const Derived &driver)
{
    Base::statmem();
    Derived::statmem();
    driver.statmem();
    statmem();
}


void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0;
}

// void clobber(Base1 &b)
// {
//     b.prot_mem = 0;
// }

void Practice_15_6()
{
    BulkQuote   bulk;
    BulkQuote   *bulk_p = &bulk;
    Quote       *item_p = &bulk;

    bulk_p->DiscountPolicy();
    //item_p->DiscountPolicy();
}
