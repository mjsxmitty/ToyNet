
#ifndef __ESSENTIAL_CPP_NUMSEQ_VER1_H__
#define __ESSENTIAL_CPP_NUMSEQ_VER1_H__

#include <vector>
#include <iostream>
#include <map>
#include <string>


namespace chapter_04
{

class NumSequence
{
    friend std::ostream& operator<<(std::ostream &os, NumSequence &ns);
public:
    typedef void (NumSequence::*PtrType)(int);
    typedef std::vector<int>::iterator  iterator;

    enum NUM_SEQ
    {
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

    bool IsElem(int elem);
public:
    int                     Elem(int pos);
    bool                    Begin(iterator &iter);
    bool                    End(iterator &iter);
    int                     BegPos() const { return beg_pos_; };
    int                     Length() const { return length_; };
    const std::vector<int>* Sequence() const;

    void SetBegPos(int pos);
    void SetLength(int pos);
    void SetSequence(NUM_SEQ nst);
public:
    char const* WhatAmI() const
    {
        static const char* names[seq_cnt_] = {
			"not set",
			"fibonacci",
			"pell",
			"lucus",
			"triangular",
			"square",
			"pentagonal"            
        };

        return names[isa_];
    }
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
public:
    static NUM_SEQ SeqType(int num)
    {
        if (seq_map_.empty())
            InitSeqMap();

        return num <= 0 || num >= seq_cnt_ ?
                NS_UNK : NUM_SEQ(num);
    }
public:
    bool operator==(const NumSequence &rhs) const
    {
        return (beg_pos_ == rhs.beg_pos_) &&
                (length_ == rhs.length_) &&
                (pmf_ == rhs.pmf_);
    }

    inline bool operator!=(const NumSequence &rhs) const
    {
        return !(*this == rhs);
    }

    int PosElem(int elem);
public:
    static int NumOfSequence() { return seq_cnt_; }
private:
    void FiboSeq(int pos);
    void PellSeq(int pos);
    void LucaSeq(int pos);
    void TriaSeq(int pos);
    void SquaSeq(int pos);
    void PentSeq(int pos);
private:
    bool CheckIntegrity(int pos) const;
    std::ostream& Print(std::ostream &os = std::cout);
    int CalcPos(int elem);
private:
    int                 beg_pos_;
    int                 length_;
    NUM_SEQ             isa_;
    PtrType             pmf_;
    std::vector<int>    *elem_;

    //enum {seq_cnt_ = 7};
    static const int                        seq_cnt_ = 7;
    static const int                        max_seq_;
    static PtrType                          func_tbl_[seq_cnt_];
    static std::vector<std::vector<int>>    seq_;
    static std::map<std::string, NUM_SEQ>   seq_map_;
};

std::ostream& operator<<(std::ostream &os, const NumSequence &ns);

extern void Display(std::ostream &os, NumSequence &ns, int pos, int elem_val);
}
#endif // __ESSENTIAL_CPP_NUMSEQ_VER1_H__
