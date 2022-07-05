

#ifndef __GZ_SCREEN_H__
#define __GZ_SCREEN_H__

#include <string>

void GZPractice_7_3_1();
void GZPractice_7_3_2();

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
    GZScreen(pos ht, pos wd, char c) :
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
    GZScreen& Display(std::ostream &os);

};

#endif // __GZ_SCREEN_H__
