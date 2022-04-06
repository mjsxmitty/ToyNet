

#ifndef __TEACHER_H__
#define __TEACHER_H__

#include <string>
#include "identity.h"


class Teacher : public Identity
{
public:
    int     id;
public:
    Teacher(/* args */);
    //~Teacher();
    Teacher(int id, std::string name, std::string pwd);
public:
	//菜单界面
    void OperateMenu();

	//查看所有预约
	void ShowAllOrder(); 

	//审核预约
	void ValidOrder(); 
};




#endif
