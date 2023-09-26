
#ifndef __NLP_CHAPTER_04_PWD_H__
#define __NLP_CHAPTER_04_PWD_H__

#include <sys/stat.h>

void pwd();

void print_path_to(ino_t this_node);

ino_t get_inode(char *fname);

void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len);

#endif // __NLP_CHAPTER_04_PWD_H__
