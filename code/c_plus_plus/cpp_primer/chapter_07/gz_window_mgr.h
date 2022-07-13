

#ifndef __GZ_WINDOW_MGR_H__
#define __GZ_WINDOW_MGR_H__

#include <vector>
#include "gz_screen.h"

class GZWindowMgr
{
private:
    // 7.3.1类成员初始化
    std::vector<GZScreen>   screens_{GZScreen(10, 20, '*')};
public:
    // 7.3.4 友元再探
    //类之间的友元关系
    using ScreenIndex = std::vector<GZScreen>::size_type;
    void Clear(ScreenIndex);

    //7.4 类的作用域
    //作用域和定义在类外部的成员
    ScreenIndex AddScreen(const GZScreen &);
};

#endif // __GZ_WINDOW_MGR_H__
