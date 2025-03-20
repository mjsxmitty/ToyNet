
#include <iostream>
#include "common.h"

int main()
{
    std::cout << "max int value: " << common::Max(34, 199)
        << ", max std::string value: " << common::Max("nihao", "hello")
        << std::endl;

    int ia[8] = { 8, 34, 39, 13, 1, 21, 5, 2 };
    std::vector<int> vec(ia, ia + 8);
    std::cout << "max vec value: " << common::Max(vec) << std::endl;
    std::cout << "max array value: " << common::Max(ia, 8) << std::endl;

    std::string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    std::vector<std::string> svec( sarray, sarray+6 );
    std::cout << "max svec value: " << common::Max(svec) << std::endl;
    std::cout << "max sarray value: " << common::Max(sarray, sizeof(sarray) / sizeof (sarray[0])) << std::endl;

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    std::vector<float> fvec( farray, farray+5 );
    std::cout << "max fvec value: " << common::Max(fvec) << std::endl;
    std::cout << "max farray value: " << common::Max(farray, sizeof(farray) / sizeof (farray[0])) << std::endl;
}
