
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

#endif // __CPP_PRIMER_ZGBULKQUOTE_H__
