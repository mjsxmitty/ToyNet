
#ifndef __CPP_PRIMER_WINDOWMGR_H__
#define __CPP_PRIMER_WINDOWMGR_H__

#include "screen.h"

#include <vector>

class WindowMgr
{
public:
    //using ScreenIndex = std::vector<Screen>::size_type;
    typedef std::vector<Screen>::size_type ScreenIndex;
public:
    void Clear(ScreenIndex i);
    ScreenIndex AddScreen(const Screen &s);
private:
    /* 7-3-1-6 类数据成员初始化 {} = */
    std::vector<Screen> screens{Screen(24, 80, 'X')};
};

void TestWindowMgr();
#endif // __CPP_PRIMER_CHAPTER_07_WINDOWMGR_H__
