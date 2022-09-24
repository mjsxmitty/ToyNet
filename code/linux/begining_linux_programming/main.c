
#include <stdio.h>
#include <unistd.h>

#include "chapter_03/chapter_03.h"
#include "chapter_04/chapter_04.h"

int main(int argc, char **argv)
{
    printf("==================Hello World!==================\n");

    //ch_03(argc, argv);

    ch_04(argc, argv);

	printf("===Quietly try and amaze everyone's sentences===\n");
    return 0;
}
