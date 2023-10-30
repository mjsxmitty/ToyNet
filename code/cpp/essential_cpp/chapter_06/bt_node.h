
#ifndef __ESSENTIAL_CPP_BT_NODE_H__
#define __ESSENTIAL_CPP_BT_NODE_H__

#include <ostream>

namespace chapter_06
{

template <typename Type>
class BinaryTree;

template <typename ValType>
class BTnode
{
    friend class BinaryTree<ValType>;
public:
    BTnode(const ValType &);
private:
    void InsertValue(const ValType &val);
    void RemoveValue(const ValType &val, BTnode *&prev);
    static void LchildLeaf(BTnode *leaf, BTnode *sub_tree);

    void Preorder(BTnode *pt, std::ostream &);
    void Inorder(BTnode *pt, std::ostream &);
    void Postorder(BTnode *pt, std::ostream &);

    void DisplayVal(BTnode *pt, std::ostream &os);
private:
    ValType     val_;
    int         cnt_;   // 重复次数
    BTnode      *lchild_;
    BTnode      *rchild_;
};

template<typename ValType>
BTnode<ValType>::BTnode(const ValType &val) : val_(val) //
{
    cnt_ = 1;
    lchild_ = rchild_ = 0;
}

template<typename ValType>
void BTnode<ValType>::InsertValue(const ValType &val)
{
    if (val_ == val)
    {
        cnt_++;
        return ;
    }

    // 左子树插入元素
    if (val < val_)
    {
        if (!lchild_)
            lchild_ = new BTnode<ValType>(val);
        else
            lchild_->InsertValue(val);
    }

    // 右子树插入元素
    if (val > val_)
    {
        if (!rchild_)
            rchild_ = new BTnode<ValType>(val);
        else
            rchild_->InsertValue(val);
    }
}

template<typename ValType>
void BTnode<ValType>::RemoveValue(const ValType &val, BTnode *&prev)
{
    if (val < val_)
    {
        if (prev->lchild_)
            return ;
        else
            RemoveValue(val, prev->lchild_);
    }
    else if (val > val_)
    {
        if (prev->rchild_)
            return ;
        else
            RemoveValue(val, prev->rchild_);
    }
    else
    {
        if (rchild_)
        {
            prev = rchild_;
            if (lchild_)
                if (!prev->lchild_)
                    prev->lchild_ = lchild_;
                else
                    LchildLeaf(lchild_, prev->lchild_);
        }
        else
            prev = lchild_;
    }
}

template<typename ValType>
void BTnode<ValType>::LchildLeaf(BTnode *leaf, BTnode *sub_tree)
{
    while (sub_tree->lchild_)
        sub_tree = sub_tree->lchild_;

    sub_tree->lchild_ = leaf;
}

template<typename ValType>
void BTnode<ValType>::Preorder(BTnode *pt, std::ostream &os)
{
    if (pt)
    {
        DisplayVal(pt, os);
        if (pt->lchild_) Preorder(pt->lchild_, os);
        if (pt->rchild_) Preorder(pt->rchild_, os);
    }
}

template<typename ValType>
void BTnode<ValType>::Inorder(BTnode *pt, std::ostream &os)
{
    if (pt)
    {
        if (pt->lchild_) Preorder(pt->lchild_, os);
        DisplayVal(pt, os);
        if (pt->rchild_) Preorder(pt->rchild_, os);
    }
}

template<typename ValType>
void BTnode<ValType>::Postorder(BTnode *pt, std::ostream &os)
{
    if (pt)
    {
        if (pt->lchild_) Preorder(pt->lchild_, os);
        if (pt->rchild_) Preorder(pt->rchild_, os);
        DisplayVal(pt, os);
    }
}

template<typename ValType>
void BTnode<ValType>::DisplayVal(BTnode *pt, std::ostream &os)
{
    os << pt->val_ << ' ';
}

}

#endif //__ESSENTIAL_CPP_BT_NODE_H__
