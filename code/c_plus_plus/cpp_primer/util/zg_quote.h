
#ifndef __CPP_PRIMER_ZGQUOTE_H__
#define __CPP_PRIMER_ZGQUOTE_H__

#include <string>


class ZGQuote
{
    /* 15.2.1 定义基类 */
public:
    ZGQuote() = default;
    ZGQuote(const std::string &book, double sales_price) :
        book_no_(book), price_(sales_price) {};

    std::string isbn() const { return book_no_; }
    virtual double NetPrice(std::size_t n) const
    { return n * price_; }

    virtual ~ZGQuote() = default;
private:
    std::string     book_no_;   //isbn
protected:
    double          price_ = 0.0;
};

#endif // ZGQUOTE_H
