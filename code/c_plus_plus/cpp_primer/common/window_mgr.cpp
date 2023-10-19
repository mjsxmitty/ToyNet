
#include "window_mgr.h"

void WindowMgr::Clear(ScreenIndex i)
{
    Screen &s = screens_[i];
    //s.contents_ = std::string(s.height_ * s.width_, ' ');
    s.contents_.clear();
}

WindowMgr::ScreenIndex WindowMgr::AddScreen(const Screen &s)
{
    screens_.push_back(s);
    return screens_.size() - 1;
}
