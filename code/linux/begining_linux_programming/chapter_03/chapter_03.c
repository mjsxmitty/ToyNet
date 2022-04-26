
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "chapter_03.h"

void Chapter_03()
{
    chapter_3_4_3();
}

void chapter_3_4_1()
{
    if (write(1, "Here is some data\n", 18) != 18) 
        write(2, "a write error has occurred on file descriptor 1\n", 50);
}

void chapter_3_4_2()
{
    char buf[128];
    int nread;

    nread = read(0, buf, 128);
    if (nread == -1)
        write(2, "a read error has occurred\n", 27);

    if (write(1, buf, nread) != nread)
        write(2, "a write error has occurred\n", 28);
}

/**/
void chapter_3_4_3()
{
    char    c;
    int     in_fd, out_fd;
    char    buf[1024];

    in_fd = open("/home/gao_zhuo/share/snail/code/linux/begining_linux_programming/build/file.in", O_RDONLY);
    out_fd = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    // while (read(in_fd, &c, 1) == 1)
    //     write(out_fd, &c, 1);

    int nread;
    while ((nread = read(in_fd, buf, 1024)) > 0)
        write(out_fd, buf, nread);
    
    printf("write finished.");
    exit(0);
}