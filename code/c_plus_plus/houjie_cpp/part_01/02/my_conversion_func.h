
#ifndef __MY_CONVERSION_FUNC_H__
#define __MY_CONVERSION_FUNC_H__

#include <iostream>

//分数类
class Fraction
{
public:
    int     m_numerator;
    int     m_denominator;     
public:
    //不加explicit表示通过一个参数可以构造对应的对象
    //一个int对象可以转换为Fraction对象
    explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}

    //Fraction d2 = f + 4;---- > f===>double
    //Fraction类型可以转换为double
    operator double() const 
    {
        return  ((double) m_numerator / m_denominator); 
    };

    //Fraction d2 = f + 4;--- > +===>operator+ && 4====>Fraction obj
    Fraction operator+(const Fraction &f) 
    { 
        return Fraction(m_numerator + f.m_numerator, m_denominator + f.m_denominator); 
    }

};


void TestCoverFunc();


#endif
