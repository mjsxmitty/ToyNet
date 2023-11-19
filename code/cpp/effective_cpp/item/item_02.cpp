
#include "item_02.h"
#include <vector>
#include <iostream>

using namespace std;

const Rational operator*(const Rational &lhs, const Rational &rhs)
{
    Rational r;
    return r;
}

void Print(const TextBook &ctb)
{
    cout << ctb[0] << endl;
}

void Item02()
{
    cout << "**********item 02**********" << endl;
#if 0
    std::vector<int> ivec(10, 1024);
    const std::vector<int>::iterator iter = ivec.begin();
    *iter = 0;
    //++iter;

    std::vector<int>::const_iterator citer = ivec.cbegin();
    //*citer = 10;
    ++citer;
#endif
#if 1
    Rational a, b, c;
    //(a * b) = c;
#endif
#if 0
    TextBook tb("Hello");
    cout << tb[0] << endl;
    tb[1] = 'a';

    const TextBook ctb("World");
    cout << ctb[0] << endl;
    //ctb[1] ='b';
#endif
#if 1
    CTextBook ctb("Hello World");
    char *pc = &ctb[1];
    *pc = 'j';
    cout << ctb.ptext_ << endl;
#endif
    cout << "***************************" << endl;
}
