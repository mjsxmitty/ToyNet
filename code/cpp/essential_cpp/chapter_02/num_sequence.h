

#ifndef __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
#define __ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__

#include <vector>
#include <iostream>
#include <fstream>

namespace chapter_02
{

namespace ver0 {

typedef const std::vector<int>* pvec; 
//typedef const std::vector<int>* (*pfunc)(int);
typedef pvec (*pfunc)(int);

/* 鍑芥暟鏁扮粍 */
const int       seq_cnt = 7;
extern pfunc    seq_array[seq_cnt];
//extern const std::vector<int>* (*seq_array[])(int);

/* 绫诲瀷 */
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

/* 鍚勭鍑芥暟 */
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
        std::cerr << "invalid size: " << size
                << " cannot handle request!\n";
        return false;
    }
    
    return true;
}

}
}
#endif //__ESSENTIAL_CPP_NUMERIC_SEQUENCE_H__
