

#ifndef __GZ_WINDOW_MGR_H__
#define __GZ_WINDOW_MGR_H__

#include <vector>
#include "gz_screen.h"

class GZWindowMgr
{
public:
    //GZWindowMgr();
private:
    // 7.3.1类成员初始化
    std::vector<GZScreen>   screens_{GZScreen(10, 20, '*')};
};

#endif // __GZ_WINDOW_MGR_H__
