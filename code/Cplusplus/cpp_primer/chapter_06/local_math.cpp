
#include "local_math.h"

int Fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

/*递归秋阶乘*/
int Factorial(int val)
{
    if (val > 1)
        return Factorial(val - 1) * val;    
    return 1;
}

/*辗转相除秋最大公约数*/
int Gcd(int v1, int v2)
{
    while (v2)
    {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;       
    }
    return v1;
}
