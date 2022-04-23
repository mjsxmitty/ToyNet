
#include <vector>
#include <iostream>
#include "num_seq1.h"
#include <algorithm>

using namespace std;

const int NumSeqVer1::seq_cnt_;
vector<vector<int>> NumSeqVer1::seq_(seq_cnt_);
const int NumSeqVer1::max_seq_ = 64;

typedef NumSeqVer1::PtrType PtrType;
PtrType NumSeqVer1::func_tbl_[seq_cnt_] = {
    0,
    &NumSeqVer1::FiboSeq,
    &NumSeqVer1::LucaSeq,
    &NumSeqVer1::PellSeq,
    &NumSeqVer1::PentSeq,
    &NumSeqVer1::SquaSeq,
    &NumSeqVer1::TriaSeq
};

NumSeqVer1::NumSeqVer1(int beg, int len, NumSeqVer1::NUM_SEQ nst)
{
    SetBegPos(beg);
    SetLength(len);
    SetSequence(nst);
}

void NumSeqVer1::FiboSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->empty() )
       {  elem_->push_back( 1 ); elem_->push_back( 1 ); }

    if ( elem_->size() <= pos )
    {
            int ix = elem_->size();
            int n_2 = (*elem_)[ ix-2 ],
                n_1 = (*elem_)[ ix-1 ];

            int val;
            for ( ; ix <= pos; ++ix ){
                    val = n_2 + n_1;
                    elem_->push_back( val );
                    n_2 = n_1; n_1 = val;
            }
     }
}

void NumSeqVer1::PellSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->empty() )
       {  elem_->push_back( 1 ); elem_->push_back( 2 ); }

    if ( elem_->size() <= pos )
    {
            int ix = elem_->size();
            int n_2 = (*elem_)[ ix-2 ],
                n_1 = (*elem_)[ ix-1 ];

            int val;
            for ( ; ix <= pos; ++ix ){
                    val = n_2 + 2 * n_1;
                    elem_->push_back( val );
                    n_2 = n_1; n_1 = val;
            }
     }
}

void NumSeqVer1::LucaSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->empty() )
       {  elem_->push_back( 1 ); elem_->push_back( 3 ); }

    if ( elem_->size() <= pos )
    {
            int ix = elem_->size();
            int n_2 = (*elem_)[ ix-2 ],
                n_1 = (*elem_)[ ix-1 ];

            int elem;
            for ( ; ix <= pos; ++ix ){
                    elem = n_2 +  n_1;
                    elem_->push_back( elem );
                    n_2 = n_1; n_1 = elem;
            }
     }
}

void NumSeqVer1::TriaSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->size() <= pos )
    {
        int end_pos = pos+1;
        int ix = elem_->size()+1;
        cout << "tri: ix: " << ix << " pos: " << pos << endl;
        for ( ; ix <= end_pos; ++ix )
              elem_->push_back( ix*(ix+1)/2 );
    }
}

void NumSeqVer1::SquaSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->size() <= pos )
    {
        int end_pos = pos + 1;
        int ix = elem_->size()+1;
        for ( ; ix <= end_pos; ++ix )
              elem_->push_back( ix*ix );
    }
}

void NumSeqVer1::PentSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
         return;

    if ( elem_->size() <= pos )
    {
        int end_pos = pos + 1;
        int ix = elem_->size()+1;
        for ( ; ix <= end_pos; ++ix )
              elem_->push_back( ix*(3*ix-1)/2 );
    }
}

void NumSeqVer1::SetBegPos(int pos)
{
    if (pos <= 0 || pos > max_seq_)
    {
        cerr << "invalid begin position: " << pos
             << " setting default position value of 1\n";
        pos = 1;
    }

    beg_pos_ = pos;
}

void NumSeqVer1::SetLength(int pos)
{
    if (pos <= 0 || pos + beg_pos_ - 1 > max_seq_)
    {
        cerr << "invalid length: " << pos
             << " setting default length value of 1\n";
        pos = 1;
    }

    length_ = pos;
}

void NumSeqVer1::SetSequence(NUM_SEQ nst)
{
    switch (nst)
    {
        default:
            cerr << "invalid type: setting to 0\n";
        case NS_UNK:
            pmf_ = 0;
            elem_ = 0;
            isa_ = NS_UNK;
        case NS_FIB:
        case NS_PELL:
        case NS_LUCAS:
        case NS_TRI:
        case NS_SQ:
        case NS_PENT:
            pmf_ = func_tbl_[nst];
            elem_ = &seq_[nst];
            isa_ = nst;
            break;
    }
}

bool NumSeqVer1::CheckIntegrity(int pos) const
{
    if (pos <= 0 || pos > max_seq_)
    {
        cerr << "invalid position: " << pos
             << " can not handle request!\n";
        return false;
    }

    if (isa_ == NS_UNK)
    {
        cerr << "object is not select a sequence."
             << " please select a sequence, try again!\n";
        return false;
    }

    return true;
}

ostream &NumSeqVer1::Print(ostream &os)
{
    if (!CheckIntegrity(length_ + beg_pos_ - 1))
        return os;

    //TODO ... 需要处理
    int len = beg_pos_ + length_ - 1;
    if (elem_->size() < len)
        (this->*pmf_)(len);

    for (int ix = beg_pos_ - 1; ix < len; ++ix)
        os << (*elem_)[ix] << ' ';

    return os;
}

int NumSeqVer1::Elem(int pos)
{
    if (!CheckIntegrity(pos))
        return 0;

    if (pos > elem_->size())
    {
        cout << "check integrity: calculating "
             << pos - elem_->size() << " additional elem_ents\n";

        //指定队列生产元素
        (this->*pmf_)(pos);//
    }

    return (*elem_)[pos - 1];
}

bool NumSeqVer1::Begin(iterator &iter)
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return false;

    iter = elem_->begin() + beg_pos_ - 1;
    return true;
}

bool NumSeqVer1::End(iterator &iter)
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return false;

    iter = elem_->begin() + beg_pos_ - 1 + length_;
    return true;
}

const std::vector<int> *NumSeqVer1::Sequence() const
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return 0;

    return elem_;
}

bool NumSeqVer1::IsElem(int elem)
{
    if (!CheckIntegrity(length_ + beg_pos_ - 1))
        return false;

    iterator bit, eit;
    Begin(bit), End(eit);
    return binary_search(bit, eit, elem);
}

int NumSeqVer1::CalcPos(int elem)
{
    int pos = elem_->size() - 1;
    cout << "calc_pos() elem: " << elem
         << " pos: " << pos
         << " at: " << (*elem_)[pos]
         << "\n";

    while ((pos < max_seq_) && ((*elem_)[pos]< elem))
    {
        (this->*pmf_)(++pos);
        cout << " pos: " << pos
             << " at: " << (*elem_)[pos]
             << endl;
    }
    
    return ((pos < max_seq_) && (*elem_)[pos] == elem) ? 
            pos + 1 : 0;
}

int NumSeqVer1::PosElem(int elem)
{
    cout << "pos_elem( " << elem << ")\n";
    if (!CheckIntegrity(1))
        return 0;
    
    iterator it;

    if ((*elem_)[elem_->size() - 1] < elem)
        return CalcPos(elem);

    if ((it = find(elem_->begin(), elem_->end(), elem)) == elem_->end())
        return 0;
    else
        return distance(elem_->begin(), it);
}

ostream &operator<<(ostream &os, NumSeqVer1 &ns)
{
    ns.Print(os);
    return os;
}
