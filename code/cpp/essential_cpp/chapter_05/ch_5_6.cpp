
#include <iostream>

#include "fibonacci_ver1.h"

using namespace std;
using namespace chapter_05::ver1;

int main()
{
    const int postion = 8;

    Fibonacci fib;
    Display(cout, fib, postion);

    Fibonacci fib2(8);
    cout << fib2 << endl;

    return 0;
}
