
#include "ch_2.h"

using namespace std;
using namespace gz_cpp_ch_02;

void ch_2()
{
    {
        GZHello Hello;
        Hello.Hello();
        GZHello::SHello();  // 调用静态成员
        Hello.a = 0;        // 使用成员
        int k = Hello.a;
        Hello.b;
        //Hello.m = 10;
        //Hello.m1 = 10;

        GZMonster Monster;
        Monster.GetP();

        GZMonster::SHello();
        Monster.SHello();
        Monster.Hello();
    }

    {

    }
}
