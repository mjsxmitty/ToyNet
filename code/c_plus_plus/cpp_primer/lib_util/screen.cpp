

#include "screen.h"

#include <string>
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

const Screen& Screen::Display(std::ostream &os) const
{
    DoDisplay(os);

    /* 7-3-2-1 从const成员返回*this */
    //返回 const Screen&类型
    return *this;
}

int height_ = 2;
Screen::pos Verify(Screen::pos)
{
    return 0;
}

void Screen::DummyFcn(pos height_)
{
    //函数体名字查找规则
    //cursor_ = weight_ * height_;
    //cursor_ = weight_ + this->height_;
    //cout << "use val: " << height_ << endl;
    cout << "use val: " << this->height_ << endl;
    cout << "use val: " << Screen::height_<< endl;
    cout << "use val: " << ::height_<< endl;
    height_ = Verify(height_);
}

Screen &Screen::Clear(char c)
{
    contents_ = std::string(weight_ * height_, c);
    return *this;
}

const char Screen::bak_ground_;
