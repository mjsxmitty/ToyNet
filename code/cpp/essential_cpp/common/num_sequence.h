

#ifndef __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
#define __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__

#include <vector>
#include <iostream>
#include <fstream>

namespace common
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
    const int max_elems = 1024;
    if (size <= 0 || size > max_elems)
    {
        std::cerr << "invalid size: " << size << std::endl;
        return false;
    }

    return true;
}

}

namespace ch_04
{

class NumSequence
{
public:
    typedef void (NumSequence::*PtrType)(int);

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
    const std::vector<int>* Sequence() const { return elem_; }
public:
    static int NumOfSequence() {return num_seq_;}
    static NUM_SEQ SeqType(int num);
private:
    void Fibonacci(int pos);
    void Pell(int pos);
    void Lucas(int pos);
    void Triangular(int pos);
    void Sequare(int pos);
    void Pentagonal(int pos);
private:
    bool CheckIntegrity(int pos);

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
};


}

#endif //__ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
