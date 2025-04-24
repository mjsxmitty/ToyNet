
#include "triangular.h"
#include "triangular_iterator.h"

TriangularIterator::TriangularIterator(int ix) : index_(ix - 1) {}

bool TriangularIterator::operator==(const TriangularIterator &rhs) const
{
    return index_ == rhs.index_;
}

bool TriangularIterator::operator!=(const TriangularIterator &rhs) const
{
    return !(*this == rhs);
}

int TriangularIterator::operator*() const
{
    CheckIntegrity();
    return Triangular::elems_[index_];
}

#if 1
void TriangularIterator::CheckIntegrity() const
{
    if (index_ > Triangular::max_size_)
        throw IteratorOverflow();

    if (index_ > Triangular::elems_.size())
        Triangular::GenElements(index_ + 1);
}
#endif

#if 0
// 避免友元
void TriangularIterator::CheckIntegrity () const
{
    if (index_ > Triangular::max_size())
        throw IteratorOverflow();

    if (index_ > Triangular::elem_size())
        Triangular::GenElements(index_ + 1);
}
#endif

TriangularIterator& TriangularIterator::operator++()
{
    ++index_;
    CheckIntegrity();
    return *this;
}

TriangularIterator TriangularIterator::operator++(int)
{
    TriangularIterator ret = *this;
    ++index_;
    CheckIntegrity();
    return ret;
}


