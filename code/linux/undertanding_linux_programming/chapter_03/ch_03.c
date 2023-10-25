
#include "ch_03.h"
#include "ls.h"

void ch_03(int argc, char **argv)
{
    if (argc == 1) 
        do_ls(".");
    else {
        int i = 1;
        for (; i < argc; ++i) {
            do_ls(argv[i]);
        }
    }
}
