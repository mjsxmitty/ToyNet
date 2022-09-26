
#ifndef __ESSENTIAL_CPP_UTIL_BT_NODE_H__
#define __ESSENTIAL_CPP_UTIL_BT_NODE_H__

template <typename Type>
class BinaryTree;

template <typename ValType>
class BTnode
{
public:
    BTnode(const ValType &);
private:
    ValType     val_;
    int         cnt_;
    BTnode      *lchild_;
    BTnode      *rchild_;
};

#endif //__ESSENTIAL_CPP_UTIL_BT_NODE_H__
