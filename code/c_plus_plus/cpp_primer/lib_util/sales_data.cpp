
#include "sales_data.h"

#include <iostream>
#include <string>

using namespace std;

/* 类外定义成员函数 */

//与类内声明一致
//类作用域(遇到类名便认为在在类作用域内)
//const声明
double SalesData::AvgPrice() const
{
    return units_sold_ ? revenue_ / units_sold_ : 0;
}

SalesData& SalesData::Combine(const SalesData &item)
{
    units_sold_ += item.units_sold_;
    revenue_ += item.revenue_;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const SalesData &item)
{
    os << item.Isdn() << " " << item.units_sold_ << " "
       << item.revenue_ << " " << item.AvgPrice();
    return os;
}

std::istream& operator>>(std::istream &in, SalesData &item)
{
    double price;
    in >> item.book_no_ >> item.units_sold_ >> price;

    if (in)
        item.revenue_ = item.units_sold_ * price;
    else
        item = SalesData();

    return in;
}


SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
    // SalesData ret(lhs);
    // ret += rhs;
    // return ret;

    SalesData ret = lhs;
    ret.units_sold_ += rhs.units_sold_;
    ret.revenue_ += rhs.revenue_;
    return ret;
}
///执锟叫猴拷锟斤拷锟斤拷之前,锟斤拷员默锟较筹拷始锟斤拷
SalesData::SalesData(istream &in)
{
    Read(in, *this);
    // in >> *this;
}

SalesData& SalesData::operator=(const SalesData &rhs)
{
    book_no_ = rhs.book_no_;
    units_sold_ = rhs.units_sold_;
    revenue_ = rhs.revenue_;
    return *this;
}

SalesData& SalesData::operator=(const string &isbn)
{
    book_no_ = isbn;
    return *this;
}

SalesData& SalesData::operator+=(const SalesData &rhs)
{
    // units_sold_ += rhs.units_sold_;
    // revenue_ += rhs.revenue_;
    // return *this;

    *this = (*this) + rhs;
    return *this;
}

//锟斤拷始锟斤拷锟叫憋拷锟斤拷锟节讹拷锟藉处
// SalesData::SalesData(std::istream &in) : SalesData()
//{
//    //std::cout << "func d" << std::endl;
//    Read(in, *this);
//}





istream &Read(istream &in, SalesData &item)
{
    double price = 0;
    in >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = item.units_sold_ * price;
    return in;
}

ostream &Print(ostream &out, const SalesData &item)
{
    out << item.book_no_ << " " << item.units_sold_ << " "
        << item.revenue_ << " " << item.AvgPrice();
    return out;
}

SalesData Add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.Combine(rhs);
    return sum;
}
