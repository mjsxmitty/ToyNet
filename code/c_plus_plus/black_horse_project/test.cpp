
#include <iostream>
#include <map>
#include <fstream>

#include "test.h"
#include "worker_manager/worker_manager.h"
#include "worker_manager/worker.h"
#include "worker_manager/employee.h"
#include "worker_manager/boss.h"
#include "worker_manager/manager.h"
#include "speech_match/speech_manager.h"

#include "room_booking/identity.h"
#include "room_booking/global.hpp"
#include "room_booking/student.h"
#include "room_booking/teacher.h"
#include "room_booking/manager1.h"

using namespace std;

void test()
{
    Worker *worker = NULL;
    worker = new Employee(1, "张三", 1);
    worker->ShowInfo();
    delete worker;

}

void testWorkerManager()
{
	WorkerManager wm;
	int choice = 0;
	while (true) {
		//展示菜单
		wm.ShowMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice) {
            case 0: //退出系统
                wm.ExitSysterm();
                break;
            case 1: //添加职工
                wm.AddEmployee();
                break;
            case 2: //显示职工
                wm.Show();
                break;
            case 3: //删除职工
                wm.DelEmp();
                break;
            case 4: //修改职工
                wm.ModEmp();
                break;
            case 5: //查找职工
                wm.FindEmp();
                break;
            case 6: //排序职工
                break;
            case 7: //清空文件
                wm.CleanFile();
                break;
            default:
                system("clear");
                break;
		}
	}

	//system("pause");
	return ;
}

void testSpeech()
{
    srand((unsigned int)time(NULL));
    SpeechManager sm;
	int choice = 0; //用来存储用户的选项

	while (true) {
		sm.ShowMenu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice) {
            case 1:  //开始比赛
                sm.StartSpeech();
                break;
            case 2:  //查看记录
                sm.ShowRecord();
                break;
            case 3:  //清空记录
                sm.ClearRecord();
                break;
            case 0:  //退出系统
                sm.ExitSysterm();
                break;
            default:
                system("clear"); //清屏
                break;
		}
	}

	system("pause");
	return ;
}

void StudentMenu(Identity * &student)
{
	while (true)
	{
		student->OperateMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->ApplyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->ShowMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->ShowAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->CancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			// system("pause");
			// system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//教师菜单
		teacher->OperateMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->ShowAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->ValidOrder();
		}
		else
		{
			delete teacher;
			// cout << "注销成功" << endl;
			// system("pause");
			// system("cls");
			return;
		}
	}
}

void ManagerMenu(Identity* &manager)
{
    while (true) {
        manager->OperateMenu();
        Manager1 *man = (Manager1 *)manager;

        int select = 0;
        cin >> select;
        if (select == 1) {
            cout << "添加账号" << endl;
            man->AddPerson();
        } else if (select == 2) {
            cout << "查看账号" << endl;
            man->ShowPerson();
        } else if (select == 3) {
            cout << "查看机房" << endl;
            man->ShowComputer();
        } else if (select == 4) {
            cout << "清空预约" << endl;
            man->CleanFile();
        } else {
            delete manager;
            cout << "注销成功" << endl;
            return ;
        }
    }
}


//登录功能
void LoginIn(string fileName, int type)
{

	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

    //学生登录验证
	if (type == 1) {
		int file_id;
        string file_name;
        string file_pwd;
        
        while (ifs >> file_id && ifs >> file_name && ifs >> file_pwd) {
            if (id == file_id && name == file_name && pwd == file_pwd) {
                //cout << "登陆成功！" << endl;
                person = new Student(id, name, pwd);
                StudentMenu(person);
                return ;
            }
        }
	} else if (type == 2) {
		//教师登录验证
		int file_id;
        string file_name;
        string file_pwd;
        
        while (ifs >> file_id && ifs >> file_name && ifs >> file_pwd) {
            if (id == file_id && name == file_name && pwd == file_pwd) {
                //cout << "登陆成功！" << endl;
                person = new Teacher(id, name, pwd);
                TeacherMenu(person);
                return ;
            }
        }
	} else if(type == 3) {
		//管理员登录验证
		//int file_id;
        string file_name;
        string file_pwd;
        
        while (ifs >> file_name && ifs >> file_pwd) {
            if (name == file_name && pwd == file_pwd) {
                //cout << "登陆成功！" << endl;
                person = new Manager1(name, pwd);
                ManagerMenu(person);
                return ;
            }
        }
	}
	
	cout << "验证登录失败!" << endl;

	// system("pause");
	// system("cls");
	return;
}

void testRoomBooking()
{
	int select = 0;
	while (true) {

		cout << "======================  欢迎进入机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择
		switch (select) {
            case 1:  //学生身份
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:  //老师身份
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:  //管理员身份
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                cout << "欢迎下次使用！" << endl;
                return ;
                break;
            default:
                cout << "输入有误，请重新选择！" << endl;
                // system("pause");
                 system("clear");
                break;
		}

	}
	//system("pause");
	return ;
}