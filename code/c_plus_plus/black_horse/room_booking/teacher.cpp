
#include "order_file.h"
#include "teacher.h"
#include <iostream>
#include <vector>

using namespace std;

Teacher::Teacher(/* args */)
{
}

Teacher::Teacher(int id, std::string name, std::string pwd)
{
    this->id = id;
    name_ = name;
    passwd_ = pwd;
}
void Teacher::OperateMenu()
{
	cout << "欢迎教师：" << name_ << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


void Teacher::ShowAllOrder()
{
	OrderFile of;
	if (of.size_ == 0) {
		cout << "无预约记录" << endl;
		return;
	}

	for (int i = 0; i < of.size_; i++) {
		cout << i + 1 << "、 ";

		cout << "预约日期： 周" << of.order_data_[i]["date"];
		cout << " 时段：" << (of.order_data_[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.order_data_[i]["stuId"];
		cout << " 姓名：" << of.order_data_[i]["stuName"];
		cout << " 机房：" << of.order_data_[i]["roomId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.order_data_[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.order_data_[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.order_data_[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
}

//审核预约
void Teacher::ValidOrder()
{
	OrderFile of;
	if (of.size_ == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.size_; i++)
	{
		if (of.order_data_[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、 ";
			cout << "预约日期： 周" << of.order_data_[i]["date"];
			cout << " 时段：" << (of.order_data_[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.order_data_[i]["roomId"];
			string status = " 状态： ";  // 0取消的预约   1 审核中   2 已预约  -1 预约失败
			if (of.order_data_[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.order_data_[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.order_data_[v[select - 1]]["status"] = "-1";
				}
				of.UpdateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
}