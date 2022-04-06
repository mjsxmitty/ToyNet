
#ifndef __CPP_PRIMER_CHAPTER_07_WINDOWMGR_H__
#define __CPP_PRIMER_CHAPTER_07_WINDOWMGR_H__

#include "screen.h"

#include <vector>

class WindowMgr
{
public:
    //using ScreenIndex = std::vector<Screen>::size_type;
    typedef std::vector<Screen>::size_type ScreenIndex;
public:
    //WindowMgr();
public:
    void Clear(ScreenIndex i);
    ScreenIndex AddScreen(const Screen &s);
private:
    //类内初始化使用{}和=
    std::vector<Screen> screens{Screen(24, 80, 'X')};
};

void TestWindowMgr();
#endif // __CPP_PRIMER_CHAPTER_07_WINDOWMGR_H__
