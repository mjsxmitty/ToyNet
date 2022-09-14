
#include <stdio.h>
#include <unistd.h>

#include "chapter_03/chapter_03.h"

int main(int argc, char **argv)
{
    printf("hello world!\n");

    // printf("str=%*s%s/\n", 0, "", "gao");
    // printf("str=%*s%s/\n", 4, "", "zhuo");
    // printf("str=%*s, %s\n", 10, "hello", "gz");
    // printf("str=%*s, %*s\n", -10, "hello", 20, "gz");
    // printf("str=%.*s, %s\n", 10, "hello", "gz");
    // printf("str=%.*s, %s\n", 3, "hello", "gz");
    ch_03(argc, argv);


    return 0;
}
