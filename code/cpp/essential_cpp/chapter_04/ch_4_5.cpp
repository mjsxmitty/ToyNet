
#include <iostream>
#include <vector>
#include <algorithm>

#include "triangular.h"

using namespace std;

int main()
{
    char ch;
    bool more = true;

    while (more)
    {
        cout << "Enter a value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::IsElem(ival);
        cout << ival << (is_elem ? " is " : " is not ")
                << "an element in the Triangular series.\n"
                << "Anther value(y/n)? ";

        cin >> ch;
        if (ch == 'y' || ch == 'N')
            more = true;
        else
            more = false;
    }
    return 0;
}
