

#include "my_complex.h"

//重载输出
//为什么放在头文件不可以？换成inline呢？
std::ostream& operator<<(std::ostream &os, const Complex &x)
{
    return os << "( " << Real(x) << ", " << Imag(x) << " )";
}