
#ifndef __CPP_PRIMER_CHAPTER_07_SALESDATE_H__
#define __CPP_PRIMER_CHAPTER_07_SALESDATE_H__

#include <string>
#include <iostream>

class SalesData
{
public:
    /* chapter 07 */
    //ÒýÈëthis/const
    //³ÉÔ±º¯ÊýÓÉ¶ÔÏóµ÷ÓÃµÃÒÔÊ¹ÓÃ: total.Isbn() --> SalesData::Isbn(&total)
    std::string Isdn() const //thisµÄÀàÐÍ SalesData *const(ÆÕÍ¨º¯Êý) --> const SalesData *const
    {
        return book_no_;
        // ¿ÉÒÔÖ±½ÓÊ¹ÓÃ³ÉÔ±: ÏÈ±àÒëÉùÃ÷ÔÙ±àÒëº¯ÊýÌå
        //return this->book_no_;
    }

    /* ·µ»Øthis¶ÔÏóµÄº¯Êý */
    SalesData& Combine(const SalesData &item);
private:
    double AvgPrice() const ;

public:
    //ï¿½ï¿½Ôªï¿½ï¿½ï¿½ï¿½Î»ï¿½Ã²ï¿½ï¿½ï¿½,ï¿½ï¿½ï¿½ï¿½ï¿½Ú½ï¿½ï¿½ï¿½ï¿½ï¿½Ö¸ï¿½ï¿½ï¿½Ë·ï¿½ï¿½ï¿½È¨ï¿½ï¿½
    friend std::istream& Read(std::istream &in, SalesData &item);
    friend std::ostream& Print(std::ostream &out, const SalesData &item);
    friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
    friend std::ostream& operator<<(std::ostream &os, const SalesData &item);
    friend std::istream& operator>>(std::istream &in, SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
public:
    //ï¿½á¹©ï¿½ï¿½ï¿½ìº¯ï¿½ï¿½,ï¿½ï¿½Ã»ï¿½ï¿½Ä¬ï¿½Ï¹ï¿½ï¿½ìº¯ï¿½ï¿½
    SalesData() = default;
    //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê½×ªï¿½ï¿½
    explicit SalesData(std::istream &in);
    explicit SalesData(const std::string &s) : book_no_(s){}
    SalesData(const std::string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p * n){std::cout << "func a" << std::endl;}

    /*Î¯ï¿½Ð¹ï¿½ï¿½ìº¯ï¿½ï¿½*/
    // SalesData() : SalesData("", 0, 0) {std::cout << "func b" << std::endl;}
    // SalesData(const std::string &s) : SalesData(s, 0, 0) {std::cout << "func c" << std::endl;}
    
    //Î¯ï¿½ï¿½Ð´ï¿½Ú¶ï¿½ï¿½å´¦
    //SalesData(std::istream &in);
    //Î¯ï¿½ï¿½Ð´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    // SalesData(std::istream &in) : SalesData() { Read(in, *this);}
    // -->SalesData()-->SalesData(const std::string &s, unsigned n, double p) -->Read
    SalesData(const SalesData &rhs) : book_no_(rhs.book_no_), units_sold_(rhs.units_sold_), revenue_(rhs.revenue_) {}
    SalesData& operator=(const SalesData &rhs);
    SalesData& operator=(const std::string &isbn);
    SalesData& operator+=(const SalesData &rhs);

    //std::string operator std::string() const { return book_no_; }
    // double operator double() const { return revenue_; }

private:
    std::string     book_no_;       //isbn
    unsigned        units_sold_;    //ÏúÁ¿
    double          revenue_;       //×ÜÊÕÈë
};

//ï¿½ï¿½Ôªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½ï¿½Ù´ï¿½ï¿½ï¿½ï¿½ï¿½
std::istream& Read(std::istream &in, SalesData &item);
std::ostream& Print(std::ostream &out, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);

std::ostream& operator<<(std::ostream &os, const SalesData &item);
std::istream& operator>>(std::istream &in, SalesData &item);
#endif // __CPP_PRIMER_CHAPTER_07_SALESDATE_H__
