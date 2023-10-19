

#ifndef __CPP_PRIMER_WINDOW_MGR_H__
#define __CPP_PRIMER_WINDOW_MGR_H__

#include <vector>
#include "screen.h"

class WindowMgr
{

public:
    using ScreenIndex = std::vector<Screen>::size_type;
public:
    void Clear(ScreenIndex);

    ScreenIndex AddScreen(const Screen &);
private:
    std::vector<Screen>   screens_{Screen(10, 20, '*')};
};

#endif // __CPP_PRIMER_WINDOW_MGR_H__
