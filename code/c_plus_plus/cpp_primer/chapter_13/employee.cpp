

#include "employee.h"

#include <iostream>

using namespace std;

int GZEmployee::sn = 0;

void PrintGZEmployee(const GZEmployee &e)
{
    cout << e.GetName() << " : " << e.GetMySn() << endl;
}
