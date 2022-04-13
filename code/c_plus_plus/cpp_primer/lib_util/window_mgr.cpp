

#include "window_mgr.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void TestWindowMgr()
{
    WindowMgr my_window_mgr;
    my_window_mgr.Clear(0);
}

void WindowMgr::Clear(ScreenIndex i)
{
    Screen &s = screens[i];
    //s.contents_ = string(s.height_ * s.weight_, ' ');
    s.Display(cout);
    cout << endl;
    s.contents_ = "";
    s.Display(cout);
    cout << endl;
}

/* 7-4 类的作用域 */
WindowMgr::ScreenIndex WindowMgr::AddScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
