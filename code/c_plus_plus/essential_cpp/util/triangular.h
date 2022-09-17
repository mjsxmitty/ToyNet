

#ifndef __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__
#define __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__

#include <string>
#include <vector>
#include <iostream>
#include "triangular_iterator.h"

class Triangular
{
    /* 4.2 什么是构造函数和析构函数 */
private:
    int             beg_pos_;
    int             length_;
    mutable int     next_;
public:
    Triangular(int len = 1, int bp = 1);
    // Triangular(int len);
    Triangular(const Triangular &rhs);

public:
    /* 4.3 何谓可变和不变 */
    int Length() const { return length_; }
    int BegPos() const { return beg_pos_; }
    int Elem(int pos) const { return elems_[pos - 1]; }

    void NextReset() const { next_ = beg_pos_ - 1; }
    bool Next(int &val) const;
public:
    /* 4.4 什么是this 指针 */
    Triangular& Copy(const Triangular &rhs);
    Triangular& operator=(const Triangular &rhs);
private:
    /* 4.5 静态成员 */
    static std::vector<int>     elems_;
    static int                  init_size_;

    //enum { max_size_ = 1024 };
    static const int max_size_ = 1024;
    int buf[max_size_];
public:
    static bool IsElem(int val);
    static void GenElements(int length);
    static void GenElemsToValue(int value);
    static void Display(int len, int bp, std::ostream &os = std::cout);
public:
    /* 4.6 打造一个指针类 */
    typedef TriangularIterator Iterator;

    Iterator Begin() const;
    Iterator End() const;
public:
    /* 4.7 友元 */
    friend std::ostream &operator<<(std::ostream &os, const Triangular &rhs);
    friend class TriangularIterator;
public:
    void Length(int len) { length_ = len; }
    void BegPos(int pos) { beg_pos_ = pos; }


    /* 鍙互閬垮厤鍙嬪厓 */
    static int max_size() { return max_size_; }
    static int elem_size() { return elems_.size(); }


};

/* 4.3 */
extern int Sum(const Triangular &item);

std::istream& operator>>(std::istream& in, Triangular& rhs);
std::ostream& operator<<(std::ostream& os, const Triangular& rhs);


#endif // __ESSENTIAL_CPP_UTIL_TRIANGULAR_H__
