

#ifndef __MANAGER1_H__
#define __MANAGER1_H__

#include <vector>
#include <string>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"

class Manager1 : public Identity
{
public:
    Manager1(std::string name, std::string pwd);
    // ~Manager();
    // Manager();
public:
    void OperateMenu();
	//添加账号  
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房信息
	void ShowComputer();

	//清空预约记录
	void CleanFile();
private:
	void InitVector();
	bool CheckRepeat(int id, int type);
public:
	std::vector<Student>	students_;
	std::vector<Teacher>	teachers_;

	std::vector<ComputerRoom>	computers_;
};




#endif
