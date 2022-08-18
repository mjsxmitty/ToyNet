
#ifndef __CPP_PRIMER_ZGLIMITEDQUOTE_H__
#define __CPP_PRIMER_ZGLIMITEDQUOTE_H__

#include "zg_disc_quote.h"

#include <string>

class ZGlimitedQuote : public ZGDiscQuote
{
public:
    ZGlimitedQuote() = default;
    ZGlimitedQuote(const std::string &book, double price,
                   std::size_t qty, double disc) :
                   ZGDiscQuote(book, price, qty, disc){}

    double NetPrice(std::size_t cnt) const override;

};

#endif // __CPP_PRIMER_ZGLIMITEDQUOTE_H__
