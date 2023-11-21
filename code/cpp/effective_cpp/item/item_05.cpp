

#include "item_05.h"
#include <iostream>

using namespace std;
using namespace effective_item_05;

/* 了解C++默默编写并调用那些函数 */
void Item05()
{
    cout << "**********item 05**********" << endl;
#if 1
    std::string name1("abc");
    NameObject<int> no1(name1, 12);

    NameObject<int> no2(no1);
    cout << no2.name_value_ << no2.object_value_ << endl;

    no2.name_value_ = "ddd";
    cout << no1.name_value_ << no1.object_value_ << endl;

    //no2 = no1;
#endif
    cout << "***************************" << endl;
}
