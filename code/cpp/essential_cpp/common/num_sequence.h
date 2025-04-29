

#ifndef __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
#define __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <map>
namespace ver1
{

typedef const std::vector<int>* pvec;
typedef pvec (*pfunc)(int);
//typedef const std::vector<int>* (*pfunc)(int);        // 函数指针

const int       seq_cnt = 7;
extern pfunc    seq_array[seq_cnt];
//extern const std::vector<int>* (*seq_array[])(int);
//typedef const std::vector<int>* (*seq_array[])(int);

extern const char* seq_name[seq_cnt];

enum NS_TYPE
{
    NS_UNK,
    NS_FIB,
    NS_LUCAS,
    NS_PELL,
    NS_TRI,
    NS_SQ,
    NS_PENT
};

extern pvec FiboSeq(int size);
extern pvec PellSeq(int size);
extern pvec LucaSeq(int size);
extern pvec TriaSeq(int size);
extern pvec SquaSeq(int size);
extern pvec PentSeq(int size);

extern bool SeqElem(int size, int &elem, pfunc f);

inline void DisPlay(const std::string &msg)
{
    std::cerr << msg << std::endl;
}

inline bool CheckIntegrity(int size)
{
    const int MaxElems = 1024;
    if (size <= 0 || size > MaxElems)
    {
        std::cerr << "invalid size: " << size << std::endl;
        return false;
    }

    return true;
}

}

namespace ver2
{

class NumSequence
{
    friend std::ostream& operator<<(std::ostream &os, const NumSequence &ns);
public:
    typedef void (NumSequence::*PtrType)(int);
    typedef std::vector<int>::iterator iterator;

    enum NUM_SEQ {
        NS_UNK = 0,
        NS_FIB,
        NS_PELL,
        NS_LUCAS,
        NS_TRI,
        NS_SQ,
        NS_PENT
    };
public:
    NumSequence(int beg = 1, int len = 1, NUM_SEQ nst = NS_UNK);
public:
    void SetLength(int len);
    void SetBegin(int beg);
    void SetSequence(NUM_SEQ nst);

    int Elem(int pos);
    int Length() const { return length_; }
    int Begin() const { return beg_pos_; }
    const std::vector<int>* Sequence() const;

    bool Begin(iterator &it);
    bool End(iterator &it);
public:
    static int NumOfSequence() {return num_seq_;}
    static NUM_SEQ SeqType(int num);

    int PosElem(int elem);
    bool IsElem(int elem);
    std::ostream& Print(std::ostream &os);

    bool operator==( const NumSequence &rhs )
    {
        return ( beg_pos_ == rhs.beg_pos_ &&
                 length_ == rhs.length_ &&
                 pmf_ == rhs.pmf_ &&
                 nst_ == rhs.nst_);
    }

    bool operator!=( const NumSequence &rhs )
    {
        return !( *this == rhs );
    }

    char const* WhatAmI() const
    {
        static const char* names[num_seq_] = {
			"not set",
			"fibonacci",
			"pell",
			"lucus",
			"triangular",
			"square",
			"pentagonal"
        };

        return names[nst_];
    }
private:
    void Fibonacci(int pos);
    void Pell(int pos);
    void Lucas(int pos);
    void Triangular(int pos);
    void Sequare(int pos);
    void Pentagonal(int pos);
private:
    static void InitSeqMap()
    {
        seq_map_[ "fibonacci" ] = NS_FIB;
        seq_map_[ "pell" ] = NS_PELL;
        seq_map_[ "lucus" ] = NS_LUCAS;
        seq_map_[ "triangular" ] = NS_TRI;
        seq_map_[ "square" ] = NS_SQ;
        seq_map_[ "pentagonal" ] = NS_PENT;
    }
private:
    bool CheckIntegrity(int pos) const;
    int CalcPos(int elem);
public:
    int                 beg_pos_;
    int                 length_;
    PtrType             pmf_;       // 当前数列函数
    std::vector<int>    *elem_;     // 当前数列的元素
    NUM_SEQ             nst_;       // 当前数列

    static const int                        num_seq_ = 7;       //数列个数（+1）
    static const int                        max_seq_;
    static PtrType                          func_arr_[num_seq_];
    static std::vector<std::vector<int>>    seq_;
    static std::map<std::string, NUM_SEQ>   seq_map_;
};

extern void Display(std::ostream &os, NumSequence &ns, int pos, int elem_val);
std::ostream& operator<<(std::ostream &os, NumSequence &ns);
}

namespace ver3
{

class NumSequence
{
    friend std::ostream& operator<<(std::ostream &os, const NumSequence &ns);
public:
    virtual ~NumSequence(){}
public:
    virtual int             Length() const = 0;
    virtual int             BegPos() const = 0;
    virtual int             Elem(int pos) const = 0;
    virtual const char*     WhatAmI() const = 0;
    virtual std::ostream&   Print(std::ostream &os = std::cout) const = 0;

    static int              MaxElems() { return MaxElems_; }
protected:
    virtual void            GenElems(int pos) const = 0;
    bool                    CheckIntegrity(int pos, int size) const;
protected:
    enum { MaxElems_ = 1024 };
};

std::ostream& operator<<(std::ostream &os, const NumSequence &ns);

inline void Display(std::ostream &os, const NumSequence &ns, int pos)
{
    os << "the element at position: " << pos
        << " for the " << ns.WhatAmI() << " sequence is "
        << ns.Elem(pos) << std::endl;
}

class Fibonacci : public NumSequence
{
public:
    Fibonacci(int len = 1, int beg = 1) : length_(len), beg_pos_(beg) { }
public:
    int             Length() const { return length_; }
    int             BegPos() const { return beg_pos_; }

    int             Elem(int pos) const;
    const char*     WhatAmI() const;
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    void            GenElems(int pos) const;
protected:
    static std::vector<int> elems_;
    int                     length_;
    int                     beg_pos_;
};

}

namespace ver4
{

class NumSequence
{
public:
    NumSequence(int len, int beg, std::vector<int> &re, const std::string &s);
    virtual ~NumSequence() {}
public:
    virtual NumSequence* Clone() = 0;   //
public:
    //virtual const char* WhatAmI() const = 0;
    //const char* WhatAmI() const {return name_.c_str();}
    const char* WhatAmI() const
    {
        return typeid(*this).name();
    }
    int                 Elem(int pos) const;
    std::ostream&       Print(std::ostream &os = std::cout) const;
    int                 Length() const { return length_; }
    int                 BegPos() const { return beg_pos_; }
    
    static int          MaxElems() { return 64; }
protected:
    virtual void        GenElems(int pos) const = 0;                // 
    bool                CheckIntegrity(int pos, int size) const;
protected:
    int                 length_;
    int                 beg_pos_;
    std::vector<int>    &relems_;   // 另一种实现(指针);但是需要检查指针是否为空;引用不需要检查
protected:
    std::string         name_;

    NumSequence& operator=(const NumSequence &rhs);
    NumSequence(const NumSequence &rhs);
};

inline void Display(std::ostream &os, const NumSequence &ns, int pos)
{
    os << "the element at position: " << pos
        << " for the " << ns.WhatAmI() << " sequence is "
        << ns.Elem(pos) << std::endl;
}


class Fibonacci : public NumSequence
{
public:
    Fibonacci(int len = 1, int beg = 1);
    Fibonacci(const Fibonacci &rhs);
    Fibonacci& operator=(const Fibonacci &rhs);
public:
    Fibonacci* Clone() { return new Fibonacci(*this); } // 调用拷贝构造
    // const char* WhatAmI() const { return "fibonacci"; }
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

}

namespace ver5
{

template <int len, int beg_pos>
class NumSequence
{
public:
    virtual ~NumSequence() {}
public:
    int             Elem(int pos);
    const char*     WhatAmI() const;
    static int      MaxElems() { return MaxElems_; }
    std::ostream&   Print(std::ostream &os = std::cout) const;
protected:
    std::vector<int>    *pelems_;
    static const int    MaxElems_ = 1024;
protected:
    NumSequence(std::vector<int> *pv) : pelems_(pv){}
protected:
    virtual void    GenElems(int pos) const = 0;
    bool            CheckIntegrity(int pos, int size) const;
};

template <int len, int beg_pos>
std::ostream& operator<<(std::ostream &os, const NumSequence<len, beg_pos> &ns)
{
    ns.Print(os);
    return os;
}

template<int len, int beg_pos>
int NumSequence<len, beg_pos>::Elem(int pos)
{
    if (!CheckIntegrity(pos, pelems_->size()))
        return 0;

    return (*pelems_)[pos - 1];
}

template<int len, int beg_pos>
const char *NumSequence<len, beg_pos>::WhatAmI() const
{
    return typeid (*this).name();
}

template<int len, int beg_pos>
std::ostream &NumSequence<len, beg_pos>::Print(std::ostream &os) const
{
    int elem_cnt = len + beg_pos - 1;
    if (elem_cnt > (int)pelems_->size())
        GenElems(elem_cnt);

    int elem_pos = beg_pos - 1;
    os << " (" << len << ", " << beg_pos << "): ";
    while (elem_pos < elem_cnt)
        os << (*pelems_)[elem_pos++] << ' ';


    return os;
}

template<int len, int beg_pos>
bool NumSequence<len, beg_pos>::CheckIntegrity(int pos, int size) const
{
    if (pos <= 0 || pos >= MaxElems_)
    {
        std::cerr << "invalid position: " << pos
             << " can not handle request!!"
             << std::endl;
        return false;
    }

    if (pos > size)
        GenElems(pos);

    return true;
}

template<int len, int beg_pos = 1>
class Fibonacci : public NumSequence<len, beg_pos>
{
public:
    Fibonacci() : NumSequence<len, beg_pos>(&elems_) { }
protected:
    void    GenElems(int pos) const;
private:
    static std::vector<int>    elems_;
};

template<int len, int beg_pos>
std::vector<int> Fibonacci<len, beg_pos>::elems_;

template<int len, int beg_pos>
void Fibonacci<len, beg_pos>::GenElems(int pos) const
{
    if (elems_.empty())
    {
        elems_.push_back(1);
        elems_.push_back(1);
    }

    if((int)elems_.size() <= pos)
    {
        int ix = elems_.size();
        int n2 = elems_[ix - 2];
        int n1 = elems_[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            elems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

}

namespace ver6
{

template <void (*pf)(int pos, std::vector<int> &seq)>
class NumSequence;

template<void (*pf)(int pos, std::vector<int> &seq)>
std::ostream& operator<<(std::ostream &os, const NumSequence<pf> &ns);

template <void (*pf)(int pos, std::vector<int> &seq)>
class NumSequence
{
    friend std::ostream& operator<< <>(std::ostream &os, const NumSequence<pf> &ns);
public:
    NumSequence(int len, int bp = 1)
    {
        // if (!pf) return;

        len_ = len > 0 ? len : 1;
        beg_pos_ = bp > 0 ? bp : 1;

        pf(len_ + beg_pos_ - 1, seq_);       //
    }

    std::ostream& Print(std::ostream &os = std::cout);
protected:
    int                 len_;
    int                 beg_pos_;
    std::vector<int>    seq_;
};

template<void (*pf)(int pos, std::vector<int> &seq)>
std::ostream& NumSequence<pf>::Print(std::ostream &os)
{
    os << " (" << len_ << ", " << beg_pos_ << "): ";
    int elem_pos = beg_pos_ - 1;
    int elem_cnt = len_ + beg_pos_ - 1;
    //os << seq_.size() << std::endl;
    while (elem_pos < elem_cnt)
        os << seq_[elem_pos++] << ' ';
    return os;
}

template<void (*pf)(int pos, std::vector<int> &seq)>
std::ostream& operator<<(std::ostream &os, NumSequence<pf> &ns)
{
    ns.Print(os);
    return os;
}

}

namespace ver7
{

typedef unsigned int Uint;

template<typename SeqType>
class NumSequence;

template<typename SeqType>
std::ostream& operator<<( std::ostream &os, const NumSequence<SeqType> &ns );

template<typename SeqType>
class NumSequence
{
public:
    typedef std::vector<unsigned int>::iterator Iterator;

    NumSequence( int len = 1, int bp = 1 );
public:
    Uint Elem( int pos ) const;
    bool IsElem( Uint elem ) const;
    int PosElem( Uint elem) const;

    const char* WhatAmI() const { return SeqType::WhatAmI(); }
    static int MaxElems() { return MaxElems_; }
    std::ostream& Print( std::ostream &os = std::cout ) const;

    void SetPosition( int pos );
    void SetLength( int len );

    bool operator==(const NumSequence &) const;
    bool operator!=(const NumSequence &) const;

    const std::vector<Uint>* Sequence() const { return pelems_; }
    Iterator Begin() const { return pelems_->begin() + beg_pos_ - 1; }
    Iterator End() const { return pelems_->begin() + beg_pos_ + length_; }

    int Length() const { return length_; }
    int BegPos() const { return beg_pos_; }
protected:
    void GenElems( int pos ) const { ns_.GenElems( pos ); }
    bool CheckInterity( int pos, int size ) const;
    int CalcPos( Uint Elem ) const;
protected:
    SeqType             ns_;
    int                 length_;
    int                 beg_pos_;
    std::vector<Uint>   *pelems_;

    static const int    MaxElems_;
};

template<typename SeqType>
const int NumSequence<SeqType>::MaxElems_ = 1024;

template<typename SeqType>
std::ostream& operator<<( std::ostream &os, const NumSequence<SeqType> &ns )
{
    return ns.Print(os);
}

template<typename SeqType>
inline bool NumSequence<SeqType>::operator==( const NumSequence &rhs ) const
{
    return ( beg_pos_ == rhs.beg_pos_ ) && ( length_ == rhs.length_ );
}

template<typename SeqType>
inline bool NumSequence<SeqType>::operator!=( const NumSequence &rhs ) const
{
    return !( *this == rhs );
}

template<typename SeqType>
void NumSequence<SeqType>::SetPosition( int pos )
{
    if ( pos <= 0 || pos >= MaxElems_ )
    {
        std::cerr << "invalid position: " << pos << " default setting 1\n";
        beg_pos_ = 1;
    }

    beg_pos_ = pos;
}

template<typename SeqType>
void NumSequence<SeqType>::SetLength( int len )
{
    if ( len <= 0 || len + beg_pos_ - 1 > MaxElems_ )
    {
        std::cerr << "invalid length: " << len << " default setting 1\n";
        length_ = 1;
    }

    length_ = len;
}

template<typename SeqType>
NumSequence<SeqType>::NumSequence( int len, int bp ) : length_(len),beg_pos_(bp), pelems_( SeqType::ElemSet() )
{
    SetLength(len);
    SetPosition(bp);
}

template<typename SeqType>
Uint NumSequence<SeqType>::Elem( int pos ) const
{
    return ( !CheckInterity( pos, pelems_->size() )) ? 0 : (*pelems_)[ pos - 1 ];
}

template<typename SeqType>
bool NumSequence<SeqType>::CheckInterity( int pos, int size ) const
{
    if ( pos <= 0 || pos >= MaxElems_ )
    {
        std::cerr << "invalid position: " << pos << " can not handle request!\n";
        return false;
    }

    if ( size > MaxElems_ )
    {
        std::cerr << "invalid size: " << size << " can not handle request!\n";
        return false;
    }

    if ( pos > size )
        GenElems( pos );

    return true;
}

template<typename SeqType>
std::ostream& NumSequence<SeqType>::Print( std::ostream &os ) const
{
    int beg_pos = beg_pos_ - 1;
    int end_pos = beg_pos + length_;

    if ( !CheckInterity( end_pos, pelems_->size() ) )
        return os;

    os << "( " << beg_pos_ << ", " << length_ << " )";
    while ( beg_pos < end_pos )
        os << (*pelems_)[beg_pos++] << ' ';
    os << std::endl;
    
    return os;
}

template<typename SeqType>
inline bool NumSequence<SeqType>::IsElem( Uint elem ) const
{
    return ( (!CheckInterity( beg_pos_, pelems_->size() ) ) ? false : binary_search( Begin(), End(), elem ) );
}

template<typename SeqType>
inline int NumSequence<SeqType>::PosElem( Uint elem ) const
{
    if ( ( *pelems_ )[pelems_->size() - 1] < elem )
        return CalcPos( elem );

    Iterator it = find( pelems_->begin(), pelems_->end(), elem );
    return ( it == pelems_->end() ? 0 : distance( pelems_->begin(), it ) + 1 );
}

template<typename SeqType>
inline int NumSequence<SeqType>::CalcPos( Uint elem ) const
{
    int pos = pelems_->size() - 1;
    while ( pos < MaxElems_ && (*pelems_)[pos] < elem )
    {
        ns_.GenElems( ++pos );
    }
    
    return ( ( pos < MaxElems_ ) &&  (*pelems_)[pos] == elem ) ? pos + 1 : 0;
}

class Fibonacci {
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Fibonacci"; }

protected:
    static std::vector<uint> _elems;
};

class Pell {
public:
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Pell"; }

protected:
    static std::vector<uint> _elems;
};

class Lucas {
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Lucas"; }

protected:
    static std::vector<uint> _elems;
};

class Triangular {
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Triangular"; }

protected:
    static std::vector<uint> _elems;
};

class Square {
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Square"; }

protected:
    static std::vector<uint> _elems;
};

class Pentagonal {
public:
    void  GenElems( int pos ) const;
    static std::vector<uint>* ElemSet() { return &_elems; }
    static const char* WhatAmI() { return "Pentagonal"; }

protected:
    static std::vector<uint> _elems;
};

template <typename SeqType>
inline void display( std::ostream &os, const NumSequence<SeqType> &ns, int pos )
{
	os << "The element at position " 
	   << pos            << " for the "
	   << ns.WhatAmI() << " sequence is " 
	   << ns.Elem( pos ) << std::endl;
}

template <typename SeqType>
inline void display( std::ostream &os, const NumSequence<SeqType> &ns, int pos, int elem_val )
{
	os << "The element at position " 
	   << pos            << " for the "
	   << ns.WhatAmI() << " sequence is " 
	   << elem_val << std::endl;
}

}

#endif //__ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
