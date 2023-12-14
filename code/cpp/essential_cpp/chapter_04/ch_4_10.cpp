
#include <iostream>
#include <vector>
#include <algorithm>

#include "triangular.h"

using namespace std;

int main()
{
    Triangular tri(6, 3);
    cout << tri << endl;

    Triangular tri2;
    cin >> tri2;
    cout << tri2 << endl;

    return 0;
}
