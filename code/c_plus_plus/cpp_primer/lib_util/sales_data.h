
#ifndef __CPP_PRIMER_SALESDATE_H__
#define __CPP_PRIMER_SALESDATE_H__

#include <string>
#include <iostream>

class SalesData
{
public:

    /* 7-1-2-1 引入this & const & 类的作用域和成员函数 */
    //成员函数由对象调用得以使用: total.Isbn() --> SalesData::Isbn(&total)
    //普通函数:this的类型 SalesData *const --> const函数：const SalesData *const
    std::string Isdn() const
    {
        // 可以直接使用成员: 先编译声明再编译函数体
        //return this->book_no_;
        return book_no_;
    }

    /* 7-1-2-3 返回this对象的函数 */
    SalesData& Combine(const SalesData &item);

private:
    /* 7-1-2-2 类外定义成员函数 */
    double AvgPrice() const ;
public:
    /* 7-1-4-1 默认构造函数 */
    //某些类不能使用合成默认构造函数
    //自定义构造函数之后要想使用默认构造函数就必须声明default
    //default既可以出现在声明也可以出现在定义之中
    SalesData() = default;

    /* 7-1-4-2 构造函数初始值列表 */
    //忽略成员以合成默认构造函数相同方式隐式初始化
    explicit SalesData(const std::string &s) : book_no_(s)
    {
        std::cout << "SalesData::SalesData(s) --- consturctor\n";
    }

    SalesData(const std::string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p * n)
    {
        std::cout << "SalesData::SalesData(s,n,p) --- consturctor\n";
    }

    /* 7-1-4-2 类外定义构造函数 */
    explicit SalesData(std::istream &in);
public:
    /* 7-2-1 友元*/
    //存在访问控制 ---> 需要友元声明
    //声明位置不限 ---> 不受访问控制符约束
    //仅仅指明访问权限,并非声明,类外需要再次声明
    //类外部与类在同一头文件声明
    friend std::istream& Read(std::istream &in, SalesData &item);
    friend std::ostream& Print(std::ostream &out, const SalesData &item);
    friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
public:
    /* 7-5-1 默认实参和构造函数 */
    //warn:防止冲突...
//    SalesData(std::istream &in = std::cin);

    /* 7-5-2 委托构造函数 */
//    SalesData() : SalesData("", 0, 0) { }
//    SalesData(const std::string &s) : SalesData(s, 0, 0) { }
//    SalesData(std::istream &in) : SalesData() { Read(in, *this); }
    // -->SalesData()-->SalesData(const std::string &s, unsigned n, double p) -->Read
public:
    friend std::ostream& operator<<(std::ostream &os, const SalesData &item);
    friend std::istream& operator>>(std::istream &in, SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
public:
    SalesData(const SalesData &rhs) : book_no_(rhs.book_no_), units_sold_(rhs.units_sold_), revenue_(rhs.revenue_) {}
    SalesData& operator=(const SalesData &rhs);
    SalesData& operator=(const std::string &isbn);
    SalesData& operator+=(const SalesData &rhs);

    //std::string operator std::string() const { return book_no_; }
    // double operator double() const { return revenue_; }

private:
    std::string     book_no_;       //isbn
    unsigned        units_sold_;    //销量
    double          revenue_;       //总收入
};

/* 7-1-3 与类相关的非成员函数 ---> 与类声明再同一头文件 */
std::istream& Read(std::istream &in, SalesData &item);
std::ostream& Print(std::ostream &out, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);

std::ostream& operator<<(std::ostream &os, const SalesData &item);
std::istream& operator>>(std::istream &in, SalesData &item);

#endif // __CPP_PRIMER_SALESDATE_H__
