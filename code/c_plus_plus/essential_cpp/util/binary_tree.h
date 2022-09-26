
#ifndef __ESSENTIAL_CPP_UTIL_BINARY_TREE_H__
#define __ESSENTIAL_CPP_UTIL_BINARY_TREE_H__

#include "bt_node.h"

template <typename ElemType>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const BinaryTree &);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree &);
public:
    bool Empty() const { return root_ == 0; }
    void Clear();
private:
    void Copy(BTnode<ElemType> *tar, BTnode<ElemType> *src);
private:
    BTnode<ElemType>    *root_;
};

#endif //__ESSENTIAL_CPP_UTIL_BINARY_TREE_H__
