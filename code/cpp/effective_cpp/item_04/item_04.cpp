
#include "item_04.h"
#include <iostream>

using namespace std;

/* 确定对象被使用前已被初始化 */
int main()
{
#if 0
    //Directory d;
    //dir();
    tfs();
#endif
    return 0;
}


//FileSystem tfs;

// 
//Directory temp_dir;

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
