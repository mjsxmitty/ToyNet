
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

int main()
{
    ifstream    in_file("Makefile");
    ofstream    out_file("moo_cat.out");

    if (!in_file || !out_file)
    {
        cerr << "unalbe to open file!" << endl;
        return -1;
    }

    vector<string>  text;
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end(), common::StrSizeComp());
    //sort(text.begin(), text.end(), less<string>());

    ostream_iterator<string> os(out_file, "\n");
    copy(text.begin(), text.end(), os);

    return 0;
}
