
#include "sales_data.h"

using namespace std;

#if 0
istream& Read(istream &is, SalesData &item)
{
    double price = 0;
    is >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = price * item.units_sold_;
    return is;
}

ostream& Print(ostream &os, SalesData &item)
{
    os << item.Isbn() << ' ' << item.units_sold_ << ' '
       << item.revenue_ << ' ' << item.AvgPrice();
    return os;
}

SalesData Add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}
#endif

double SalesData::AvgPrice() const
{
    if (units_sold_)
        return revenue_ / units_sold_;
    else
        return 0;
}

#if 0
SalesData& SalesData::Combine(const SalesData &rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_    += rhs.revenue_;
    return *this;
}
#endif
#if 0
SalesData::SalesData(istream &is)
{
    Read(is, *this);
}


SalesData::SalesData(const SalesData &orig) :
                            book_no_(orig.book_no_),
                            units_sold_(orig.units_sold_),
                            revenue_(orig.revenue_)
{

}

SalesData& SalesData::operator=(const SalesData &orig)
{
    book_no_ = orig.book_no_;
    units_sold_ = orig.units_sold_;
    revenue_ = orig.revenue_;

    return *this;
}

#endif

SalesData& SalesData::operator=(const SalesData &) = default;

ostream& operator<<(ostream &os, const SalesData &rhs)
{
    os << rhs.book_no_ << ", "
        << rhs.units_sold_  << ", "
        << rhs.revenue_ << ", "
        << rhs.revenue_;
    return os;
}

std::istream& operator>>(std::istream &in, SalesData &rhs)
{
    double price = 0.0;
    in >> rhs.book_no_ >> rhs.units_sold_ >> price;
    if (in)
        rhs.revenue_ = rhs.units_sold_ * price;
    else
        rhs = SalesData();

    return in;
}

SalesData& SalesData::operator+=(const SalesData &rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return  *this;
}

SalesData& SalesData::operator-=(const SalesData &rhs)
{
    units_sold_ -= rhs.units_sold_;
    revenue_ -= rhs.revenue_;
    return *this;
}

SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
    SalesData ret(lhs);
    ret += rhs;
    return ret;
}

SalesData operator-(const SalesData &lhs, const SalesData &rhs)
{
    SalesData ret(lhs);
    ret -= rhs;
    return ret;
}

bool operator==(const SalesData &lhs, const SalesData &rhs)
{
    return lhs.book_no_ == rhs.book_no_ &&
            lhs.units_sold_ == rhs.units_sold_ &&
            lhs.revenue_ == rhs.revenue_;
}

bool operator!=(const SalesData &lhs, const SalesData &rhs)
{
    return !(lhs == rhs);
}

SalesData& SalesData::operator=(const std::string &isbn)
{
    book_no_ = isbn;
    return *this;
}
