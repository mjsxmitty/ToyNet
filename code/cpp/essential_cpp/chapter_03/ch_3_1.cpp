
#include <list>
#include <iostream>
#include "common.h"

using namespace chapter_03;

int main1()
{
    const int       *iptr = nullptr;
    const std::string    *sptr = nullptr;
#if 0
    iptr = FindVec(s_ivec, s_ivec[5]);
    if (iptr == &s_ivec[5])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test no template func failed, ret: "
             << *iptr << std::endl;

    iptr = FindVer1(s_ivec, s_ivec[6]);
    if (iptr == &s_ivec[6])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test FindVer1 with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = FindVer1(s_svec, s_svec[0]);
    if (sptr == &s_svec[0])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test FindVer1 with char array type func failed, ret: "
             << *sptr << std::endl;

    iptr = FindVer2(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test FindVer2 with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = FindVer2(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test FindVer2 with char array type func failed, ret: "
             << *sptr << std::endl;

    iptr = FindVer3(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test FindVer3 with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = FindVer3(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test FindVer3 with char array type func failed, ret: "
             << *sptr << std::endl;
#endif
    iptr = FindVer4(s_ia, s_ia + s_int_size, s_ia[8]);
    if (iptr == &s_ia[8])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test FindVer4 with int array type func failed, ret: "
             << *iptr << std::endl;

    sptr = FindVer4(s_sa, s_sa + s_string_size, s_sa[3]);
    if (sptr == &s_sa[3])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test FindVer4 with char array type func failed, ret: "
             << *sptr << std::endl;

    iptr = FindVer4(Begin(s_ivec), End(s_ivec), s_ivec[9]);
    if (iptr == &s_ivec[9])
        std::cout << *iptr << std::endl;
    else
        std::cout << "test FindVer4 with int vector type func failed, ret: "
             << *iptr << std::endl;

    sptr = FindVer4(Begin(s_svec), End(s_svec), s_svec[3]);
    if (sptr == &s_svec[3])
        std::cout << *sptr << std::endl;
    else
        std::cout << "test FindVer4 with char vector type func failed, ret: "
             << *sptr << std::endl;

    return 0;
}

