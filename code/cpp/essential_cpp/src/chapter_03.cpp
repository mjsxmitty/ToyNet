
#include <list>
#include <iostream>
#include <string>
#include <vector>

#include "common.h"

const int s_int_size = 12;
const int s_string_size = 4;

int             s_ia[s_int_size] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
std::string     s_sa[s_string_size] = { "pooh", "piglet", "eeyore", "tigger" };

int main()
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

