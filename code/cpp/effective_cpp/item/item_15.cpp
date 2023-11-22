

#include "item_15.h"
#include <iostream>

using namespace effective_item_15;

/* 在资源管理类中提供原始资源的访问 */
void Item15()
{
    std::cout << "**********item 15**********" << std::endl;
#if 0
    Font f(GetFont());
    int new_font_size = 1024;

    ChangeFontSize(f.get(), new_font_size);
#endif
#if 1
    Font f(GetFont());
    int new_font_size = 1024;

    ChangeFontSize(f, new_font_size);

    // 存在风险（f已经释放）
    FontHandle fh = f;
#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_15 {

FontHandle GetFont()
{
    static FontHandle fh;
    return fh;
}

void ReleaseFont(FontHandle fh)
{
    std::cout << "release font." << std::endl;
}

void ChangeFontSize(FontHandle f, int new_size)
{
    std::cout << "change font size: " << new_size << std::endl;
}

}
