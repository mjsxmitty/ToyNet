
#include "chapter_08.h"

namespace chapter_08
{
void Test1()
{
    int *p = new int;
    delete p;
}

void Test2()
{
    int *p1 = new int;
    int *p2 = (int *)malloc(sizeof(int)); // 分配一片内存

    delete p2;
    free(p1);

    Base *b = new Base();
    delete b;

    //b->Base();    // error
    //b->~Base();   // 可以调用
    //free(b);
}

void Test3()
{
    Base *base = new Children();
    delete base;
}

void Test4()
{
    Base *p = new Base[10];
    delete [] p;
    //delete p;
}

void Test5()
{
    Children **pp = new Children* [10];
    for (int i = 0; i != 10; ++i)
    {
        pp[i] = new Children[10];
    }

    cout << "distruct ... " << endl;
    for (int i = 0; i != 10; ++i)
    {
        delete [] pp[i];
    }
    delete [] pp;

    Children ***ppp = new Children**[10];
    for (int i = 0; i != 10; ++i)
    {
        ppp[i] = new Children*[10];

        for (int j = 0; j != 10; ++j)
        {
            ppp[i][j] = new Children[10];
        }
    }

    cout << "distruct ... " << endl;
    for (int i = 0; i != 10; ++i)
    {
        for (int j = 0; j != 10; ++j)
        {
            delete [] ppp[i][j];
        }

        delete [] ppp[i];
    }
    delete [] ppp;
}

void Test6()
{
    PreDistribution<Base> distribution(10);
    Base *ptr = distribution[1];
    ptr->Hello();
}

}
