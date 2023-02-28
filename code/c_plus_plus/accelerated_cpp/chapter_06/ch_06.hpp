
#ifndef __ACCELERATED_CPP_CH_06_HPP__
#define __ACCELERATED_CPP_CH_06_HPP__

#include "student.h"
#include <vector>
#include <iostream>

namespace chapter_06 {

void ch_6()
{
    std::vector<chapter_04::StudentInfo> did, didnt;
    chapter_04::StudentInfo student;

    while (chapter_04::Read(std::cin, student))
    {
        if (DidAllHW(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    
    WriteAnalysis(std::cout, "median", MedianAnalysis, did, didnt);
    WriteAnalysis(std::cout, "average", AverageAnalysis, did, didnt);
    WriteAnalysis(std::cout, "optimisc", OptimisticAnalysis, did, didnt);
}

}
#endif // __ACCELERATED_CPP_CH_06_HPP__