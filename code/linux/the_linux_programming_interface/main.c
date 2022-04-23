
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("Hello World !\n");

    // printf("%s\n", &argv[2][1]);
    // printf("%c\n", argv[2][1]);
    // for (int ix = 1; ix != argc; ++ix)
    // {
    //     printf("%s\n", &argv[2][1]);
    //     // printf("%ld\n", strlen(argv[ix]));
    //     // printf("%ld\n",strlen(argv[ix]) / sizeof(argv[ix][1]));
    //     // for (int jx = 0; jx != strlen(argv[ix]); ++jx)
    //     // {
    //     //     printf("%c\n", argv[ix][jx]);
    //     // }
        
    // }

    char *ss = "1000";
    printf("%d\n", atoi(ss));
    return 0;
}
