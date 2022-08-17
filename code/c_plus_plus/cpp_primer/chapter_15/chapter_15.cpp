
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
    ch_15_2();
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

void ch_15_4()
{

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
