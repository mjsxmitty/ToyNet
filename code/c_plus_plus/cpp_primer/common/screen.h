

#ifndef __CPP_PRIMER_SCREEN_H__
#define __CPP_PRIMER_SCREEN_H__

#include <string>
#include <iostream>

class BitMap;
class Screen
{
    friend class WindowMgr;
public:
    //typedef std::string::size_type  unsigned;
    //using unsigned = std::string::size_type;
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd, char c = '*') :
        height_(ht), width_(wd), contents_(ht * wd, c) {}
public:
    char        Get() const { return contents_[cursur_]; }
    char        Get(unsigned ht, unsigned wd) const;
    Screen&   Move(unsigned ht, unsigned wd);

    int     GetAccessCtr() const { return access_ctr_; }
    void    SomeNumber() const;

    Screen&   Set(char);
    Screen&   Set(unsigned, unsigned, char);

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
    unsigned             cursur_ = 0;
    unsigned             height_ = 0;
    unsigned             width_ = 0;
    std::string     contents_;
    mutable size_t  access_ctr_ = 0;

public:
    /* 7.3.4 友元再探 */
    //类之间的友元关系
    friend class GZWindowMgr;

    // 函数重载和友元
    friend std::ostream& StoreOn(std::ostream &, Screen &);
    //friend BitMap& StoreOn(BitMap &, Screen &);

    //homework 7.33
    unsigned Size() const;
public:
    // 7.4.1名字查找与作用域
    // 成员定义中的普通块作用域的名字查找
    void DummyFcn(unsigned height_)
    {
        cursur_ = width_ * height_;
        std::cout << cursur_ << std::endl;
    }
    void DummyFcn2(unsigned height_)
    {
        //cursur_ = width_ * this->height_;
        cursur_ = width_ * Screen::height_;
        std::cout << cursur_ << std::endl;
    }
    void DummyFcn3(unsigned height_);

    //当文件中名字的出现处对其进行解析
    void SetHeight(unsigned);

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
//extern BitMap& StoreOn(BitMap &, Screen &);

#endif // __CPP_PRIMER_SCREEN_H__
