
#include "ch_03.h"
#include "ls.h"

void ch_03(int argc, char **argv)
{
    if (argc == 1) 
        //DoLs(".");
        DoStat(".");
    else {
        int i = 1;
        for (; i < argc; ++i) {
            //DoLs(argv[i]);
            DoStat(argv[i]);
        }
    }
}
