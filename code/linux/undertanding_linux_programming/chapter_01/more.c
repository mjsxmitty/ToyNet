
#include "more.h"
#include <stdlib.h>

#define PAGE_LEN    24
#define LINE_LEN    512

void More(int argc, char **argv)
{
#if 0
    printf("cnt:%d\n", argc);
    return;
#endif
    FILE    *fp;
    if (argc == 1)
        DoMore(stdin);
    else {
        int i = 1;
        for (; i < argc; ++i) {
            if ((fp = fopen(argv[i], "r")) != NULL) {
                DoMore(fp);
                fclose(fp);
            } else {
                exit(1);
            }
        }
    }
    
    return ;
}

void DoMore(FILE *fp)
{
    char    line[LINE_LEN];
    int     num_of_lines = 0;
    int     reply = 0;

    FILE *fp_tty = fopen("/dev/tty", "r");
    if (fp_tty == NULL)
        exit(1);

    while (fgets(line, LINE_LEN, fp)) {
        if (num_of_lines == PAGE_LEN) {

            reply = SeeMore(fp_tty);
            if (reply == 0)
                break;

            printf("reply: %d", reply);
            num_of_lines -= reply;
        }

        if (fputs(line, stdout) == EOF)
            exit(1);

        num_of_lines++;
    }
}

int SeeMore(FILE *fp)
{
    printf("\033[7m more? \033[m");

    int     c;
    //while ((c = getchar()) != EOF)
    while ((c= getc(fp)) != EOF) {
        if (c == 'q') return 0;
        if (c == ' ') return PAGE_LEN;
        if (c == '\n') return 1;
    }
    
    return 0;
}
