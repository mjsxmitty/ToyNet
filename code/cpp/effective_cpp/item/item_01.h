
#ifndef __EFFECTIVE_CPP_ITEM_01_H__
#define __EFFECTIVE_CPP_ITEM_01_H__

#include <string>

void Item01();

#define ASPECT_RATIO    1.653
const double aspect_ratio = 1.654;

const char * const author_name = "Gauo";        // 第二个const
const std::string author_name2("Gauo");

class GamePlayer
{
private:
    static const int num_turns_ = 1024;         // 个别编译器不支持;涉及到取地址需要定义;编译期间知道值
    int scores[num_turns_];

    enum {num_turns2_ = 5};
    int scores_[num_turns2_];
};

class CostEstimate
{
public:
    static const double fudge_factor_;
};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
void f(int i);

#endif // __EFFECTIVE_CPP_ITEM_01_H__
