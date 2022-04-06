

#ifndef __CPP_PRIMER_CHAPTER_15_DISC_QUOTE_H__
#define __CPP_PRIMER_CHAPTER_15_DISC_QUOTE_H__

#include "quote.h"

#include <string>
#include <utility>

class DiscQuote : public Quote
{
public:
    //DiscQuote(/* args */) = default;
    DiscQuote(const std::string &book = "", double price = 0.0,
                std::size_t qty = 0, double disc = 0.0) : 
                Quote(book, price), 
                quantity_(qty), discount_(disc) {}
public:
    double NetPrice(std::size_t n) const = 0;
    std::pair<std::size_t, double>  DiscountPolicy() const
    {
        return {quantity_, discount_};
    }
protected:
    std::size_t     quantity_ = 0;
    double          discount_ = 0.0;
};

#endif //