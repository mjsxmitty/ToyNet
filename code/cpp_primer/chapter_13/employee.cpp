

#include "employee.h"

#include <iostream>

using namespace std;

int Employee::sn = 0;

void PrintEmployee(const Employee &e)
{
    cout << e.GetName() << " : " << e.GetMySn() << endl;
}
