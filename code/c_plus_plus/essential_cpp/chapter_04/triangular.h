

#ifndef __ESSENTIAL_CPP_CHAPTER_04_TRIANGULAR_H__
#define __ESSENTIAL_CPP_CHAPTER_04_TRIANGULAR_H__

#include <string>
#include <vector>
#include <iostream>

class Triangular
{
public:
    Triangular(int len = 1, int bp = 1);
    Triangular(const Triangular &rhs);
    Triangular& operator=(const Triangular &rhs);
public:
    int Length() const { return length_; }
    int BegPos() const { return beg_pos_; }
    int Elem(int pos) const { return elems_[pos - 1]; }

    void Length(int len) { length_ = len; }
    void BegPos(int pos) { beg_pos_ = pos; }

    void NextReset() const { next_ = beg_pos_ - 1; }
    bool Next(int &val) const;
public:
    static bool IsElem(int val);
    static void GenElements(int length);
    static void GenElemsToValue(int value);
    static void Display(int len, int bp, std::ostream &os = std::cout);
private:
    //static const int max_size = 1024;
    enum { max_size = 1024 };
    static std::vector<int>    elems_;
    int                 beg_pos_, length_;
    mutable int         next_;
};

int Sum(const Triangular &item);

#endif // TRIANGULAR_H
