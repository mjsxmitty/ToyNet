#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void FileRead(const char *InFileName,char *InBuffer)
{
	ifstream ReadFile;
	ReadFile.open(InFileName);
	ReadFile.seekg(0, ios::end);
	int FileLen = ReadFile.tellg();
	ReadFile.seekg(0, ios::beg);
	ReadFile.read(InBuffer, FileLen);
	cout << InBuffer << endl;
	ReadFile.close();
}

bool FileCopy(const char* InCopyFileName, const char* InTargerFileName)
{
	char buffer[4096] = { 0 };
	ifstream iReadFile;
	ofstream wWriteFile;
	iReadFile.open(InCopyFileName);
	wWriteFile.open(InTargerFileName);//没有就创建一个

//	while (iReadFile >> buffer)
	//while (!iReadFile.eof())
	//{
	//	iReadFile >> buffer;
	//	cout << buffer;
	//	wWriteFile << buffer;
	//}
	iReadFile.seekg(0, ios::end);
	int FileLen = iReadFile.tellg();
	iReadFile.seekg(0, ios::beg);
	iReadFile.read(buffer, FileLen);
	wWriteFile << buffer;

	iReadFile.close();
	wWriteFile.close();

	return true;
}

int main()
{
	//cout
//	cout << "Hello" << endl;//输入
	//cin; //输出
	//cout
	//cerr;//
	//clog;//
	char buffer[1024] = { 0 };
	//cin.getline(buffer, 1024);//可以输出带空格的
//	cin >> buffer;//输入的是一个连续的 
//	cout << buffer << endl;
	//什么是输入和输出
	//IO
//	cerr << "asdasdasd asdasd Error" << endl;//非缓存

	//clog << "Hello Log" << endl;
	//cout
	//cerr
	//clog

	cout << "cout Text" << endl;
	cerr << "Error" << endl;
	clog << "LOG LOG" << endl;

	//iostream
	//fstream

	//ofstream
	//ifstream
	//fstream

	//ofstream file;
	//file.open("xxx.txt",ios::app);//创建一个

	//cout << "开始写入信息" << endl;
	//cin.getline(buffer, 1024);
	//file << buffer << endl;

	//file.close();

	//ifstream ReadFile;
	//ReadFile.open("xxx.txt");

	////读取一行 以 endl结尾
	//cout << "开始读取信息" << endl;
	//ReadFile >> buffer;
	//cout << buffer << endl;

	////读取完整的策略
	//char buffer2[1024] = { 0 };
	//ReadFile.seekg(0, ios::end);
	//int FileLen = ReadFile.tellg();
	//ReadFile.seekg(0, ios::beg);
	//ReadFile.read(buffer2, FileLen);
	//cout << buffer2 << endl;
	//ReadFile.close();

	//ios::app +
	//ios::ate
	//ios::in  r
	//ios::out w
	//ios::trunc
	//ios::out | ios::app w+
	//ios::in  | ios::out r+
	//fstream file1;
	//file1.open("xxx.txt",ios::out | ios::app); //w+
	////file1 << "weraw"<<endl;
	////file1 << "ca"<<endl;

	//file1 >> buffer;
	//cout << buffer << endl;
	//file1.close();

	//char buffer4[1024] = { 0 };
	//FileRead("xxx.txt", buffer4);

//	FileCopy("Source.cpp","SourceXXXXXX.cpp");
	cout << setiosflags(ios::left | ios::showpoint);  // 设左对齐，以一般实数方式显示
	cout.precision(5);       // 设置除小数点外有五位有效数字 
	cout << 34123.456789 << endl;
	cout.width(10);          // 设置显示域宽10 
	cout.fill('*');          // 在显示区域空白处用*填充
	cout << resetiosflags(ios::left);  // 清除状态左对齐
	cout << setiosflags(ios::right);   // 设置右对齐
	cout << 123.456789 << endl;
	cout << setiosflags(ios::left | ios::fixed);    // 设左对齐，以固定小数位显示
	cout.precision(3);    // 设置实数显示三位小数
	cout << 999.123456 << endl;
	cout << resetiosflags(ios::left | ios::fixed);  //清除状态左对齐和定点格式
	cout << setiosflags(ios::left | ios::scientific);    //设置左对齐，以科学技术法显示 
	cout.precision(3);   //设置保留三位小数
	cout << 123.45678 << endl;
	system("pause");
	return 0;
}