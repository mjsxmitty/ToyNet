
#include "chapter_15.h"
#include "quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"

#include <iostream>

using namespace std;

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
