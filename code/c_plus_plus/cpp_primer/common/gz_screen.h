

#ifndef __GZ_SCREEN_H__
#define __GZ_SCREEN_H__

#include <string>
#include <iostream>

class BitMap;
class GZScreen
{
public:
    /* 7.3.1类成员再探 */
    //typedef std::string::size_type  pos;
    using pos = std::string::size_type;
private:
    pos             cursur_ = 0;
    pos             height_ = 0;
    pos             width_ = 0;
    std::string     contents_;
public:
    //成员函数
    GZScreen() = default;
    GZScreen(pos ht, pos wd, char c = '*') :
        height_(ht), width_(wd), contents_(ht * wd, c) {}

    /* 令成员作为内联函数 */
    char        Get() const { return contents_[cursur_]; }
    inline char Get(pos ht, pos wd) const;
    GZScreen&   Move(pos ht, pos wd);
private:
    /* 可变数据成员 */
    mutable size_t  access_ctr_ = 0;
public:
    void SomeNumber() const;
    int GetAccessCtr() const { return access_ctr_; }
public:
    /* 7.3.2 返回*this成员函数 */
    GZScreen& Set(char);
    GZScreen& Set(pos, pos, char);

    /* 基于const的重载 */
    GZScreen& Display(std::ostream &os)
    {
        DoDisplay(os);
        return *this;
    }
    const GZScreen& Display(std::ostream &os) const
    {
        DoDisplay(os);
        return *this;
    }
private:
    void DoDisplay(std::ostream &os) const { os << contents_; }
public:
    /* 7.3.4 友元再探 */
    //类之间的友元关系
    friend class GZWindowMgr;

    // 函数重载和友元
    friend std::ostream& StoreOn(std::ostream &, GZScreen &);
    //friend BitMap& StoreOn(BitMap &, GZScreen &);

    //homework 7.33
    pos Size() const;
public:
    // 7.4.1名字查找与作用域
    // 成员定义中的普通块作用域的名字查找
    void DummyFcn(pos height_)
    {
        cursur_ = width_ * height_;
        std::cout << cursur_ << std::endl;
    }
    void DummyFcn2(pos height_)
    {
        //cursur_ = width_ * this->height_;
        cursur_ = width_ * GZScreen::height_;
        std::cout << cursur_ << std::endl;
    }
    void DummyFcn3(pos height_);

    //当文件中名字的出现处对其进行解析
    void SetHeight(pos);

    // 7.6
    //GZScreen& Clear(char c = bkground_);
private:
    //static const char bkground_ = '*';
    //const char bk_groung_;
};

class BitMap
{
public:
    std::ostream os;
};
extern std::ostream& StoreOn(std::ostream &, GZScreen &);
//extern BitMap& StoreOn(BitMap &, GZScreen &);

#endif // __GZ_SCREEN_H__
