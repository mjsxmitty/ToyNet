

#ifndef __CPP_PRIMER_CHAPTER_15_QUOTE_H__
#define __CPP_PRIMER_CHAPTER_15_QUOTE_H__

#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
            book_no_(book), price_(sales_price) {}
    virtual ~Quote() = default;
public:
    std::string     isbn() const ;
    virtual double  NetPrice(std::size_t n) const;
    virtual void    Debug() const;
private:
    std::string     book_no_;
protected:
    double          price_;
};

#endif // __CPP_PRIMER_CHAPTER_15_QUOTE_H__
