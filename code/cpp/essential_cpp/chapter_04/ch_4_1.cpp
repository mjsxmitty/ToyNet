
#include <iostream>
#include <vector>
#include <algorithm>

#include "stack.h"

using namespace std;

int main()
{
    Stack sta;
    cout << sta.Empty() << endl;
    FillStack(sta, cin);

    return 0;
}
