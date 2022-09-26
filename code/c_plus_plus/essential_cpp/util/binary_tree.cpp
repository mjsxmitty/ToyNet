
#include "binary_tree.h"

template<typename ElemType>
BinaryTree<ElemType>::BinaryTree() : root_(0)
{

}

template<typename ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree &rhs)
{
    Copy(root_, rhs.root_);
}

template<typename ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Clear();
}

template<typename ElemType>
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree &rhs)
{
    if (this != &rhs)
    {
        Clear();
        Copy(root_, rhs.root_);
    }

    return *this;
}
