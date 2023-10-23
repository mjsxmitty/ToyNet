
#ifndef __CPP_PRIMER_BULKQUOTE_H__
#define __CPP_PRIMER_BULKQUOTE_H__

#include "quote.h"

class BulkQuote : public Quote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string &, double, std::size_t, double);

    double NetPrice(std::size_t n) const override;
private:
    std::size_t     min_qty_ = 0;
    double          discount_ = 0.0;
};

#include "disc_quote.h"

class BulkQuote2 : public DiscQuote
{
public:
    BulkQuote2() = default;
    BulkQuote2(const std::string &book, double price,
                 std::size_t qty, double disc) :
                DiscQuote(book, price, qty, disc){};

    double NetPrice(std::size_t n) const override;
};

#endif // __CPP_PRIMER_BULKQUOTE_H__
