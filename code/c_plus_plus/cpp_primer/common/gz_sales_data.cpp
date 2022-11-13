

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

/********************************************************************/


//GZSalesData::GZSalesData(const GZSalesData &orig) :
//                            book_no_(orig.book_no_),
//                            units_sold_(orig.units_sold_),
//                            revenue_(orig.revenue_)
//{

//}

//GZSalesData& GZSalesData::operator=(const GZSalesData &orig)
//{
//    book_no_ = orig.book_no_;
//    units_sold_ = orig.units_sold_;
//    revenue_ = orig.revenue_;

//    return *this;
//}

GZSalesData& GZSalesData::operator=(const GZSalesData &) = default;

/****************************************************************/
/***************************14.2*********************************/

ostream& operator<<(ostream &os, const GZSalesData &rhs)
{
    os << rhs.book_no_ << ", "
       << rhs.units_sold_  << ", "
       << rhs.revenue_ << ", "
       << rhs.revenue_;
    return os;
}

std::istream& operator>>(std::istream &in, GZSalesData &rhs)
{
    double price = 0.0;
    in >> rhs.book_no_ >> rhs.units_sold_ >> price;
    if (in)
        rhs.revenue_ = rhs.units_sold_ * price;
    else
        rhs = GZSalesData();

    return in;
}

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
