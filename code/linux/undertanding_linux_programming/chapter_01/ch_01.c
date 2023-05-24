
#include "ch_01.h"

#include <stdlib.h>

#define PAGE_LEN    24
#define LINE_LEN    512

void ch_01(int argc, char **argv)
{
    More(argc, argv);
}

void More(int argc, char **argv)
{
    FILE    *fp;
    if (argc == 1)
        DoMore(stdin);
    else
        while (--argc) {
            if ((fp = fopen(*++argv, "r")) != NULL) {
                DoMore(fp);
                fclose(fp);
            } else
                exit(1);
        }
    
    return ;
}

void DoMore(FILE *fp)
{
    char    line[LINE_LEN];
    int     num_of_lines = 0;
    int     reply = 0;

    FILE *fp_tty = fopen("/dev/tty2", "r");
    if (fp_tty == NULL)
        exit(1);

    while (fgets(line, LINE_LEN, fp)) {

        if (num_of_lines == PAGE_LEN) {
            
            reply = SeeMore(fp_tty);
            if (reply == 0)
                break;

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
