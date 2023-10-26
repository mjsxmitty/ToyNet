
#include <memory>
#include "my_member_template.h"


class Base1{};
class Derived1 : public Base1{};

class Base2{};
class Derived2 : public Base2 {};


Pair<Derived1, Derived2> p;
Pair<Base1, Base2> p2(p);//反过来不可以
//shared_ptr

void func()
{
    Base1 *ptr = new Derived1;

    std::shared_ptr<Base1> sptr(Derived1);
}