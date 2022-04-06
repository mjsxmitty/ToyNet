


#ifndef __CPP_PRIMER_CHAPTER_07_SCREEN_H__
#define __CPP_PRIMER_CHAPTER_07_SCREEN_H__

#include <string>
#include <iostream>

class Screen
{
public:
    //友元类
    friend class WindowMgr;

    //类型成员
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;
public:
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height_(ht), weight_(wd), contents_(ht * wd, c) {}
    //Screen(pos ht, pos wd, char c) : height_(ht), weight_(wd), contents_(ht * wd, c) {}
public:
    //函数重载
    char Get() const {return contents_[cursor_];}   //隐式内敛
    char Get(pos r, pos c) const;
    void SomeMember() const;

    //返回*this
    Screen& Move(pos r, pos c);
    Screen& Set(char c);
    Screen& Set(pos r, pos c, char a = '*');
    //基于const重载
    Screen& Display(std::ostream &os);
    const Screen& Display(std::ostream &os) const;

    //名字查找与类的作用域
    void DummyFcn(pos height);
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }
private:
    pos             cursor_ = 0;
    pos             height_ = 1, weight_ = 0;
    std::string     contents_;

    mutable size_t  func_call_num_;
};

//inline关键字类内外都可以声明,最好在类外声明
inline char Screen::Get(pos r, pos c) const
{
    return contents_[r * weight_ + c];
}

//改变成员之后返回整体
inline Screen& Screen::Move(pos r, pos c)
{
    cursor_ = r * weight_ + c;
    return *this;
}

//mutable关键字
inline void Screen::SomeMember() const
{
    ++func_call_num_;
}

inline Screen& Screen::Set(char c)
{
    contents_[cursor_] = c;
    return *this;
}

inline Screen& Screen::Set(pos r, pos c, char a)
{
    contents_[r * weight_ + c] = a;
    return *this;
}

void TestScreen();
//Screen::pos Verify(Screen::pos);
#endif // __CPP_PRIMER_CHAPTER_07_SCREEN_H__
