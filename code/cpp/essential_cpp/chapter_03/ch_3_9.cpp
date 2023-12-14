
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
    int iarray[s_int_size];
    Filter(s_ia, s_ia + s_int_size, iarray, s_int_size, less<int>());   // 数组不支持安插操作

    vector<int> ivec(s_int_size);
    Filter(s_ivec.begin(), s_ivec.end(), back_inserter(ivec), s_int_size, greater<int>());
    return 0;
}
