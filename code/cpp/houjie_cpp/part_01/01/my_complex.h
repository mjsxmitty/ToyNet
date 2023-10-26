

#ifndef __MY_COMPLEX_H__
#define __MY_COMPLEX_H__

#include <iostream>

class Complex
{
public:
    Complex ( double r = 0, double i = 0 ) : re_(r), im_(i){}
    //MyComplex() : m_re(0), m_im(0){}

    double real() const {return re_;}
    double imag() const {return im_;}

    Complex& operator+=(const Complex&);

    friend Complex& Dopal(Complex*, const Complex&);
    friend std::ostream& operator<<(std::ostream &os, const Complex &x);

    /*同一个class不同objects互为友元（直接使用对象成员）*/
    int Func(const Complex &para) { return para.im_ + para.re_; }
private:
    double re_;
    double im_;
};

//返回引用
inline Complex& Dopal(Complex *ths, const Complex &r)
{
    ths->re_ += r.re_;
    ths->im_ += r.im_;
    return *ths;
}

inline Complex& Complex::operator+=(const Complex &r)
{
    return Dopal(this, r);
}

/**
 * 全局函数定义
 * Image(C) 
 */
inline double Imag(const Complex &x) { return x.imag(); }
inline double Real(const Complex &x) { return x.real(); } 

/**
 * 操作符重载：非成员函数
 * c1 + c2
 * c1 + 1
 * 2 + c2
 * +c1
 * -c2
 * */
inline Complex operator+(const Complex &x, const Complex &y)
{
    //临时对象
    return Complex(x.imag() + y.imag(), x.real() + y.real());
}

inline Complex operator+(const Complex &x, double y)
{
    return Complex(x.imag() + y, x.real());
}

inline Complex operator+(double x, const Complex &y)
{
    return Complex(x + y.imag(), y.real());
}

inline Complex operator+(const Complex &x)
{
    return x;
}

inline Complex operator-(const Complex &x)
{
    return Complex(-Real(x), -Imag(x));
}

inline bool operator==(const Complex &x, const Complex &y)
{
    return Real(x) == Real(y) && Imag(x) == Imag(y);
}

inline bool operator==(const Complex &x, double y)
{
    return Real(x) == y && Imag(x) == 0;
}

inline bool operator==(double x, const Complex &y)
{
    return x == Real(y) && Imag(y) == 0;
}

inline bool operator!=(const Complex &x, const Complex &y)
{
    return Real(x) != Real(y) || Imag(x) != Imag(y);
}

inline bool operator!=(const Complex &x, double y)
{
    return Real(x) != y || Imag(x) != 0;
}

inline bool operator!=(double x, const Complex &y)
{
    return x != Real(y) || Imag(y) != 0;
}

//共轭复数
inline Complex Conj(const Complex &x)
{
    return Complex(Real(x), -Imag(x));
}

#endif // MYCOMPLEX_H
