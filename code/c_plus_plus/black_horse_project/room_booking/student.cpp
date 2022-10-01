
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "global.hpp"
#include "student.h"
#include "computer_room.h"
#include "order_file.h"

using namespace std;

Student::Student(/* args */)
{
}

Student::Student(int id, std::string name, std::string passwd)
{
    this->id = id;
    name_ = name;
    passwd_ = passwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom cr;
    while (ifs >> cr.id_ && ifs >> cr.max_num_) {
        computers_.push_back(cr);
    }
    
    ifs.close();
}

void Student::OperateMenu()
{
	cout << "欢迎学生代表： " << name_ << " 登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Student::ApplyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

    int date = 0;
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

    int interval = 0;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    
	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << computers_[0].max_num_ << endl;
	cout << "2号机房容量：" << computers_[1].max_num_ << endl;
	cout << "3号机房容量：" << computers_[2].max_num_ << endl;

    int room = 0;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 3) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << id << " ";
	ofs << "stuName:" << name_ << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
    ofs.close();
} 


void Student::ShowMyOrder()
{
    OrderFile of;
    if (of.size_ == 0) {
		cout << "无预约记录" << endl;
		return;
    }
    
    for (int i = 0; i < of.size_; i++) {
        if (atoi(of.order_data_[i]["stuId"].c_str()) == id) {
			cout << "预约日期： 周" << of.order_data_[i]["date"];
			cout << " 时段：" << (of.order_data_[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.order_data_[i]["roomId"];

            string status = " 状态： ";
            if (of.order_data_[i]["status"] == "1") {
                status +=  "审核中";
            } else if (of.order_data_[i]["status"] == "2") {
                status += "预约成功";
            } else if (of.order_data_[i]["status"] == "-1") {
                status += "审核未通过，预约失败";
            } else {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
} 


void Student::ShowAllOrder()
{
    OrderFile of;
    if (of.size_ == 0) {
		cout << "无预约记录" << endl;
		return;
    }
    
    for (int i = 0; i < of.size_; i++) {
        cout << "预约日期： 周" << of.order_data_[i]["date"];
        cout << " 时段：" << (of.order_data_[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 机房：" << of.order_data_[i]["roomId"];
		cout << " 学号：" << of.order_data_[i]["stuId"];
		cout << " 姓名：" << of.order_data_[i]["stuName"];

        string status = " 状态： ";
        if (of.order_data_[i]["status"] == "1") {
            status +=  "审核中";
        } else if (of.order_data_[i]["status"] == "2") {
            status += "预约成功";
        } else if (of.order_data_[i]["status"] == "-1") {
            status += "审核未通过，预约失败";
        } else {
            status += "预约已取消";
        }
        cout << status << endl;
    }
} 


void Student::CancelOrder()
{
    OrderFile of;
    if (of.size_ == 0) {
		cout << "无预约记录" << endl;
		return;
    }

	vector<int>v;
	int index = 1;
    for (int i = 0; i < of.size_; i++) {
        if (atoi(of.order_data_[i]["stuId"].c_str()) == id) {
            if (of.order_data_[i]["status"] == "1" || of.order_data_[i]["status"] == "2") {

                v.push_back(i);
                cout <<  index ++  << "、 ";
                cout << "预约日期： 周" << of.order_data_[i]["date"];
                cout << " 时段：" << (of.order_data_[i]["interval"] == "1" ? "上午" : "下午");
                cout << " 机房：" << of.order_data_[i]["roomId"];

                string status = " 状态： ";
                if (of.order_data_[i]["status"] == "1") {
                    status +=  "审核中";
                } else if (of.order_data_[i]["status"] == "2") {
                    status += "预约成功";
                } 
                cout << status << endl;
            }
        }
    }

	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			} else {
				//	cout << "记录所在位置： " << v[select - 1] << endl;
				of.order_data_[v[select - 1]]["status"] = "0";
				of.UpdateOrder();
				cout << "已取消预约" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}
}