

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <vector>

#include "identity.h"
#include "computer_room.h"

class Student : public Identity
{
public:
    int     id;
	std::vector<ComputerRoom> computers_;
public:
    Student(/* args */);
    //~Student();
    Student(int id, std::string name, std::string passwd);
public:
	//菜单界面
    void OperateMenu(); 

	//申请预约
	void ApplyOrder(); 

	//查看我的预约
	void ShowMyOrder(); 

	//查看所有预约
	void ShowAllOrder(); 

	//取消预约
	void CancelOrder();
};




#endif //__STUDENT_H__