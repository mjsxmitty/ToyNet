
#ifndef __CPP_PRIMER_LIMITEDQUOTE_H__
#define __CPP_PRIMER_LIMITEDQUOTE_H__

#include "disc_quote.h"

#include <string>

class limitedQuote : public DiscQuote
{
public:
    limitedQuote() = default;
    limitedQuote(const std::string &book, double price,
                   std::size_t qty, double disc) :
                   DiscQuote(book, price, qty, disc){}

    double NetPrice(std::size_t cnt) const override;

};

#endif // __CPP_PRIMER_LIMITEDQUOTE_H__
