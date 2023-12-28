
/* 尽可能以const, enum, inline替换#define */

#include <iostream>
#include "item_02.h"

using namespace std;

//const int GamePlayer::num_turns_;
const double CostEstimate::fudge_factor_ = 1.24;

void f(int i)
{
    cout << "val: " << i << endl;
}

int main()
{
#if 1
    cout << ASPECT_RATIO << endl;
#endif
#if 1
    cout << aspect_ratio << endl;
#endif
#if 1
    int a = 5, b = 0;
    CALL_WITH_MAX(++a,b);       // a ++执行2次
    CALL_WITH_MAX(++a,b+10);    // a ++执行1次
#endif
#if 0
    int a = 5, b = 0;
    CallWithMax(++a, b);
    CallWithMax(++a, b + 10);
#endif
    return 0;
}
