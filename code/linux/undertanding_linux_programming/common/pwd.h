
#ifndef __NLP_CHAPTER_04_PWD_H__
#define __NLP_CHAPTER_04_PWD_H__

#include <sys/stat.h>

/*pwd 命令实现*/
void pwd();

/*输出全路径*/
void print_path_to(ino_t this_node);

/*获取指定文件的inode*/
ino_t get_inode(char *fname);

/*获取指定inode的文件名*/
void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len);

#endif // __NLP_CHAPTER_04_PWD_H__
