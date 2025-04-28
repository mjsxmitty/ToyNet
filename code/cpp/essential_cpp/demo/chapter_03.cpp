
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "common.h"

using namespace std;
using namespace common;

const int s_int_size = 12;
const int s_string_size = 4;

int             s_ia[s_int_size] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
string     s_sa[s_string_size] = { "pooh", "piglet", "eeyore", "tigger" };

int main1()
{
    const int           *iptr = nullptr;
    const string    *sptr = nullptr;

    vector<int>            s_ivec(s_ia, s_ia + s_int_size);
    vector<string>    s_svec(s_sa, s_sa + s_string_size);

    iptr = Find(s_ia, s_ia + s_int_size, s_ia[10]);
    if (iptr == &s_ivec[10])
        cout << *iptr << endl;
    else
        cout << "test Find with int array type func failed, ret: "
             << *iptr << endl;

    sptr = Find(Begin(s_svec), End(s_svec), s_svec[1]);
    if (sptr == &s_svec[1])
        cout << *sptr << endl;
    else
        cout << "test Find with char vector type func failed, ret: "
             << *sptr << endl;

    list<int>    slist(s_ia, s_ia + s_int_size);
    list<int>::iterator it = Find(slist.begin(), slist.end(), 1024);
    if (it != slist.end())
        cout << *it << endl;
    else
        cout << "not find appoint val."
            << endl;

    return 0;
}

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; }

int main2()
{
    vector<int>            s_ivec(s_ia, s_ia + s_int_size);

    for_each(s_ivec.begin(), s_ivec.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#if 1
    vector<int> vec1 = FilterVer(s_ivec, s_int_size, GreaterThan);
    for_each(vec1.begin(), vec1.end(), [](int i) { cout << i << ' ';});
    cout << endl;

    vector<int> vec2 = FilterVer(s_ivec, s_int_size, less<int>());
    for_each(vec2.begin(), vec2.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#endif
    int ia[s_int_size];
    auto ia2 = Filter(s_ia, s_ia + s_int_size, ia, s_int_size, less<int>());
    for_each(ia, ia2, [](int i) { cout << i << ' ';});
    cout << endl;

    vector<int> vec3;
    Filter(s_ia, s_ia + s_int_size, back_inserter(vec3), s_int_size, greater<int>());
    for_each(vec3.begin(), vec3.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#if 1
    for_each(begin(s_sa), end(s_sa), [](const string &s) { cout << s << ' ';});
    cout << endl;

    list<string> slist;
    Filter(s_sa, s_sa + s_string_size, back_inserter(slist), "piglet", greater<string>());
    for_each(slist.begin(), slist.end(), [](const string &s) { cout << s << ' ';});
    cout << endl;

    auto ret_vec = SubVec(s_ivec, s_int_size);
    for_each(ret_vec.begin(), ret_vec.end(), [](int i) { cout << i << ' ';});
    cout << endl;
#endif

    return 0;
}

vector<int>     s_ivec(s_ia, s_ia + s_int_size);

int main()
{
    int iarray[s_int_size];
    Filter(s_ia, s_ia + s_int_size, iarray, s_int_size, less<int>());   // 数组不支持安插操作

    vector<int> ivec(s_int_size);
    Filter(s_ivec.begin(), s_ivec.end(), back_inserter(ivec), s_int_size, greater<int>());
    return 0;
}