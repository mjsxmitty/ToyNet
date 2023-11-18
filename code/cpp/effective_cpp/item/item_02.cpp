
#include "item_02.h"
#include <vector>
#include <iostream>

using namespace std;

void Item02()
{
    cout << "**********item 01**********" << endl;
#if 1
    std::vector<int> ivec(10, 1024);
    const std::vector<int>::iterator iter = ivec.begin();
    *iter = 0;
    //++iter;

    std::vector<int>::const_iterator citer = ivec.cbegin();
    //*citer = 10;
    ++citer;
#endif

    cout << "***************************" << endl;
}
