
#include <iostream>
#include <vector>
#include <algorithm>

#include "triangular.h"

using namespace std;

int main()
{
    Triangular tri(20);
    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";

    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    cout << tri << endl;

    while (beg != end)
    {
        cout << *beg << '\t';
        ++beg;
    }
    cout << endl;
    return 0;
}
