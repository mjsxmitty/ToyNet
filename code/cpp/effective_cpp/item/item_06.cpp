

#include "item_06.h"
#include <iostream>

using namespace std;
using namespace effective_item_06;

/* 若不想使用编译器自动生成的函数,就应该明确拒绝 */
void Item06()
{
    cout << "**********item 06**********" << endl;
#if 1
    HomeForSale hs;
    //HomeForSale hs2(hs);
#endif
    cout << "***************************" << endl;
}
