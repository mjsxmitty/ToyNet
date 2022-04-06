#include <iostream>
#include "Mysql/mysql.h"

#pragma comment(lib,"libmysql.lib")

using namespace std;

const char user[] = "root";
const char pswd[] = "root";
const char host[] = "localhost";
//const char host[] = "127.0.0.1";
const char table[] = "hellohello";
unsigned int port = 3306;

int main()
{
	MYSQL mysql;
	MYSQL_RES* Result = nullptr;
	MYSQL_ROW mysql_row;
	int ret = 0;

	mysql_init(&mysql);
	if (mysql_real_connect(&mysql,host,user,pswd,table,port,nullptr,0))
	{
		//select * from user;
		ret = mysql_query(&mysql,"select * from user;");
		if (ret == 0)
		{
			Result = mysql_store_result(&mysql);
			if (Result)
			{
				while (mysql_row = mysql_fetch_row(Result))
				{
					cout << "|ID	:" << mysql_row[1];
					cout << "|Name  :" << mysql_row[0];
					cout << "|age	:" << mysql_row[2];
					cout << endl;
				}
			}
		}
		else
		{
			cout << "Ê§°Ü" << endl;
		}
	}

	if (Result != nullptr)
	{
		mysql_free_result(Result);
	}

	mysql_close(&mysql);

	return 0;
}