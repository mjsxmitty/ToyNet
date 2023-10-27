

#include "my_point_like.h"

struct Foo
{
    void Method(void) { ;}
};

void TestPointClass()
{
    SharePtr<Foo> sp(new Foo);
    Foo f(*sp);
    sp->Method();
    f.Method();
}