
#ifndef __CPP_PRIMER_CHAPTER_07_SALESDATE_H__
#define __CPP_PRIMER_CHAPTER_07_SALESDATE_H__

#include <string>
#include <iostream>

class SalesData
{
public:
    //��Ԫ����λ�ò���,�����ڽ�����ָ���˷���Ȩ��
    friend std::istream& Read(std::istream &in, SalesData &item);
    friend std::ostream& Print(std::ostream &out, const SalesData &item);
    friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
    friend std::ostream& operator<<(std::ostream &os, const SalesData &item);
    friend std::istream& operator>>(std::istream &in, SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
public:
    //�ṩ���캯��,��û��Ĭ�Ϲ��캯��
    SalesData() = default;
    //������ʽת��
    explicit SalesData(std::istream &in);
    explicit SalesData(const std::string &s) : book_no_(s){}
    SalesData(const std::string &s, unsigned n, double p)
        : book_no_(s), units_sold_(n), revenue_(p * n){std::cout << "func a" << std::endl;}

    /*ί�й��캯��*/
    // SalesData() : SalesData("", 0, 0) {std::cout << "func b" << std::endl;}
    // SalesData(const std::string &s) : SalesData(s, 0, 0) {std::cout << "func c" << std::endl;}
    
    //ί��д�ڶ��崦
    //SalesData(std::istream &in);
    //ί��д��������
    // SalesData(std::istream &in) : SalesData() { Read(in, *this);}
    // -->SalesData()-->SalesData(const std::string &s, unsigned n, double p) -->Read
    SalesData(const SalesData &rhs) : book_no_(rhs.book_no_), units_sold_(rhs.units_sold_), revenue_(rhs.revenue_) {}
    SalesData& operator=(const SalesData &rhs);
    SalesData& operator=(const std::string &isbn);
    SalesData& operator+=(const SalesData &rhs);

    //std::string operator std::string() const { return book_no_; }
    // double operator double() const { return revenue_; }
public:
    std::string Isdn() const { return book_no_; }
    SalesData& Combine(const SalesData &item);
private:
    double AvgPrice() const ;
private:
    std::string     book_no_;
    unsigned        units_sold_;
    double          revenue_;
};

//��Ԫ������Ҫ�����ٴ�����
std::istream& Read(std::istream &in, SalesData &item);
std::ostream& Print(std::ostream &out, const SalesData &item);
SalesData Add(const SalesData &lhs, const SalesData &rhs);

std::ostream& operator<<(std::ostream &os, const SalesData &item);
std::istream& operator>>(std::istream &in, SalesData &item);
#endif // __CPP_PRIMER_CHAPTER_07_SALESDATE_H__
