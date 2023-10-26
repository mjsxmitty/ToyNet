

#ifndef __CPP_PRIMER_SCREEN_H__
#define __CPP_PRIMER_SCREEN_H__

#include <string>
#include <iostream>

class BitMap;
class Screen
{
    friend class WindowMgr;
public:
    //typedef std::string::size_type  pos;
    using pos = std::string::size_type;
public:
    Screen() = default;
    Screen(pos ht, pos wd, char c = '*') :
        height_(ht), width_(wd), contents_(ht * wd, c) {}
public:
    char Get() const { return contents_[cursur_]; }
    char Get(pos ht, pos wd) const;
    Screen& Move(pos ht, pos wd);

    int GetAccessCtr() const { return access_ctr_; }
    void SomeNumber() const;

    Screen& Set(char);
    Screen& Set(pos, pos, char);

    Screen& Display(std::ostream &os)
    {
        DoDisplay(os);
        return *this;
    }
    const Screen& Display(std::ostream &os) const
    {
        DoDisplay(os);
        return *this;
    }
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }
private:
    pos             cursur_ = 0;
    pos             height_ = 0;
    pos             width_ = 0;
    std::string     contents_;
    mutable size_t  access_ctr_ = 0;

public:
    friend std::ostream& StoreOn(std::ostream &, Screen &);
    //friend BitMap& StoreOn(BitMap &, Screen &);
public:
    pos Size() const;
public:
    void DummyFcn(pos height_)
    {
        cursur_ = width_ * height_;
        std::cout << cursur_ << std::endl;
    }
    void DummyFcn2(pos height_)
    {
        //cursur_ = width_ * this->height_;
        cursur_ = width_ * Screen::height_;
    }
    void DummyFcn3(pos height_);

    void SetHeight(pos);

    // 7.6
    //Screen& Clear(char c = bkground_);
private:
    //static const char bkground_ = '*';
    //const char bk_groung_;
};

class BitMap
{
public:
    std::ostream os;
};
extern std::ostream& StoreOn(std::ostream &, Screen &);
extern BitMap& StoreOn(BitMap &, Screen &);

#endif // __CPP_PRIMER_SCREEN_H__
