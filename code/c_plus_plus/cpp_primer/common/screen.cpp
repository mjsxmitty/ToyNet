
#include <iostream>
#include <string>

#include "screen.h"

inline char Screen::Get(unsigned r, unsigned c) const
{
    unsigned row = r * width_;
    return contents_[row + c];
}

inline Screen& Screen::Move(unsigned r, unsigned c)
{
    cursur_ = r * width_ + c;
    return *this;
}

void Screen::SomeNumber() const
{
    ++access_ctr_;
}

Screen &Screen::Set(char c)
{
    contents_[cursur_] = c;
    return *this;
}

Screen &Screen::Set(unsigned ht, unsigned wd, char c)
{
    contents_[ht * width_ + wd] = c;
    return *this;
}

/*****************************************************************/
/***************************7.3.4*********************************/

std::ostream& StoreOn(std::ostream &os, Screen &s)
{
    os << s.contents_ << std::endl;
    return os;
}

//BitMap& StoreOn(BitMap &b, Screen &s)
//{
//    b.os << s.contents_ << endl;
//    return b;
//}

/*****************************************************************/
/****************************7.33*********************************/

unsigned Screen::Size() const
{
    return height_ * width_;
}

/*****************************************************************/
/****************************7.33*********************************/
int gz_height_ = 10;
void Screen::DummyFcn3(unsigned height_)
{
    cursur_ = width_ * ::gz_height_;
    std::cout << cursur_ << std::endl;
}

void GZPractice_7_4_1()
{
    Screen my_screen(1, 1, '*');
    my_screen.Display(std::cout);
    my_screen.DummyFcn(3);
    my_screen.DummyFcn2(3);
    my_screen.DummyFcn3(4);
}

// Verify瀹氫箟鍦ㄧ被涔嬪悗,鍗村湪鍑芥暟涔嬪墠
unsigned Verify(unsigned p) {  return 0; }
void Screen::SetHeight(unsigned val)
{
    height_ = Verify(val);
}
