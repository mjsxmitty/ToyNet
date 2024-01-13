
#ifndef __EFFECTIVE_CPP_ITEM_02_H__
#define __EFFECTIVE_CPP_ITEM_02_H__

#include <string>

class GamePlayer
{
private:
    static const int num_turns_ = 1024;
    int scores_[num_turns_];
};

class CostEstimate
{
public:
    static const double fudge_factor_;
    constexpr static const double fudge_factor2_ = 3.14;    // 非const整型
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

