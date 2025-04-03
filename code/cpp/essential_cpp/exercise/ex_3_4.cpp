
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
    ifstream name_file("Makefile");
    if (!name_file)
    {
        cerr << "open input name file failed.\n";
        return -1;
    }

    ofstream even_file("even_file"), odd_file("odd_file");
    if (!even_file || !odd_file)
    {
        cerr << "open out file failed.\n";
        return -1;
    }

    istream_iterator<string>    in(name_file), eof;
    vector<string>  input;

    copy(in, eof, back_inserter(input));
    vector<string>::iterator div = partition(input.begin(), input.end(), EvenElem());

    ostream_iterator<string> even_it(even_file, "\n"), odd_it(odd_file, "\t");

    copy(input.begin(), div, even_it);
    copy(div, input.end(), odd_it);
}
