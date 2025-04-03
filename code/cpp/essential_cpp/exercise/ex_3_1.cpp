
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

#include "common.h"

using namespace std;
using namespace common;

int main()
{
    ifstream    in_file("Makefile");
    ofstream    out_file("moo_cat.map");

    if (!in_file || !out_file)
    {
        cerr << "open input/output file failed!" << endl;
        return -1;
    }

    set<string> exclude_set;
    InitExclusionSet(exclude_set);

    map<string, int> word_count;
    ProcessFile(word_count, exclude_set, in_file);

    UserQuery(word_count);

    return 0;
}
