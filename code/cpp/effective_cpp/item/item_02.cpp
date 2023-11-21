
#include <iostream>
#include "item_02.h"

using namespace std;
using namespace effective_item_02;

/* 尽可能以const, enum, inline替换#define */
void Item02()
{
    cout << "**********item 03**********" << endl;
#if 0
    cout << ASPECT_RATIO << endl;
#endif
#if 0
    cout << aspect_ratio << endl;
#endif
#if 0
    int a = 5, b = 0;
    CALL_WITH_MAX(++a,b);       // a ++执行2次
    CALL_WITH_MAX(++a,b+10);    // a ++执行1次
#endif
#if 1
    int a = 5, b = 0;
    CallWithMax(++a, b);
    CallWithMax(++a, b + 10);
#endif
    cout << "***************************" << endl;
}

namespace effective_item_02 {

//const int GamePlayer::num_turns_;

const double CostEstimate::fudge_factor_ = 1.24;

void f(int i)
{
    cout << "val: " << i << endl;
}

}
