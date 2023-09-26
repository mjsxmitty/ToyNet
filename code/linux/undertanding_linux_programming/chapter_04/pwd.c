
#include "pwd.h"

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

#define BUFF_SIZE   512

void pwd()
{
    print_path_to(get_inode("."));
    putchar('\n');
    exit(1);
}

void print_path_to(ino_t this_node)
{
    ino_t my_node;
    char its_name[BUFF_SIZE];

    if (get_inode("..") != this_node) {
        chdir("..");
        inum_to_name(this_node, its_name, BUFF_SIZE);       // 获取当前目录
        my_node = get_inode(".");
        print_path_to(my_node);
        printf("/%s", its_name);
    }
}

ino_t get_inode(char *fname)
{
    struct stat info;
    if (stat(fname, &info) == -1) {
        fprint(stderr, "cannot stat");
        perror(fname);
        exit(-1);
    }

    return info.st_ino;
}

void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len)
{
    DIR             *dir_ptr;
    struct dirent   *dirent_ptr;

    dir_ptr = opendir(".");
    if (dir_ptr == NULL) {
        perror(".");
        exit(-1);
    }

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
