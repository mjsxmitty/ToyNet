


#include "my_conversion_func.h"


void TestCoverFunc()
{
    Fraction f(3, 5);

    double d = 4 + f;   
    //Fraction d = f + 4;
    /**
     * 此时有两种错误（不加explicit）：
     * （1） 调用operator+
     * (2) 4转换为Fraction对象再相加
     * 加explicit解释为：
     * 4不能转换为Fraction对象
    */
    
}