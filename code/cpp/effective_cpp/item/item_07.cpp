
#include "item_07.h"
#include <iostream>

using namespace std;
using namespace effective_item_07;

/* 为多态基类生命virtual析构函数 */
void Item07()
{
    cout << "**********item 07**********" << endl;
#if 0
    // TimeKeeper *tk = new TimeKeeper();
    // delete tk;

    TimeKeeper *tk2 = new AtomicClock();
    delete tk2;
#endif
#if 0
    // 不做基类令其析构函数为虚函数--->不佳
    cout << "Point size: " << sizeof (Point) << endl;
#endif
#if 1
//    SpecialString *pss = new SpecialString;
//    std::string     *ps;
//    ps = pss;

//    delete ps;

    AtomicClock *pac = new AtomicClock;
    TimeKeeper *tk = new TimeKeeper;

    tk = pac;
    delete tk;      // 无虚函数
#endif
    cout << "***************************" << endl;
}

namespace effective_item_07 {

AMOV::~AMOV()
{

}

}
