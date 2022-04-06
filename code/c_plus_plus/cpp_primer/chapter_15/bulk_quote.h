

#ifndef __CPP_PRIMER_CHAPTER_15_BULK_QUOTE_H__
#define __CPP_PRIMER_CHAPTER_15_BULK_QUOTE_H__

//#include "quote.h"
#include "disc_quote.h"
class BulkQuote : public DiscQuote
{
public:
    //BulkQuote() = default;
    BulkQuote(const std::string &book = "", double p = 0, std::size_t n = 0, double disc = 0) :
        DiscQuote(book, p, n, disc) {}
public:
    double NetPrice(std::size_t n) const override;
private:
    void Debug() const override;
// private:
//     std::size_t     min_qty_ = 0;       //折扣数量
//     double          discount_ = 0.0;     //折扣
};

#endif // __CPP_PRIMER_CHAPTER_15_BULK_QUOTE_H__
