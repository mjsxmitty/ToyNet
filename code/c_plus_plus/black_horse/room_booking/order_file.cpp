

#include "order_file.h"
#include "global.hpp"

#include <fstream>

using namespace std;

OrderFile::OrderFile()
{
    size_ = 0;

    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId &&  ifs >> status) {
        string key, value;
        map<string, string> temp;

        int pos = date.find(":");
        if (pos != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }
        
        pos = interval.find(":");
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }

        pos = stuId.find(":");
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }

        pos = stuName.find(":");
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }

        pos = roomId.find(":");
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            temp.insert(make_pair(key, value));
        }

        order_data_.insert(make_pair(size_, temp));
        size_++;
    }

    ifs.close();
}

void OrderFile::UpdateOrder()
{
    if (size_ == 0) {
        return ;
    }
    
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < size_; i++) {
		ofs << "date:" << order_data_[i]["date"] << " ";
		ofs << "interval:" << order_data_[i]["interval"] << " ";
		ofs << "stuId:" << order_data_[i]["stuId"] << " ";
		ofs << "stuName:" << order_data_[i]["stuName"] << " ";
		ofs << "roomId:" << order_data_[i]["roomId"] << " ";
		ofs << "status:" << order_data_[i]["status"] << endl;
    }
    ofs.close();
}
