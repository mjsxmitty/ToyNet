
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

int main()
{
    ifstream    name_file("families.txt");
    if (!name_file)
    {
        cerr << "open name file failed.\n";
        return -1;
    }

    common::svec_map    familes;
    common::InitFamilyMap(name_file, familes);

    string      name;
    while (1)
    {
        cout << "please enter a family name or q to quit: ";
        cin >> name;
        if (name == "q")
            break;

        common::QueryMap(name, familes);
    }

    common::DisplayMap(familes, cout);

    return 0;
}
