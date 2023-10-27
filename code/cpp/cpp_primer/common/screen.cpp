
#include <iostream>
#include <string>

#include "screen.h"

char Screen::Get(pos r, pos c) const
{
    pos row = r * width_;
    return contents_[row + c];
}

Screen& Screen::Move(pos r, pos c)
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

Screen &Screen::Set(pos ht, pos wd, char c)
{
    contents_[ht * width_ + wd] = c;
    return *this;
}

std::ostream& StoreOn(std::ostream &os, Screen &s)
{
    os << s.contents_ << std::endl;
    return os;
}

BitMap& StoreOn(BitMap &b, Screen &s)
{
    //b.os << s.contents_ << endl;
    return b;
}

Screen::pos Screen::Size() const
{
    return height_ * width_;
}

int height_ = 10;
void Screen::DummyFcn3(pos height_)
{
    cursur_ = width_ * ::height_ * height_;
    std::cout << cursur_ << std::endl;
}

Screen::pos Verify(Screen::pos p) {  return p; }
void Screen::SetHeight(pos val)
{
    // 屏蔽全局height_
    height_ = Verify(val);  //
}
