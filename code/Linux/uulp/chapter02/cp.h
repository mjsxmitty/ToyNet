
/**
 * 读写文件
 */


#ifndef __CHAPTER02_CP_H__
#define __CHAPTER02_CP_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE   4096
#define COPY_MODE   0644    

int Cp(int ac, char **av)
{
    int     in_fd, out_fd, n_chars;
    char    buf[BUFF_SIZE];

    //printf("%d, %s", ac, av);
    if (ac != 3) {
        fprintf(stderr, "Usage: %s source destination.\n", *av);
        exit(-1);
    }
    
    //printf("open source .. ");
    if ((in_fd = open(av[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Open source file %s error.\n", av[1]);
        exit(-1);
    }

    //printf("create dest .. ");
    if ((out_fd = creat(av[2], COPY_MODE)) == -1) {
        fprintf(stderr, "Create destination %s file error.\n", av[2]);
        exit(-1);
    }
    
    //printf("read and write .. ");
    while ((n_chars = read(in_fd, buf, BUFF_SIZE)) > 0) {
        if (write(out_fd, buf, n_chars) != n_chars) {
            fprintf(stderr, "Write file  content error.\n");
            exit(-1);
        }
    }
    
    //printf("read and write .. ");
    if (n_chars == -1) {
        fprintf(stderr, "Read file content error.\n");
        exit(-1);
    }

    //printf("close .. ");
    if (close(in_fd) == -1 || close(out_fd) == -1) {
        fprintf(stderr, "Close file error.\n");
        exit(-1);
    }

    return 0;   
}


#endif //__CHAPTER02_WHO_H__