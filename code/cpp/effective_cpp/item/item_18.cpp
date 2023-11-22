
#include "item_18.h"

/* 宁以pass-by-reference-to-const替换pass-by-value */
/* 让接口容易被正确使用，不容易被误用 */
void Item18()
{

}

namespace effective_item_18 {

std::shared_ptr<Investment> CreateInvestment()
{
    std::shared_ptr<Investment> ret_val(static_cast<Investment*>(0), GetRaidOfInvestment);
    //ret_val=0;
    // 最好能初始化指针,避免一次赋值
    return ret_val;
}

void GetRaidOfInvestment(Investment *pi)
{

}

}
