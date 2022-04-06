

#ifndef __CPP_PRIMER_CHAPTER_15_LIMIT_QUOTE_H__
#define __CPP_PRIMER_CHAPTER_15_LIMIT_QUOTE_H__

//#include "quote.h"
#include "disc_quote.h"

class LimitQuote : public DiscQuote
{
public:
    //LimitQuote() = default;
    LimitQuote(const std::string &book = "",
                double p = 0, std::size_t n = 0, double disc = 0) :
                // Quote(book, p), min_qty_(n), discount_(disc) {}
                DiscQuote(book, p, n, disc) {}
public:
    double NetPrice(std::size_t n) const override;
    void Debug() const;
// private:
//     std::size_t     min_qty_ = 0;
//     double          discount_ = 0.0;
};

#endif // __CPP_PRIMER_CHAPTER_15_LIMIT_QUOTE_H__
