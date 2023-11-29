
#include "pwd.h"

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE   512

void pwd()
{
    print_path_to();
    putchar('\n');
    return ;
}

void print_path_to()
{
    ino_t my_node;
    char its_name[BUFF_SIZE];

    my_node = get_inode(".");

    if (get_inode("..") != my_node) {
        chdir("..");
        inum_to_name(my_node, its_name, BUFF_SIZE);
        print_path_to();
        printf("/%s", its_name);
    }
}

ino_t get_inode(char *fname)
{
    struct stat info;
    if (stat(fname, &info) == -1) {
        perror(fname);
        exit(-1);
    }

    return info.st_ino;
}

void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len)
{
    DIR             *dir_ptr;
    struct dirent   *dirent_ptr;

    // 打开当前目录(输入节点的上一级目录)
    dir_ptr = opendir(".");
    if (dir_ptr == NULL) {
        perror(".");
        exit(-1);
    }

    // 遍历
    while ((dirent_ptr = readdir(dir_ptr)) != NULL) {
        if (dirent_ptr->d_ino == inode_to_find) {
            strncpy(name_buf, dirent_ptr->d_name, buf_len);
            name_buf[buf_len - 1] = '\0';
            closedir(dir_ptr);
            return ;
        }
    }

    fprintf(stderr, "error looking for inum: %d\n", inode_to_find);
    exit(-1);
}
