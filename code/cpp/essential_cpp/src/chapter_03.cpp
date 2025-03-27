
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "common.h"

const int s_int_size = 12;
const int s_string_size = 4;

int             s_ia[s_int_size] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
std::string     s_sa[s_string_size] = { "pooh", "piglet", "eeyore", "tigger" };

int main1()
{
    const int           *iptr = nullptr;
    const std::string    *sptr = nullptr;

    std::vector<int>            s_ivec(s_ia, s_ia + s_int_size);
    std::vector<std::string>    s_svec(s_sa, s_sa + s_string_size);

    iptr = common::Find(s_ia, s_ia + s_int_size, s_ia[10]);
    if (iptr == &s_ivec[10])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test Find with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = common::Find(common::Begin(s_svec), common::End(s_svec), s_svec[1]);
    if (sptr == &s_svec[1])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test Find with char vector type func failed, ret: "
             << *sptr << std::endl;

    std::list<int>    slist(s_ia, s_ia + s_int_size);
    std::list<int>::iterator it = common::Find(slist.begin(), slist.end(), 1024);
    if (it != slist.end())
        std::cout << *it << std::endl;
    else
        std::cout << "not find appoint val."
            << std::endl;

    return 0;
}

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; }

int main2()
{
    std::vector<int>            s_ivec(s_ia, s_ia + s_int_size);

    std::for_each(s_ivec.begin(), s_ivec.end(), [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;
#if 1
    std::vector<int> vec1 = common::FilterVer(s_ivec, s_int_size, GreaterThan);
    for_each(vec1.begin(), vec1.end(), [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;

    std::vector<int> vec2 = common::FilterVer(s_ivec, s_int_size, std::less<int>());
    for_each(vec2.begin(), vec2.end(), [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;
#endif
    int ia[s_int_size];
    auto ia2 = common::Filter(s_ia, s_ia + s_int_size, ia, s_int_size, std::less<int>());
    std::for_each(ia, ia2, [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;

    std::vector<int> vec3;
    common::Filter(s_ia, s_ia + s_int_size, back_inserter(vec3), s_int_size, std::greater<int>());
    for_each(vec3.begin(), vec3.end(), [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;
#if 1
    for_each(begin(s_sa), end(s_sa), [](const std::string &s) { std::cout << s << ' ';});
    std::cout << std::endl;

    std::list<std::string> slist;
    common::Filter(s_sa, s_sa + s_string_size, back_inserter(slist), "piglet", std::greater<std::string>());
    std::for_each(slist.begin(), slist.end(), [](const std::string &s) { std::cout << s << ' ';});
    std::cout << std::endl;

    auto ret_vec = common::SubVec(s_ivec, s_int_size);
    std::for_each(ret_vec.begin(), ret_vec.end(), [](int i) { std::cout << i << ' ';});
    std::cout << std::endl;
#endif

    return 0;
}

std::vector<int>     s_ivec(s_ia, s_ia + s_int_size);

int main()
{
    int iarray[s_int_size];
    common::Filter(s_ia, s_ia + s_int_size, iarray, s_int_size, std::less<int>());   // 数组不支持安插操作

    std::vector<int> ivec(s_int_size);
    common::Filter(s_ivec.begin(), s_ivec.end(), back_inserter(ivec), s_int_size, std::greater<int>());
    return 0;
}