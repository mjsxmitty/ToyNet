
#ifndef __ESSENTIAL_CPP_UTIL_BT_NODE_H__
#define __ESSENTIAL_CPP_UTIL_BT_NODE_H__

template <typename ValType>
class BTnode
{
public:

private:
    ValType     val_;
    int         cnt_;
    BTnode      *lchild_;
    BTnode      *rchild_;
};

#endif //__ESSENTIAL_CPP_UTIL_BT_NODE_H__
