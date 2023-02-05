
/**
 * CPP风格IO
 */

#ifndef __CPP_CH_6_HPP__
#define __CPP_CH_6_HPP__

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string.h>

#include "chapter_06.h"

using namespace std;

namespace chapter_06
{

void ch_6()
{
    char    buffer[1024] = {0};

    /* 基本的输入和输出 */
    {
        //cin >> buffer;
        cin.getline(buffer, 1024);

        cout << buffer << endl;
        cerr << buffer << endl;
        clog << buffer << endl;
    }

    /* CPP风格文件读写 */
    {
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

    /* 文件拷贝 */
    {
        FileCopy("test.txt", "copy.txt");
    }

}

}

#endif // __CPP_CH_6_HPP__
