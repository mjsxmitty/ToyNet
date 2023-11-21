
#include "item_08.h"

#include <iostream>

using namespace std;
using namespace effective_item_08;

void Item08()
{
    cout << "**********item 08**********" << endl;
#if 1
    DBCon dbc(DBConnection::create());
    dbc.Close();

#endif
    cout << "***************************" << endl;
}
