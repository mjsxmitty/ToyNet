
#include "item_04.h"
#include <iostream>

using namespace std;

/* 确定对象被使用前已被初始化 */
int main()
{
#if 1
    //Directory d;
    dir();
#endif
    return 0;
}

// 讲非本地静态对象放在一个专属处理函数中
FileSystem& tfs()
{
    std::cout << "tfs static func" << std::endl;
    static FileSystem fs;
    return fs;
}

Directory& dir()
{
    std::cout << "dir static func" << std::endl;
    static Directory td;
    return td;
}
