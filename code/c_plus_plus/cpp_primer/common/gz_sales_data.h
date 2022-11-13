

#ifndef __GZ_SALES_DATA_H__
#define __GZ_SALES_DATA_H__

#include <string>
#include <iostream>

class GZSalesData;
/* 7.1.3 定义类相关的非成员函数 */
std::istream&   Read(std::istream &is, GZSalesData &item);
std::ostream&   Print(std::ostream &os, GZSalesData &item);
GZSalesData     Add(const GZSalesData& lhs, const GZSalesData &rhs);

/* 7.1.2 定义类 */
class GZSalesData
//struct GZSalesData
{
public:
    /* 定义成员函数 */
    std::string Isbn() const { return book_no_; }
private:
    /* 类外部定义成员函数 */
    double AvgPrice() const ;
public:
    /* 定义一个返回this对象的函数 */
    GZSalesData& Combine(const GZSalesData &rhs);
private:
    std::string     book_no_;
    unsigned int    units_sold_ = 0;
    double          revenue_ = 0.0;
public:
    /* 7.1.4 构造函数 */
    //GZSalesData() = default;
    /* 构造函数初始值列表 */
    //GZSalesData(const std::string &s) : book_no_(s) {}
    GZSalesData(const std::string &s, unsigned n, double p) :
        book_no_(s), units_sold_(n), revenue_(p) {}
    /* 类外部定义构造函数 */
    //GZSalesData(std::istream &is = std::cin);
public:
    /* 7.2.1友元 */
    friend std::istream&   Read(std::istream &is, GZSalesData &item);
    friend std::ostream&   Print(std::ostream &os, GZSalesData &item);
    friend GZSalesData     Add(const GZSalesData& lhs, const GZSalesData &rhs);

    // 7.5.2 委托构造函数
    GZSalesData() : GZSalesData("", 0, 0){}
    GZSalesData(std::string &s) : GZSalesData(s, 0, 0) {}
    GZSalesData(std::istream &is) : GZSalesData() { Read(is, *this); }

    /*************************************************************************/

    GZSalesData(const GZSalesData &) = default;
    GZSalesData& operator=(const GZSalesData &);
    ~GZSalesData() = default;

public:
    friend std::ostream& operator<<(std::ostream &, const GZSalesData &);
    friend std::istream& operator>>(std::istream &, GZSalesData &);
    friend GZSalesData operator+(const GZSalesData &, const GZSalesData &);
    friend GZSalesData operator-(const GZSalesData &, const GZSalesData &);
    friend bool operator==(const GZSalesData &, const GZSalesData &);
    friend bool operator!=(const GZSalesData &, const GZSalesData &);
public:
    GZSalesData& operator+=(const GZSalesData &);
    GZSalesData& operator-=(const GZSalesData &);
public:
    // homework14.22
    GZSalesData& operator=(const std::string &isbn);
};

std::ostream& operator<<(std::ostream &, const GZSalesData &);
std::istream& operator>>(std::istream &, GZSalesData &);
GZSalesData operator+(const GZSalesData &, const GZSalesData &);
GZSalesData operator-(const GZSalesData &, const GZSalesData &);
bool operator==(const GZSalesData &, const GZSalesData &);
bool operator!=(const GZSalesData &, const GZSalesData &);

#endif // __GZ_SALES_DATA_H__
