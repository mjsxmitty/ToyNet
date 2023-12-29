
#include "item_08.h"
#include <iostream>

using namespace std;


/* 别让异常逃离析构函数 */
int main()
{
    DBCon dbc(DBConnection::create());
    dbc.Close();

    return 0;
}
