
#ifndef __CPP_PRIMER_QUOTE_H__
#define __CPP_PRIMER_QUOTE_H__

#include <string>


class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
            book_no_(book), price_(sales_price) {};

    std::string     isbn() const { return book_no_; }
    virtual double  NetPrice(std::size_t n) const
    { return n * price_; }

    virtual ~Quote() = default;
private:
    std::string     book_no_;   //isbn
protected:
    double          price_ = 0.0;
};

#endif // __CPP_PRIMER_QUOTE_H__
