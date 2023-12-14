
#include <iostream>
#include <vector>
#include <algorithm>

#include "triangular.h"

using namespace std;

int main()
{
    Triangular tri(4);
    cout << tri << " -- sum of elements: "
        << Sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: "
        << Sum(tri2) << endl;

    Triangular tri3(4, 8);
    cout << tri3 << " -- sum of elements: "
        << Sum(tri3) << endl;
    return 0;
}
