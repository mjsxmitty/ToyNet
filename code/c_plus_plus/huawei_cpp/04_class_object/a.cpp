
#include <iostream>
#include "a.h"

using namespace std;

A::A()
{
    cout << this << " construct func." << endl;
}

A::A(const A &other) {cout << this << " cp construct func from " << &other << endl; }

A& A::operator=(const A &other) {cout << this << " operator= construct func from " << &other << endl;}

A::~A(){ cout << this << " disconstruct func" << endl; }

void A::func()
{
    cout << " ha ha ha" << endl;
}
