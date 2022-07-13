

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
