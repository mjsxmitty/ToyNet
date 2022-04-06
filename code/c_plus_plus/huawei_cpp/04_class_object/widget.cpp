
#include "widget.h"

Widget::Widget()
{
    fptr[0] = &Widget::f;
    fptr[1] = &Widget::g;
    fptr[2] = &Widget::h;
    fptr[3] = &Widget::i;
}

void Widget::Select(int idx, int val)
{
    if (idx < 0 || idx > CNT) return;
    (this->*fptr[idx])(val);
}
