
#include "chapter_02.h"

int hello()
{
    return 1 + 3;
}

namespace chapter_02
{

int Monster::b = 1024;

void Hello::SHello(){}

Monster::Monster()
{
    int cc = ::hello();    // 使用全局成员
    cout << cc << endl;
}

Monster::~Monster(){}

bool IsSimulate(Physics *p)
{
    if (p)
    {
        p->Simulate();
    }

    return true;
}

}

namespace ch_02
{
    Hello* GetHello()
    {
        return NULL;
    }
}

namespace Operator
{
    Stream GZstream;
    Stream GZendl;
}
