
#include <iostream>

#include "fibonacci_ver2.h"

using namespace std;
using namespace chapter_05::ver2;

int main()
{
    Fibonacci fib;
    NumSequence *ps = &fib;
#if 0
    if (typeid(*ps) == typeid(Fibonacci))
    {
        Fibonacci *p = static_cast<Fibonacci *>(ps);
        ps->WhatAmI();
        ps->Fibonacci::GenElems(64);   //error
    }
#endif

    if (typeid (*ps) == typeid (Fibonacci))
    {
        if (Fibonacci *pf = dynamic_cast<Fibonacci *>(ps))
            cout << pf->WhatAmI() << endl;
    }

    return 0;
}
