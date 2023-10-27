
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string.h>
#include "chapter_06.h"

using namespace std;

namespace chapter_06
{
void Test1()
{
    char    buffer[1024] = {0};
    //cin >> buffer;
    cin.getline(buffer, 1024);

    cout << buffer << endl;
    cerr << buffer << endl;
    clog << buffer << endl;
}

void Test2()
{
    char    buffer[1024] = {0};
    ofstream out_file;
    out_file.open("test.txt", ios::app);

    cout << "please enter a serise info: ";
    cin.getline(buffer, 1024);
    out_file << buffer;

    ifstream in_file;
    in_file.open("test.txt", ios::in);
//        in_file >> buffer;
//        cout << buffer << endl;

    // 读取完整的
    char    buffer1[1024] = {0};
    memset(buffer1, 0, 1024);
    in_file.seekg(0, ios::end);
    int content_len = in_file.tellg();
    in_file.seekg(0, ios::beg);
    in_file.read(buffer1, content_len);
    cout << buffer1 << endl;

    out_file.close();
    in_file.close();
}

bool FileCopy(const char *in_file_name, const char *out_file_name)
{
    char buff[1024] = {0};
    ifstream in_file;
    ofstream out_file;

    in_file.open(in_file_name);
    out_file.open(out_file_name);

    in_file.seekg(0, ios::end);
    int file_len = in_file.tellg();
    in_file.seekg(0, ios::beg);
    in_file.read(buff, file_len);

    out_file << buff;

    in_file.close();
    out_file.close();

    return true;
}

void Test3()
{
    FileCopy("test.txt", "copy.txt");
}

}
