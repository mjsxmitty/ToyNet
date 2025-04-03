
#include "common.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <fstream>
#include <set>
#include <sstream>

#include <map>

using namespace std;
using namespace common;

int main()
{
    ifstream    name_file("families.txt");
    if (!name_file)
    {
        cerr << "open name file failed.\n";
        return -1;
    }

    svec_map    familes;
    InitFamilyMap(name_file, familes);

    string      name;
    while (1)
    {
        cout << "please enter a family name or q to quit: ";
        cin >> name;
        if (name == "q")
            break;

        QueryMap(name, familes);
    }

    DisplayMap(familes, cout);

    return 0;
}
