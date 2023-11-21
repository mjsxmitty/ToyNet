
#include "item_13.h"
#include <iostream>
#include <memory>

using namespace effective_item_13;

/* 以对象管理资源 */
void Item13()
{
    std::cout << "**********item 13**********" << std::endl;
#if 1
    f();
#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_13 {

Investment* CreateInvestment(){}

void f()
{
    //Investment *pi = CreateInvestment();
    // ……
    //delete pi;
    std::auto_ptr<Investment> api(CreateInvestment());
    std::auto_ptr<Investment> api2(api);                // api 为NULL
    api2 = api;

    std::shared_ptr<Investment> spi(CreateInvestment());
    std::shared_ptr<Investment> spi2(spi);
    spi2 = spi;
}

}
