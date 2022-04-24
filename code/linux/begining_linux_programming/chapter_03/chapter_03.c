
#include <unistd.h>
#include "chapter_03.h"

void Chapter_03()
{

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
