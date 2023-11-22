
#include "item_16.h"
#include <iostream>

using namespace effective_item_16;

void Item16()
{
    std::cout << "**********item 16**********" << std::endl;
#if 1
    StringArring *psa = new StringArring[3];
    std::cout << "use StringArring point." << std::endl;
    delete [] psa;
#endif
#if 1

#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_16 {

StringArring::StringArring()
{
    std::cout << "StringArring::StringArring()" << std::endl;
}

StringArring::~StringArring()
{
std::cout << "StringArring::~StringArring()" << std::endl;
}

}


