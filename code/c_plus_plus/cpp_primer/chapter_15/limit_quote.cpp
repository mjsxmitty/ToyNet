
#include "limit_quote.h"
//#include "quote.h"
#include "disc_quote.h"

#include <iostream>

using namespace std;

void LimitQuote::Debug() const
{
    Quote::Debug();
    cout << endl;
    cout << "min qty: " << quantity_
         << ", discount: " << discount_;
}

double LimitQuote::NetPrice(std::size_t n) const
{
    if (n < quantity_)
        return n * (1 - discount_) * price_;
    else
        return quantity_ * (1 - discount_) * price_ + (n - quantity_) * price_;
}


