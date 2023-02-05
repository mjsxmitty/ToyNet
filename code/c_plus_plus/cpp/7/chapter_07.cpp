
#include <stdio.h>
#include <iostream>
#include "chapter_07.h"

using namespace std;

namespace chapter_07
{
void SignalFunction(int sig)
{
    cout << "SignalFunction() signal: " << sig << endl;
}

void SignalFunction1(int sig)
{
    cout << "SignalFunction1() signal: " << sig << endl;
}

void SignalFunction2(int sig)
{
    cout << "SignalFunction2() signal: " << sig << endl;
}

}
