
#include <iostream>
#include "gz_screen.h"

using namespace std;

/***************************7.3.1*********************************/

char GZScreen::Get(pos ht, pos wd) const
{
    pos row = ht * width_ + wd;
    return contents_[row];
}

inline GZScreen& GZScreen::Move(pos ht, pos wd)
{
    cursur_ = ht * width_ + wd;
    return *this;
}

void GZPractice_7_3_1()
{
    //重载成员函数
    GZScreen my_screen;
    char ch = my_screen.Get();
    ch = my_screen.Get(1, 2);
}

void GZScreen::SomeNumber() const
{
    ++access_ctr_;
}

/*****************************************************************/
/***************************7.3.2*********************************/

GZScreen &GZScreen::Set(char c)
{
    contents_[cursur_] = c;
    return *this;
}

GZScreen &GZScreen::Set(pos ht, pos wd, char c)
{
    contents_[ht * width_ + wd] = c;
    return *this;
}

void GZPractice_7_3_2()
{
    GZScreen my_screen(10, 20, '#');
    cout << my_screen.Get() << endl;
    my_screen.Move(1, 2).Set('*');
    cout << my_screen.Get() << endl;

   GZScreen my_screen2(3, 5);
   const GZScreen my_screen3(1, 2);
   my_screen2.Set('#').Display(cout);
   cout << endl;
   my_screen3.Display(cout);
}

/*****************************************************************/
/***************************7.3.4*********************************/

ostream& StoreOn(ostream &os, GZScreen &s)
{
    os << s.contents_ << endl;
}

//BitMap& StoreOn(BitMap &b, GZScreen &s)
//{
//    b.os << s.contents_ << endl;
//    return b;
//}

/*****************************************************************/
/****************************7.33*********************************/

GZScreen::pos GZScreen::Size() const
{
    return height_ * width_;
}

/*****************************************************************/
/****************************7.33*********************************/
int gz_height_ = 10;
void GZScreen::DummyFcn3(GZScreen::pos height_)
{
    cursur_ = width_ * ::gz_height_;
    std::cout << cursur_ << std::endl;
}

void GZPractice_7_4_1()
{
    GZScreen my_screen(1, 1, '*');
    my_screen.Display(cout);
    my_screen.DummyFcn(3);
    my_screen.DummyFcn2(3);
    my_screen.DummyFcn3(4);
}

// Verify定义在类之后,却在函数之前
GZScreen::pos Verify(GZScreen::pos p);
void GZScreen::SetHeight(GZScreen::pos val)
{
    height_ = Verify(val);
}
