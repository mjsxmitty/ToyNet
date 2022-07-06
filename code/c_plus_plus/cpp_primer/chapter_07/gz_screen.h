

#ifndef __GZ_SCREEN_H__
#define __GZ_SCREEN_H__

#include <string>
#include <iostream>

void GZPractice_7_3_1();
void GZPractice_7_3_2();

class BitMap;
class GZScreen
{
public:
//7.3.1类成员再探
    //定义类型成员
    //typedef std::string::size_type  pos;
    using pos = std::string::size_type;
private:
    pos             cursur_ = 0;
    pos             height_ = 0;
    pos             width_ = 0;
    std::string     contents_;
    //GZScreen();
public:
    //成员函数
    GZScreen() = default;
    GZScreen(pos ht, pos wd, char c = '*') :
        height_(ht), width_(wd), contents_(ht * wd, c) {}
    //令成员作为内联函数
    char        Get() const { return contents_[cursur_]; }
    inline char Get(pos ht, pos wd) const;
    GZScreen&   Move(pos ht, pos wd);
private:
    //可变数据成员
    mutable size_t  access_ctr_;
public:
    void SomeNumber() const;
//7.3.2 返回*this成员函数
    GZScreen& Set(char);
    GZScreen& Set(pos, pos, char);
    //基于const的重载
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

    // 7.3.4 友元再探
    //类之间的友元关系
    friend class GZWindowMgr;

    // 函数重载和友元
    friend std::ostream& StoreOn(std::ostream &, GZScreen &);
    //friend BitMap& StoreOn(BitMap &, GZScreen &);
};

class BitMap
{
public:
    std::ostream os;
};
extern std::ostream& StoreOn(std::ostream &, GZScreen &);
//extern BitMap& StoreOn(BitMap &, GZScreen &);

#endif // __GZ_SCREEN_H__
