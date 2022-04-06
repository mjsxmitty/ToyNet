

#include "screen.h"

#include <iostream>

using std::cout;
using std::endl;

void TestScreen()
{
    Screen my_screen(3,3,'*');
    my_screen.Move(1, 1).Set('#');
    my_screen.Display(cout);
    cout << "my screen func get ret: " << my_screen.Get()
         << ", func get2 ret: " << my_screen.Get(0, 1) << endl;

    cout << endl;
    const Screen my_const_screen(2,3,'#');
    my_const_screen.Display(cout);

    cout << endl;

    Screen test_screen;
    test_screen.Move(1,2);
    Screen::pos position = 100;
    test_screen.DummyFcn(position);

}

Screen& Screen::Display(std::ostream &os)
{
    DoDisplay(os);
    return *this;
}

//const函数绑定的对象是const的，返回的是const Screen&
const Screen& Screen::Display(std::ostream &os) const
{
    DoDisplay(os);
    return *this;
}

int height_ = 2;
Screen::pos Verify(Screen::pos)
{
    return 0;
}

void Screen::DummyFcn(pos height_)
{
    //cursor_ = weight_ * height_;
    cursor_ = weight_ + this->height_;
    cout << "use val: " << height_ << endl;
    cout << "use val: " << this->height_ << endl;
    cout << "use val: " << Screen::height_<< endl;
    cout << "use val: " << ::height_<< endl;
    cursor_ = Verify(height_);
}
