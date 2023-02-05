

#ifndef __CH_CHAPTER_09_H__
#define __CH_CHAPTER_09_H__

#include <algorithm>
#include <iostream>

using namespace std;

namespace chapter_09
{

template<typename T>
void Print(T beg, T end)
{
    while (beg != end)
    {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

void TestVector();
void TestString();
void TestMap();

template<typename T>
class Node
{
public:
    Node() : next_(nullptr), previous_(nullptr) {}
    ~Node() {}

    Node    *next_;
    Node    *previous_;
    T       data_;
};

void TestList();

struct Hello
{
    Hello() {elem_ = 0;}
    Hello(int num) : elem_(num){ }

    bool operator==(const Hello &h)
    {
        return  elem_ == h.elem_;
    }

    friend bool operator<(const Hello &lhs, const Hello &rhs)
    {
        return lhs.elem_ < rhs.elem_;
    }

    bool operator!=(const Hello &rhs)
    {
        return elem_ != rhs.elem_;
    }

    int GetElem() const { return elem_; }

    int elem_;
};

void test_list();
void TestQueue();
void TestStack();
void TestSet();
void TestForwardList();
void TestPriorityQueue();
void TestHash();
void TestArray();

template<typename ConatinerType, typename ElementType>
class ConatinerInerator
{
    typedef ConatinerInerator<ConatinerType, ElementType> Iterator;
public:
    ConatinerInerator(ConatinerType &cona, int index = 0)
        : conatiner_(cona), index_(index){}
    ConatinerInerator(const Iterator &iter)
        : conatiner_(iter.conatiner_), index_(iter.index_) {}
    bool operator!=(const Iterator &iter)
    {
        return conatiner_[index_] != iter.conatiner_[index_];
    }

    Iterator& operator++(int)
    {
        ++index_;
        return *this;
    }

    Iterator& operator--(int)
    {
        --index_;
        return *this;
    }

    Iterator& operator=(const Iterator &iter)
    {
        index_ = iter.index_;
        conatiner_ = iter.conatiner_;
        return *this;
    }

    ElementType& operator*()
    {
        return conatiner_[index_]; //
    }
private:
    ConatinerType   &conatiner_;
    int             index_;
};
}

#endif //__CH_CHAPTER_09_H__
