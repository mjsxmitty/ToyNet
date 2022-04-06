
#include <iostream>
#include "date.h"

using namespace std;

void GZDate::Init()
{
    cout << "input year,month,day" << endl;
    cin >> year >> month >> day;
}

void GZDate::Print()
{
    cout << "\tyear: " << year
         << "\n\tmonth: " << month
         << "\n\tday: " << day
         << endl;
}

bool GZDate::IsLeapYear()
{
    return ((year % 4 == 0 && year % 100 != 0) || year %400 == 0);
}
