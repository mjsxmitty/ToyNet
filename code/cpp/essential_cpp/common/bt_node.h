
#ifndef __ESSENTIAL_CPP_BT_NODE_H__
#define __ESSENTIAL_CPP_BT_NODE_H__

#include <ostream>

namespace common
{

template <typename Type>
class BinaryTree;

template <typename ValType>
class BTnode
{
    friend class BinaryTree<ValType>;
public:
    BTnode(const ValType &);
    BTnode& operator=(const BTnode &);
public:
    const ValType& Value() const { return val_; }
    int Occurs() const { return cnt_; }
    bool FindValue(const ValType &val) const;
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
BTnode<ValType>::BTnode(const ValType &val) : val_(val) // 防止类
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
bool BTnode<ValType>::FindValue(const ValType &val) const
{
    if (val == val_) return true;

    if (val < val_)
    {
        if (!lchild_)
            return false;
        else
            lchild_->FindValue(val);
    }
    else
    {
        if (!rchild_)
            return false;
        else
            rchild_->FindValue(val);
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
    os << pt->val_;
    if ( pt->cnt_ > 1)
        os << "(" << pt->cnt_ << ")";
    os << ' ';
}

}

#endif //__ESSENTIAL_CPP_BT_NODE_H__
