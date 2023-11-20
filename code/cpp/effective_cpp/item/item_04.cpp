
#include "item_04.h"
#include <iostream>

using namespace std;
using namespace effective_item_04;

namespace effective_item_04 {

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

}

void Item04()
{
    cout << "**********item 04**********" << endl;
#if 0
    //Directory d;
    //dir();
    tfs();
#endif
    cout << "***************************" << endl;
}
