
#include <list>
#include <iostream>
#include "common.h"

using namespace chapter_03;

int main()
{
    const int       *iptr = nullptr;
    const std::string    *sptr = nullptr;

    iptr = Find(s_ia, s_ia + s_int_size, s_ia[10]);
    if (iptr == &s_ivec[10])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test Find with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = Find(Begin(s_svec), End(s_svec), s_svec[1]);
    if (sptr == &s_svec[1])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test Find with char vector type func failed, ret: "
             << *sptr << std::endl;

    std::list<int>    slist(s_ia, s_ia + s_int_size);
    std::list<int>::iterator it = Find(slist.begin(), slist.end(), 1024);
    if (it != slist.end())
        std::cout << *it << std::endl;
    else
        std::cout << "not find appoint val."
            << std::endl;

    return 0;
}
