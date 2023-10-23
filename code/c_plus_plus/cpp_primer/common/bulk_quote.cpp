
#include "bulk_quote.h"
#include <string>

BulkQuote::BulkQuote(const std::string &book, double p,
                         std::size_t qty, double disc) :
                        Quote(book, p), min_qty_(qty), discount_(disc)
{

}

double BulkQuote::NetPrice(std::size_t n) const
{
    if (n > min_qty_)
        return n * (1 - discount_) * price_;
    else
        return n * price_;
}

double BulkQuote2::NetPrice(std::size_t n) const
{
    if (n > quantity)
        return n * (1 - discount) * price_;
    else
        return n * price_;
}
