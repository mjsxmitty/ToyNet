
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
    const int part_val = 10;

    for_each(s_ivec.begin(), s_ivec.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#if 0
    vector<int> vec1 = FilterVer1(s_ivec, part_val, GreaterThan);
    for_each(vec1.begin(), vec1.end(), [](int i) { cout << i << ' ';});
    cout << endl;

    vector<int> vec2 = FilterVer2(s_ivec, part_val, less<int>());
    for_each(vec2.begin(), vec2.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#endif
    int ia[s_int_size];
    auto ia2 = Filter(s_ia, s_ia + s_int_size, ia, part_val, less<int>());
    for_each(ia, ia2, [](int i) { cout << i << ' ';});
    cout << endl;

    vector<int> vec3;
    Filter(s_ia, s_ia + s_int_size, back_inserter(vec3), part_val, greater<int>());
    for_each(vec3.begin(), vec3.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#if 0
    for_each(begin(s_sa), end(s_sa), [](const string &s) { cout << s << ' ';});
    cout << endl;

    list<string> slist;
    Filter(s_sa, s_sa + s_string_size, back_inserter(slist), "piglet", greater<string>());
    for_each(slist.begin(), slist.end(), [](const string &s) { cout << s << ' ';});
    cout << endl;

    auto ret_vec = SubVec(s_ivec, part_val);
    for_each(ret_vec.begin(), ret_vec.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#endif

    return 0;
}
