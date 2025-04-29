
#include <iostream>

#include "mat.h"
#include "book.h"
#include "audio_book.h"
#include "common.h"

using namespace std;

int main1()
{
    {
        common::LibMat libmat;
        Print(libmat);
    }
    cout << "==================================" << endl;

    {
        common::Book book("a", "b");
        Print(book);
    }
    cout << "==================================" << endl;

    {
        common::AudioBook audio("1", "2", "3");
        Print(audio);
    }

    return 0;
}

int main2()
{
    using namespace ver3;

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

int main3()
{
    using namespace ver3;

    const int pos = 8;
    Fibonacci fib;
    Display(cout, fib, pos);

    Fibonacci fib2(8);
    cout << fib2 << endl;

    return 0;
}

int main4()
{
    using namespace ver3;
    Fibonacci a;
    cout << a << endl;

    Fibonacci b(5,3);
    a = b;
    cout << a << endl;

    Fibonacci c = b;
    cout << c << endl;

    return 0;
}

int main5()
{
    using namespace ver4;

    Fibonacci b;
    cout << b.WhatAmI() << endl;

    Fibonacci *ptr = b.Clone();
    cout << ptr->WhatAmI() << endl;

    NumSequence *p = b.Clone();
    cout << p->WhatAmI() << endl;

    return 0;
}

int main()
{
    using namespace ver4;

    Fibonacci fib;
    NumSequence *ps = &fib;
#if 1
    if (typeid(*ps) == typeid(Fibonacci))
    {
        Fibonacci *p = static_cast<Fibonacci *>(ps);
        cout << p->WhatAmI() << endl;
        //p->Fibonacci::GenElems(64);   //error
    }
#endif

    if (Fibonacci *pf = dynamic_cast<Fibonacci *>(ps))
        cout << pf->WhatAmI() << endl;

    return 0;
}