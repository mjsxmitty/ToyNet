
#ifndef __CPP_PRIMER_ZGBULKQUOTE_H__
#define __CPP_PRIMER_ZGBULKQUOTE_H__

#include "zg_quote.h"

class ZGBulkQuote : public ZGQuote
{
    /* 15.2.2 定义派生类 */
public:
    ZGBulkQuote() = default;
    ZGBulkQuote(const std::string &, double, std::size_t, double);

    double NetPrice(std::size_t n) const override;
private:
    std::size_t     min_qty_ = 0;
    double          discount_ = 0.0;
};

#include "zg_disc_quote.h"

class ZGBulkQuote1 : public ZGDiscQuote
{
    /* 15.4 抽象基类 */
public:
    ZGBulkQuote1() = default;
    ZGBulkQuote1(const std::string &book, double price,
                 std::size_t qty, double disc) :
                ZGDiscQuote(book, price, qty, disc){};

    double NetPrice(std::size_t n) const override;
};

#endif // __CPP_PRIMER_ZGBULKQUOTE_H__
