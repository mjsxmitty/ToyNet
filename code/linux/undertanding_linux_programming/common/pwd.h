
#ifndef __NLP_PWD_H__
#define __NLP_PWD_H__

#include <sys/stat.h>

/*pwd 锟斤拷锟斤拷实锟斤拷*/
void pwd();

/*锟斤拷锟饺凤拷锟�*/
void print_path_to();

/*锟斤拷取指锟斤拷锟侥硷拷锟斤拷inode*/
ino_t get_inode(char *fname);

/*锟斤拷取指锟斤拷inode锟斤拷锟侥硷拷锟斤拷*/
void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len);

#endif // __NLP_PWD_H__
