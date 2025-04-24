
#ifndef __ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H__
#define __ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H__

// #include "triangular.h"
class TriangularIterator
{
public:
    TriangularIterator(int ix);

    bool operator==(const TriangularIterator &rhs) const;
    bool operator!=(const TriangularIterator &rhs) const;
    int operator*() const;

    TriangularIterator& operator++();
    TriangularIterator  operator++(int);

private:
    void    CheckIntegrity() const;
    unsigned int     index_;    //索引值
};

class IteratorOverflow {};

#endif // __ESSENTIAL_CPP_TRIANGULAR_ITERATOR_H__
