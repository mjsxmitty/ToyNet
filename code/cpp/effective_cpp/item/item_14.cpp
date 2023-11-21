
#include "item_14.h"
#include <iostream>

using namespace effective_item_14;

/* 资源管理类中小心copying行为 */
void Item14()
{
    std::cout << "**********item 14**********" << std::endl;
#if 1
    std::mutex m;
    Lock l(&m);
#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_14 {

void lock(std::mutex *pm)
{
    std::cout << "locking ..." << std::endl;
}
void unlock(std::mutex *pm)
{
    std::cout << "unlocking ..." << std::endl;
}

}