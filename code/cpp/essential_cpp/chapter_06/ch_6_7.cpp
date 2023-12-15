
#include <iostream>

#include "chapter_06.h"

using namespace std;
using namespace chapter_06;

int main()
{
    LessThanPred<int> ltpi(1024);
    LessThanPred<string, StringLess> ltps("1024");

    cout << ltpi(1) << endl;
    cout << ltps("abc") << endl;

    return 0;
}
