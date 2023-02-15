
#include <vector>
#include <iostream>
#include <algorithm>

#include "num_sequence_ver1.h"

using namespace std;

const int NumSequenceVer1::seq_cnt_;
const int NumSequenceVer1::max_seq_ = 1024;
vector<vector<int>> NumSequenceVer1::seq_(seq_cnt_);
map<string, NumSequenceVer1::NUM_SEQ> NumSequenceVer1::seq_map_;

typedef NumSequenceVer1::PtrType PtrType;
PtrType NumSequenceVer1::func_tbl_[seq_cnt_] = {
    0,
    &NumSequenceVer1::FiboSeq,
    &NumSequenceVer1::LucaSeq,
    &NumSequenceVer1::PellSeq,
    &NumSequenceVer1::PentSeq,
    &NumSequenceVer1::SquaSeq,
    &NumSequenceVer1::TriaSeq
};

NumSequenceVer1::NumSequenceVer1(int beg, int len, NumSequenceVer1::NUM_SEQ nst)
{
    SetBegPos(beg);
    SetLength(len);
    SetSequence(nst);
}

void NumSequenceVer1::FiboSeq(int pos)
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

    length_ = pos;
}

void NumSequenceVer1::PellSeq(int pos)
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

    length_ = pos;
}

void NumSequenceVer1::LucaSeq(int pos)
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
    length_ = pos;
}

void NumSequenceVer1::TriaSeq(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
        return;

    if ( elem_->size() <= pos )
    {
        int end_pos = pos+1;
        int ix = elem_->size()+1;
        //cout << "tri: ix: " << ix << " pos: " << pos << endl;
        for ( ; ix <= end_pos; ++ix )
            elem_->push_back( ix*(ix+1)/2 );
    }
    length_ = pos;
}

void NumSequenceVer1::SquaSeq(int pos)
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
    length_ = pos;
}

void NumSequenceVer1::PentSeq(int pos)
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
    length_ = pos;
}

void NumSequenceVer1::SetBegPos(int pos)
{
    if (pos <= 0 || pos > max_seq_)
    {
        cerr << "invalid begin position: " << pos
            << " setting default position value of 1\n";
        pos = 1;
    }

    beg_pos_ = pos;
}

void NumSequenceVer1::SetLength(int len)
{
    if (len <= 0 || len + beg_pos_ - 1 > max_seq_)
    {
        cerr << "invalid length: " << len
            << " setting default length value of 1\n";
        len = 1;
    }

    length_ = len;
}

void NumSequenceVer1::SetSequence(NUM_SEQ nst)
{
    switch (nst)
    {
        default:
            cerr << "invalid type: setting to 0\n";
        case NS_UNK:
            pmf_ = 0;
            elem_ = 0;
            isa_ = NS_UNK;
            break;
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

bool NumSequenceVer1::CheckIntegrity(int pos) const
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

ostream &NumSequenceVer1::Print(ostream &os)
{
    if (!CheckIntegrity(length_ + beg_pos_ - 1))
        return os;

    int size = beg_pos_ + length_ - 1;
    if (elem_->size() < size)
        (this->*pmf_)(size);

    for (int ix = beg_pos_ - 1; ix < size; ++ix)
        os << (*elem_)[ix] << ' ';

    return os;
}

int NumSequenceVer1::Elem(int pos)
{
    if (!CheckIntegrity(pos))
        return 0;

    if (pos > elem_->size())
    {
        // cout << "check integrity: calculating "
        //         << pos - elem_->size() 
        //         << " additional elem_ents\n";

        //指定队列生产元素
        (this->*pmf_)(pos);//
    }

    return (*elem_)[pos - 1];
}

bool NumSequenceVer1::Begin(iterator &iter)
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return false;

    iter = elem_->begin() + beg_pos_ - 1;
    return true;
}

bool NumSequenceVer1::End(iterator &iter)
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return false;

    iter = elem_->begin() + beg_pos_ - 1 + length_;
    return true;
}

const std::vector<int>* NumSequenceVer1::Sequence() const
{
    if (!CheckIntegrity(length_ + beg_pos_ -1))
        return 0;

    return elem_;
}

bool NumSequenceVer1::IsElem(int elem)
{
    if (!CheckIntegrity(length_ + beg_pos_ - 1))
        return false;

    iterator bit, eit;
    Begin(bit), End(eit);
    return binary_search(bit, eit, elem);
}

int NumSequenceVer1::CalcPos(int elem)
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

int NumSequenceVer1::PosElem(int elem)
{
    cout << "position elem ( " << elem << ")\n";
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

ostream &operator<<(ostream &os, NumSequenceVer1 &ns)
{
    ns.Print(os);
    return os;
}
