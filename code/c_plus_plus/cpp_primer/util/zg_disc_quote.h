
#ifndef __CPP_PRIMER_ZGDISCQUOTE_H__
#define __CPP_PRIMER_ZGDISCQUOTE_H__

#include "zg_quote.h"

#include <string>

/* 15.4 抽象基类 */
class ZGDiscQuote : public ZGQuote
{
public:
    ZGDiscQuote() = default;
    ZGDiscQuote(const std::string &book, double price,
                std::size_t qty, double disc) :
                ZGQuote(book, price),
                quantity(qty), discount(disc){}

    double NetPrice(std::size_t cnt) const = 0;
protected:
    std::size_t     quantity = 0;
    double          discount = 0.0;
};

#endif // __CPP_PRIMER_ZGDISCQUOTE_H__
