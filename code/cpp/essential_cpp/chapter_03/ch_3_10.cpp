

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

using namespace std;
using namespace chapter_03;

int main()
{
#if 0
    istream_iterator<string>    is(cin);
    istream_iterator<string>    eof;

    vector<string>  local_vec;
    copy(is, eof, back_inserter(local_vec));
    sort(local_vec.begin(), local_vec.end());

    ostream_iterator<string>    os(cout, "\n");
    copy(local_vec.begin(), local_vec.end(), os);
    cout <<endl;
#endif
#if 1
    fstream     in_file("Makefile");
    ofstream    out_file("test.txt");

    if (!in_file || !out_file)
    {
        cout << "open input/output file failed." << endl;
        return -1;
    }

    istream_iterator<string>    is(in_file);
    istream_iterator<string>    eof;

    vector<string>  vec;
    copy(is, eof, back_inserter(vec));

    sort(vec.begin(), vec.end());

    ostream_iterator<string>    os(out_file, "\n");
    copy(vec.begin(), vec.end(), os);
#endif
    return 0;
}
