


#ifndef __CPP_PRIMER_SCREEN_H__
#define __CPP_PRIMER_SCREEN_H__

#include <string>
#include <iostream>

/* 7-3-4 重载函数作为友元 */
//每个函数都要声明友元函数
class Screen;
class BitMap;
extern std::ostream& store_on(std::ostream &, Screen &);
extern std::ostream& store_on(std::ostream &, BitMap &);    //访问Screen会出错--->未声明友元

class Screen
{
public:
    /* 友元 */
    //友元不存在传递性
    friend class WindowMgr;

    //TODO:分离式编译如何处理？？？
    //friend void WindowMgr::Clear(ScreenIndex i);

    friend std::ostream& store_on(std::ostream &, Screen &);

    /* 7-3-1-1 类型别名*/
    //存在访问控制
    //隐藏细节
    //using pos = std::string::size_type;
    typedef std::string::size_type pos;
public:
    /* 7-3-1-2 如果成员没有默认初始值,需要显示初始化成员 */
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height_(ht), weight_(wd), contents_(ht * wd, c) {}
    //Screen(pos ht, pos wd, char c) : height_(ht), weight_(wd), contents_(ht * wd, c) {}
public:
    /* 7-3-1-3 定义在类内部的函数自动成为内联函数(可以不使用inline) */
    inline Screen& Move(pos r, pos c)
    {
        cursor_ = r * weight_ + c;
        return *this;
    }

    //可以在类内/外(同时声明) ---> 最好类外
    char Get(pos r, pos c) const;

    /* 7-3-1-4 函数重载*/
    char Get() const { return contents_[cursor_]; }

    /* 7-3-1-5 可变数据成员 */
    void SomeMember() const;
public:
    /* 7-3-2-1 返回*this成员函数 */
    Screen& Set(char c);
    Screen& Set(pos r, pos c, char a = '*');

    /* 7-3-2-2 基于const重载 */
    Screen& Display(std::ostream &os);
    const Screen& Display(std::ostream &os) const;

    //名字查找与类的作用域
    void DummyFcn(pos height);
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }

public:
    /* 7-6 静态成员可以作为默认参数 */
    Screen& Clear(char = bak_ground_);
private:
    pos             cursor_ = 0;
    pos             height_ = 1, weight_ = 0;
    std::string     contents_;

    static const char bak_ground_ = ' ';

    mutable size_t  func_call_num_;
};

inline char Screen::Get(pos r, pos c) const
{
    return contents_[r * weight_ + c];
}

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

#endif // __CPP_PRIMER_SCREEN_H__
