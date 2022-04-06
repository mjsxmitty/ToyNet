

#include <stdio.h>

#include "chapter02/who.h"
#include "chapter02/cp.h"
#include "chapter02/who2.h"

#include "chapter03/ls.h"

int main(int argc, char **argv)
{
    printf("test begin...\n");

    //chapter02
    //Who();
    //Cp(argc, argv);
    //testCacheWho();

    //chapter03
    //testLs(argc, argv);
    testLs(argc, argv);

    printf("test end...\n");
}
