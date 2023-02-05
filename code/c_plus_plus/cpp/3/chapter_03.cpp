
#include "chapter_03.h"

#include <iostream>

using namespace std;

namespace chapter_03
{

HelloTest::HelloTest() {}

chapter_03::TestConst chapter_03::TestConst::NULLConst;

void HelloTest::Init()
{
    auto Hello = [&]() -> bool
    {
        a = 0;
        b = 10;
        aa = 10.f;

        return true;
    };

    bool init = Hello();
    if (init)
    {
        printf("init succeed, a = %d, "
               "b = %d, aa = %f\n", a, b, aa);
    }
}

}
