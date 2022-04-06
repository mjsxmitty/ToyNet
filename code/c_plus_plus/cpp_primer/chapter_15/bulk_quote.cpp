

#include "bulk_quote.h"
#include "quote.h"

#include <iostream>

using namespace std;

void BulkQuote::Debug() const
{
    Quote::Debug();
    cout << endl;
    cout << "min qty: " << quantity_
         << ", discount: " << discount_;
}

double BulkQuote::NetPrice(std::size_t n) const
{
    if (n > quantity_)
        return n * (1 - discount_) * price_;
    else
        return n * price_;
}
