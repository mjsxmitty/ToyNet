#include "chapter_04.h"


void Chapter_04()
{
    Practice_4_3();
}

void Example(const ValClass *pvc, ValClass &rvc)
{
    //pvc->Val();
    rvc.Val();
}

void Practice_4_3()
{
    const ValClass  v1;
    ValClass        v2;
    Example(&v1, v2);
}
