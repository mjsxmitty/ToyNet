

#ifndef __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__
#define __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__

#include <vector>
#include <iostream>
#include <map>
#include <string>
class NumSeqVer1
{
    friend std::ostream& operator<<(std::ostream &os, NumSeqVer1 &ns);
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
    int                     BegPos() const { return beg_pos_; };
    int                     Length() const { return length_; };
    const std::vector<int>* Sequence() const;

    void SetBegPos(int pos);
    void SetLength(int pos);
    void SetSequence(NUM_SEQ nst);
    
    bool IsElem(int elem);
public:
    const char* WhatAmI() const 
    {
        static char* names[seq_cnt_] = {
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

    // static void InitSeqMap()
    // {
	// 	seq_map_[ "fibonacci" ] = NS_FIB;
	// 	seq_map_[ "pell" ] = NS_PELL;   
	// 	seq_map_[ "lucus" ] = NS_LUCAS;
	// 	seq_map_[ "triangular" ] = NS_TRI; 
	// 	seq_map_[ "square" ] = NS_SQ; 
	// 	seq_map_[ "pentagonal" ] = NS_PENT;
    // }

    static NUM_SEQ SeqType(/*const char *name*/ int num)
    {
        // if (seq_map_.empty())
        //     InitSeqMap();
        
        // std::string nm(name);
        // return (seq_map_.count(nm)) ? 
        //         seq_map_(nm) : NS_UNK;

        return num <= 0 || num >= seq_cnt_ ?
                NS_UNK : static_cast<NUM_SEQ>(num);
    }
public:
    bool operator==(const NumSeqVer1 &rhs) const
    {
        return (beg_pos_ == rhs.beg_pos_) &&
                (length_ == rhs.length_);
    }

    inline bool operator!=(const NumSeqVer1 &rhs) const
    {
        return !(*this == rhs);
    }

    int PosElem(int elem);
public:
    static int NumOfSequence() { return seq_cnt_; }
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
    static PtrType                          func_tbl_[seq_cnt_];
    static std::vector<std::vector<int>>    seq_;
    static const int                        max_seq_;
    static std::map<std::string, NUM_SEQ>   seq_map_;
};

std::ostream& operator<<(std::ostream &os, const NumSeqVer1 &ns);

#endif // __ESSENTIAL_CPP_CHAPTER_04_NUMSEQ_H__
