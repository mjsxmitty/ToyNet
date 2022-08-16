
#include "zg_bulk_quote.h"

ZGBulkQuote::ZGBulkQuote(const std::string &book, double p,
                         std::size_t qty, double disc) :
                        ZGQuote(book, p), min_qty_(qty), discount_(disc)
{

}

// 派生类使用基类成员
double ZGBulkQuote::NetPrice(std::size_t n) const
{
    if (n > min_qty_)
        return n * (1 - discount_) * price_;
    else
        return n * price_;
}
