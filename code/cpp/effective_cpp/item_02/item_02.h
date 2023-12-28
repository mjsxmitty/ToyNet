
#ifndef __EFFECTIVE_CPP_ITEM_02_H__
#define __EFFECTIVE_CPP_ITEM_02_H__

#include <string>

#define ASPECT_RATIO    1.653
const double aspect_ratio = 1.654;

const char * const author_name = "Gauo";        // 第二个const
const std::string author_name2("Gauo");         // 最优

class GamePlayer
{
private:
    /*
     * 个别编译器不支持;
     * 涉及到取地址需要实现文件定义;
     * 编译期间知道值;
     * 只针对整型常量
     */
    static const int num_turns_ = 1024;
    int scores_[num_turns_];
};

class CostEstimate
{
public:
    static const double fudge_factor_;
};

class GamePlayer2
{
private:
    // 不能取地址
    enum {num_turns_ = 5};
    int scores_[num_turns_];
};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
void f(int i);

template<typename T>
inline void CallWithMax(const T &lhs, const T &rhs)
{
    f(lhs > rhs ? lhs : rhs);
}

#endif // #define __EFFECTIVE_CPP_ITEM_02_H__

