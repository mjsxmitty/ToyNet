
#include "item_07.h"
#include <iostream>

using namespace std;

/* 为多态基类生命virtual析构函数 */
int main()
{
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
#if 0
    SpecialString *pss = new SpecialString;
    std::string     *ps;
    ps = pss;

    delete ps;
#endif
    return 0;
}


AMOV::~AMOV()
{

}
