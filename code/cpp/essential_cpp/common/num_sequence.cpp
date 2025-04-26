
#include <iostream>
#include <vector>
#include <algorithm>

#include "num_sequence.h"

using namespace std;

namespace common
{

//pvec (*seq_array[])(int)
pfunc seq_array[seq_cnt] = {
    0,
    FiboSeq,    PellSeq,
    LucaSeq,    TriaSeq,
    SquaSeq,    PentSeq
};

const char* seq_name[seq_cnt] = {
    "none",
    "FiboSeq",    "PellSeq",
    "LucaSeq",    "TriaSeq",
    "SquaSeq",    "PentSeq"
};

pvec FiboSeq(int size)
{
    static vector<int> elems;
    if (!CheckIntegrity(size))
        return 0;

    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(1);
    }

    if ((int)elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < size; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    return &elems;
}

pvec PellSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;

    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(2);
    }

    if ((int)elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < size; ix++)
        {
            elem = n2 + 2 * n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    return &elems;
}

pvec LucaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;

    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(3);
    }

    if ((int)elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix <= size; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    return &elems;
}

pvec TriaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;

    if ((int)elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * (ix + 1) / 2);
    }

    return &elems;
}

pvec SquaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;

    if ((int)elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * ix);
    }

    return &elems;
}

pvec PentSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;

    if ((int)elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * (3 * ix - 1) / 2);
    }

    return &elems;
}

bool SeqElem(int size, int &elem, pfunc f)
{
    pvec pseq = f(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    vector<int> ivec(*pseq);
    for_each(ivec.begin(), ivec.end(), [](int i) {
        cout << i << " ";
    });
    cout << endl;

    elem = (*pseq)[size - 1];

    return true;
}


}

namespace ch_04
{

const int NumSequence::num_seq_;
vector<vector<int>> NumSequence::seq_(num_seq_);
const int NumSequence::max_seq_ = 64;

typedef NumSequence::PtrType    PtrType;
PtrType NumSequence::func_arr_[num_seq_] = {
    0,
    &NumSequence::Fibonacci,
    &NumSequence::Pell,
    &NumSequence::Lucas,
    &NumSequence::Triangular,
    &NumSequence::Sequare,
    &NumSequence::Pentagonal
};
map<string, NumSequence::NUM_SEQ> NumSequence::seq_map_;

NumSequence::NumSequence(int beg, int len, NUM_SEQ nst)
{
    SetBegin(beg);
    SetLength(len);
    SetSequence(nst);
    InitSeqMap();
}

void NumSequence::SetLength(int len)
{
    if (len < 0 || beg_pos_ - 1 + len > max_seq_)
    {
        cerr << "invalid length: " << len << " setting default value of 1\n";
        length_ = 1;
    }

    length_ = len;
}

void NumSequence::SetBegin(int beg)
{
    if (beg <= 0 || beg > max_seq_)
    {
        cerr << "invalid begin position: " << beg << " setting default value of 1\n";
        beg_pos_ = 1;
    }

    beg_pos_ = beg;
}

void NumSequence::SetSequence(NUM_SEQ nst)
{
    switch (nst)
    {
        default:
            cerr << "invalid type, default setting to unset\n";
        case NS_UNK:
            pmf_ = func_arr_[NS_UNK];
            elem_ = 0;
            nst_ = NS_UNK;
            break;
        case NS_FIB:
        case NS_PELL:
        case NS_LUCAS:
        case NS_TRI:
        case NS_SQ:
        case NS_PENT:
            pmf_ = func_arr_[nst];
            elem_ = &seq_[nst];
            nst_ = nst;
            break;
    }
}

int NumSequence::Elem(int pos)
{
    if (!CheckIntegrity(pos))
        return 0;

    if (pos > elem_->size())
    {
        (this->*pmf_)(pos);
    }

    return (*elem_)[pos - 1];
}

const std::vector<int>* NumSequence::Sequence() const
{
    if ( !CheckIntegrity( length_ + beg_pos_ - 1 ) )
        return 0;

    return elem_;
}

bool NumSequence::Begin(iterator &it)
{
    if ( !CheckIntegrity( length_ + beg_pos_ - 1 ) )
        return false;

    it = elem_->begin() + beg_pos_ - 1;
    return true;
}

bool NumSequence::End(iterator &it)
{
    if ( !CheckIntegrity( length_ + beg_pos_ - 1 ) )
        return false;

    it = elem_->begin() + length_ + beg_pos_ - 1;
    return true;
}

NumSequence::NUM_SEQ NumSequence::SeqType(int num)
{
    //
    return (num <= 0 || num >= num_seq_ ? NS_UNK : NUM_SEQ(num));
}

int NumSequence::PosElem(int elem)
{
    if ( !CheckIntegrity( 1 ) )
        return 0;

    if ( (*elem_)[elem_->size() - 1] < elem )
        return CalcPos(elem);
    
    iterator it;
    if ((it = find(elem_->begin(), elem_->end(), elem)) == elem_->end())
        return 0;
    else
        return distance(elem_->begin(), it);
}

bool NumSequence::IsElem(int elem)
{
    if ( !CheckIntegrity( length_ + beg_pos_ - 1 ) )
        return false;

    iterator bit, eit;
    if ( !Begin(bit) || !End(eit) )
    {
        cerr << "get begin/end iterator error!" << endl;
        return false;
    }

    return binary_search(bit, eit, elem);
}

ostream& NumSequence::Print(ostream &os)
{
    if ( !CheckIntegrity( length_ + beg_pos_ - 1 ) )
        return os;

    int num = length_ + beg_pos_ - 1;
    if ( elem_->size() < num )
        (this->*pmf_)(num);

    cout << " ( " <<  beg_pos_ << ", " << length_ << " ) ";
    for (int i = beg_pos_ - 1; i < num; i++)
        os << (*elem_)[i] << ' ';

    return os;
}

void NumSequence::Fibonacci(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
        return;

    if ( elem_->empty() )
    {
        elem_->push_back( 1 );
        elem_->push_back( 1 ); 
    }

    if ( elem_->size() <= pos )
    {
        int ix = elem_->size();
        int n_2 = (*elem_)[ix-2],
            n_1 = (*elem_)[ix-1];

        int val;
        for ( ; ix <= pos; ++ix )
        {
            val = n_2 + n_1;
            elem_->push_back(val);
            n_2 = n_1; n_1 = val;
        }
    }

    length_ = pos;
}

void NumSequence::Pell(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
        return;

    if ( elem_->empty() )
    {
        elem_->push_back(1);
        elem_->push_back(2); 
    }

    if ( elem_->size() <= pos )
    {
        int ix = elem_->size();
        int n_2 = (*elem_)[ix-2],
            n_1 = (*elem_)[ix-1];

        int val;
        for ( ; ix <= pos; ++ix )
        {
            val = n_2 + 2 * n_1;
            elem_->push_back(val);
            n_2 = n_1; n_1 = val;
        }
    }

    length_ = pos;
}

void NumSequence::Lucas(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
        return;

    if ( elem_->empty() )
    {
        elem_->push_back( 1 );
        elem_->push_back( 3 ); 
    }

    if ( elem_->size() <= pos )
    {
        int ix = elem_->size();
        int n_2 = (*elem_)[ix-2],
            n_1 = (*elem_)[ix-1];

        int elem;
        for ( ; ix <= pos; ++ix )
        {
            elem = n_2 +  n_1;
            elem_->push_back(elem);
            n_2 = n_1; n_1 = elem;
        }
    }

    length_ = pos;
}

void NumSequence::Triangular(int pos)
{
    if ( pos <= 0 || pos > max_seq_ )
        return;

    if ( elem_->size() <= pos )
    {
        int end_pos = pos+1;
        int ix = elem_->size()+1;
        for ( ; ix <= end_pos; ++ix )
            elem_->push_back( ix*(ix+1)/2 );
    }

    length_ = pos;
}

void NumSequence::Sequare(int pos)
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

void NumSequence::Pentagonal(int pos)
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

bool NumSequence::CheckIntegrity(int pos) const
{
    if (pos <= 0 || pos > max_seq_)
    {
        cerr << "invalis position: " << pos << endl;
        return false;
    }

    if (nst_ == NS_UNK)
    {
        cerr << "object is not select a sequence! try again!\n";
        return false;
    }

    return true;
}

int NumSequence::CalcPos(int elem)
{
    int pos = elem_->size() - 1;
    while ( pos < max_seq_ && (*elem_)[pos] < elem )
        (this->*pmf_)(++pos);

    return ((pos < max_seq_) && (*elem_)[pos] == elem) ? pos + 1 : 0;
}

void Display(ostream &os, NumSequence &ns, int pos, int elem_val)
{
    os << "--------------------------------" << std::endl;
    os << ns;
    os << "The element at position: " << pos
       << " for the " << ns.WhatAmI() << " sequence is "
       << elem_val << endl;
    os << "--------------------------------" << std::endl;
}

ostream& operator<<(ostream &os, NumSequence &ns)
{
    ns.Print(os);
    return os;
}

}