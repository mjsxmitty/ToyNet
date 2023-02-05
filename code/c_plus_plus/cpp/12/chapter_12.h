
#ifndef __CPP_CHAPETR_12_HPP__
#define __CPP_CHAPETR_12_HPP__

#include <memory>

using namespace std;

namespace chapter_12
{

void Test1();
void Test2();

class TestPtr : public enable_shared_from_this<TestPtr>
{
public:

};

void Test3();
void Test4();
void Test5();
void Test6();
}

#endif //__CPP_CHAPETR_12_HPP__
