

#include "gz_sales_data.h"

using namespace std;

void GZChapter07();

/***************************7.1.2*********************************/
double GZSalesData::AvgPrice() const
{
    if (units_sold_)
        return revenue_ / units_sold_;
    else
        return 0;
}

GZSalesData& GZSalesData::Combine(const GZSalesData &rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_    += rhs.revenue_;
    return *this;
}

/*****************************************************************/
/***************************7.1.3*********************************/
istream& Read(istream &is, GZSalesData &item)
{
    double price = 0;
    is >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = price * item.units_sold_;
    return is;
}


ostream &Print(ostream &os, GZSalesData &item)
{
    os << item.Isbn() << ' ' << item.units_sold_ << ' '
       << item.revenue_ << ' ' << item.AvgPrice();
    return os;
}

GZSalesData Add(const GZSalesData &lhs, const GZSalesData &rhs)
{
    GZSalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}
/*****************************************************************/
/***************************7.1.4*********************************/
/*
GZSalesData::GZSalesData(istream &is)
{
    Read(is, *this);
}
*/

/* 13.1.1 拷贝构造函数 */
//GZSalesData::GZSalesData(const GZSalesData &orig)
//    : book_no_(orig.book_no_), units_sold_(orig.units_sold_),
//      revenue_(orig.revenue_)
//{

//}

/* 13.1.2 拷贝赋值运算符 */
//GZSalesData& GZSalesData::operator=(const GZSalesData &orig)
//{
//    book_no_ = orig.book_no_;
//    units_sold_ = orig.units_sold_;
//    revenue_ = orig.revenue_;

//    return *this;
//}

/* 13.1.5 使用default */
GZSalesData& GZSalesData::operator=(const GZSalesData &) = default;

/****************************************************************/
/***************************14.2*********************************/

ostream& operator<<(ostream &os, const GZSalesData &rhs)
{
    os << rhs.book_no_ << " "
       << rhs.units_sold_  << " "
       << rhs.revenue_ << " "
       << rhs.revenue_;
    return os;
}

/****************************************************************/
/***************************14.3*********************************/

GZSalesData& GZSalesData::operator+=(const GZSalesData &rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return  *this;
}

GZSalesData& GZSalesData::operator-=(const GZSalesData &rhs)
{
    units_sold_ -= rhs.units_sold_;
    revenue_ -= rhs.revenue_;
    return *this;
}

GZSalesData operator+(const GZSalesData &lhs, const GZSalesData &rhs)
{
    GZSalesData ret(lhs);
    ret += rhs;
    return ret;
}

GZSalesData operator-(const GZSalesData &lhs, const GZSalesData &rhs)
{
    GZSalesData ret(lhs);
    ret -= rhs;
    return ret;
}

bool operator==(const GZSalesData &lhs, const GZSalesData &rhs)
{
    return lhs.book_no_ == rhs.book_no_ &&
            lhs.units_sold_ == rhs.units_sold_ &&
            lhs.revenue_ == rhs.revenue_;
}

bool operator!=(const GZSalesData &lhs, const GZSalesData &rhs)
{
    return !(lhs == rhs);
}

GZSalesData& GZSalesData::operator=(const std::string &isbn)
{
    book_no_ = isbn;
    return *this;
}
