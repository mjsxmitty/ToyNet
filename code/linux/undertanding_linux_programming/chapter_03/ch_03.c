
#include "ch_03.h"
#include "ls.h"

void ch_03(int argc, char **argv)
{
    if (argc == 1) 
        //DoLs(".");
        DoStat(".");
    else {
        for (int i = 1; i < argc; ++i) {
            //DoLs(argv[i]);
            //DoStat(argv[i]);
        }
    }
}