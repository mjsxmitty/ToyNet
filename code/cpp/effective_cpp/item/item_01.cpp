
#include <iostream>
#include "item_01.h"

using namespace std;

//const int GamePlayer::num_turns_;

const double CostEstimate::fudge_factor_ = 1.24;

void f(int i)
{
    cout << "val: " << i << endl;
}

void Item01()
{
    cout << "**********item 01**********" << endl;
#if 0
    cout << ASPECT_RATIO << endl;
#endif
#if 0
    cout << aspect_ratio << endl;
#endif
#if 1
    int a = 5, b = 0;
    CALL_WITH_MAX(++a,b);
    CALL_WITH_MAX(++a,b+10);
#endif
    cout << "***************************" << endl;
}
