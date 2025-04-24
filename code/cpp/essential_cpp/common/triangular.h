
#ifndef __ESSENTIAL_CPP_TRIANGULAR_H__
#define __ESSENTIAL_CPP_TRIANGULAR_H__

#include <string>
#include <vector>
#include <iostream>

#include "triangular_iterator.h"

class TriangularIterator;
class Triangular
{
    friend class TriangularIterator;
    // friend int TriangularIterator::operator*() const;
    // friend void TriangularIterator::CheckIntegrity() const;
public:
    Triangular(int len = 1, int bp = 1);
    Triangular(const Triangular &rhs);
    Triangular& operator=(const Triangular &rhs);
public:
    Triangular& Copy(const Triangular &rhs);
public:
    int Length() const { return length_; }
    int BegPos() const { return beg_pos_; }
    int Elem(int pos) const { return elems_[pos - 1]; }

    void NextReset() const { next_ = beg_pos_ - 1; }
    bool Next(int &val) const;
public:
    static bool IsElem(int val);
    static void GenElements(int length);
    static void GenElemsToValue(int val);
    static void Display(int len, int bp, std::ostream &os = std::cout);
public:
    friend std::ostream &operator<<(std::ostream &os, const Triangular &rhs);

    static int max_size() { return max_size_; }
    static int elem_size() { return elems_.size(); }
private:
    int             beg_pos_;
    int             length_;
    mutable int     next_;

    static std::vector<int>     elems_;
    //static int                  init_size_;

    //enum { max_size_ = 1024 };
    static const int max_size_ = 1024;
    //int buf[max_size_];
public:
    typedef TriangularIterator Iterator;

    Iterator Begin() const;
    Iterator End() const;
public:
    void Length(int len) { length_ = len; }
    void BegPos(int pos) { beg_pos_ = pos; }
};

extern int Sum(const Triangular &item);
extern std::istream& operator>>(std::istream& in, Triangular& rhs);
extern std::ostream& operator<<(std::ostream& os, const Triangular& rhs);

#endif // __ESSENTIAL_CPP_TRIANGULAR_H__
