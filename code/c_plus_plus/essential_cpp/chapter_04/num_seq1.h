

#ifndef __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__
#define __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__

#include <vector>
#include <iostream>

class NumSeqVer1
{
    friend std::ostream& operator<<(std::ostream &os, const NumSeqVer1 &ns);
public:
    typedef void (NumSeqVer1::*PtrType)(int);
    typedef std::vector<int>::iterator  iterator;

    enum NUM_SEQ
    {
        NS_UNK,
        NS_FIB, NS_PELL,NS_LUCAS,
        NS_TRI, NS_SQ,  NS_PENT
    };
public:
    NumSeqVer1(int beg = 1, int len = 1, NUM_SEQ nst = NS_UNK);
private:
    void FiboSeq(int pos);
    void PellSeq(int pos);
    void LucaSeq(int pos);
    void TriaSeq(int pos);
    void SquaSeq(int pos);
    void PentSeq(int pos);
public:
    int                     Elem(int pos);
    bool                    Begin(iterator &iter);
    bool                    End(iterator &iter);
    int                     BegPos(iterator &iter) const { return beg_pos_; };
    int                     Length(iterator &iter) const { return length_; };
    const std::vector<int>* Sequence()const;

    void SetBegPos(int pos);
    void SetLength(int pos);
    void SetSequence(NUM_SEQ nst);
private:
    bool CheckIntegrity(int pos) const;
    std::ostream& Print(std::ostream &os = std::cout) const;
private:
    int                 beg_pos_;
    int                 length_;
    NUM_SEQ             isa_;
    PtrType             pmf_;
    std::vector<int>    *elem_;

    //enum {seq_cnt_ = 7};
    static const int                        seq_cnt_ = 7;
    static PtrType                          func_tbl_[seq_cnt_];
    static std::vector<std::vector<int>>    seq_;
    static const int                        max_seq;
};

std::ostream& operator<<(std::ostream &os, const NumSeqVer1 &ns);

#endif // __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__
