
#include "item_09.h"
#include <iostream>

using namespace effective_item_09;

/* 绝不能在构造和析构过程中发调用virtual函数 */
void Item09()
{
    std::cout << "**********item 09**********" << std::endl;
#if 1
    BuyTranscation t;

#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_09 {

Transcation::Transcation()
{
    //LogTranscation();
    Init();
}

void Transcation::LogTranscation()
{
    std::cout << "Transcation::LogTranscation()" << std::endl;
}

void BuyTranscation::LogTranscation()
{
    std::cout << "BuyTranscation::LogTranscation()" << std::endl;
}

Transcation::Transcation(const std::string &s)
{
    std::cout << "Transcation::Transcation(s)" << std::endl;
    LogTranscation2(s);
}

void Transcation::LogTranscation2(const std::string &s) const
{
    std::cout << "Transcation::LogTranscation2() : " << s << std::endl;
}

BuyTranscation::BuyTranscation() : Transcation(CreateLogString())
{
    std::cout << "BuyTranscation::BuyTranscation()" << std::endl;
}
}
