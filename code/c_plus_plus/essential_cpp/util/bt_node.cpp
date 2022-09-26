
#include "bt_node.h"


template<typename ValType>
BTnode<ValType>::BTnode(const ValType &val) : val_(val)
{
    cnt_ = 1;
    lchild_ = rchild_ = 0;
}
