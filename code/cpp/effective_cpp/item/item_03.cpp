
#include "item_03.h"
#include <iostream>

using namespace std;
using namespace effective_item_03;

namespace effective_item_03 {

//FileSystem tfs;

// 问题得以显现: 构造函数执行的时候不能保证tfs对象已经被初始化
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

}

void Item03()
{
    cout << "**********item 03**********" << endl;
#if 0
    //Directory d;
    //dir();
    tfs();
#endif
    cout << "***************************" << endl;
}
