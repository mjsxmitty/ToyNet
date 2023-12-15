
#include <iostream>

#include "fibonacci_ver1.h"

using namespace std;
using namespace chapter_05;

int main()
{
    using namespace ver1;

    Fibonacci fib;
    cout << "fib: the begging at element 1 for 1 element: \n"
        << fib << endl;

    Fibonacci fib2(16);
    cout << "fib: the begging at element 1 for 16 element: \n"
        << fib2 << endl;

    Fibonacci fib3(8, 12);
    cout << "fib: the begging at element 12 for 8 element: \n"
        << fib3 << endl;

    return 0;
}
