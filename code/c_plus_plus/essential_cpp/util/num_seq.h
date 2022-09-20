

#ifndef __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
#define __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__

#include <vector>
#include <iostream>
#include <fstream>

typedef const std::vector<int>* pvec; 
typedef const std::vector<int>* (*pfunc)(int);

const int       seq_cnt = 7;
extern pfunc    seq_array[seq_cnt];
//extern const std::vector<int>* (*seq_array[])(int);

enum NS_TYPE
{
    NS_UNK, 
    NS_FIB,
    NS_PELL,
    NS_LUCAS,
    NS_TRI,
    NS_SQ,
    NS_PENT
};

//
extern pvec FiboSeq(int pos);
extern pvec PellSeq(int pos);
extern pvec LucaSeq(int pos);
extern pvec TriaSeq(int pos);
extern pvec SquaSeq(int pos);
extern pvec PentSeq(int pos);

extern bool SeqElem(int pos, int &elem, pfunc f);

inline void DisPlay(const std::string &msg)
{
    std::cerr << msg << std::endl;
}

inline bool CheckIntegrity(int pos)
{
    const int max_elems = 512;
    if (pos <= 0 || pos > max_elems)
    {
        std::cerr << "invalid position: " << pos
                  << " cannot handle request!\n";
        return false;
    }
    
    return true;
}

#endif //__ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
