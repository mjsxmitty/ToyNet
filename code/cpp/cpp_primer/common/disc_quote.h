
#ifndef __CPP_PRIMER_DISCQUOTE_H__
#define __CPP_PRIMER_DISCQUOTE_H__

#include "quote.h"

#include <string>

class DiscQuote : public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string &book, double price,
                std::size_t qty, double disc) :
                Quote(book, price),
                quantity(qty), discount(disc){}

    double NetPrice(std::size_t cnt) const = 0;
protected:
    std::size_t     quantity = 0;
    double          discount = 0.0;
};

#endif // __CPP_PRIMER_DISCQUOTE_H__
