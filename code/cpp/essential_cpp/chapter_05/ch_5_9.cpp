
#include <iostream>

#include "fibonacci_ver2.h"

using namespace std;
using namespace chapter_05::ver2;

int main()
{
    Fibonacci b;
    cout << b.WhatAmI() << endl;
    Fibonacci *ptr = b.Clone();
    cout << ptr->WhatAmI() << endl;

    NumSequence *p = b.Clone();
    cout << p->WhatAmI() << endl;

    return 0;
}
