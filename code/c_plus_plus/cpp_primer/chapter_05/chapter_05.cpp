

#include "chapter_05.h"
#include <string>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void Chapter_05()
{
    Practice_5_3_2();
    //Homework_5_12();
    //Homework_5_14();
    //Homework_5_20();
    //Homework_5_21();
    //Homework_5_24();
    //Homework_5_25();
}

/* switch语句 */
void Practice_5_3_2()
{
    /* 不允许跨过变量 初始化语句 直接跳转到变量作用域的另一位置*/
    bool flag = false;
    switch (flag)
    {
        case true:
            //string name;
            //int i = 10;
            int ival;
            break;
        case false:
        {
            ival = 100;
            cout << ival << endl;
        }
        break;
    }
}
void Homework_5_12()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, pref = '\0';

    cout << "请输入测试数据: " << endl;
    while (cin >> ch)
    {
        bool b1 = true;
        if (pref == 'f')
            switch (ch)
            {
                case 'f':
                    ++ffCnt;
                    b1 = false;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }

        if (b1)
            pref = ch;
        else
            pref = '\0';
    }

    cout << "ff的数量: " << ffCnt << endl;
    cout << "fl的数量: " << flCnt << endl;
    cout << "fi的数量: " << fiCnt << endl;

    return ;
}

void Homework_5_14()
{
    string  current_str, pre_str = "", max_str;
    int     current_cnt = 1, max_cnt = 0;

    while (cin >> current_str)
    {
        if (current_str == pre_str)
        {
            ++current_cnt;
            if (current_cnt > max_cnt)
            {
                max_cnt = current_cnt;
                max_str = current_str;
            }
        }
        else
            current_cnt = 1;

        pre_str = current_str;
    }

    if (max_cnt > 1)
        cout << "max str: " << max_str << ", occur count: " << max_cnt << endl;
    else
        cout << "each word occur once times." << endl;
}

void Homework_5_20()
{
    string  current_str, pre_str = " ";
    bool b1 = true;

    cout << "请输入一组字符串: ";
    while (cin >> current_str)
    {
        if (current_str == pre_str)
        {
            b1 = false;
            cout << "连续出现的字符串是: " << current_str << endl;
            break;
        }

        pre_str = current_str;
    }

    if (b1)
        cout << "没有出现连续的字符串!" << endl;

    return ;
}

void Homework_5_21()
{
    string  current_str, pre_str = " ";
    bool b1 = true;

    cout << "请输入一组字符串: ";
    while (cin >> current_str)
    {
        if (!isupper(current_str[0]))
            continue;

        if (current_str == pre_str)
        {
            b1 = false;
            cout << "连续出现的字符串是: " << current_str << endl;
            break;
        }

        pre_str = current_str;
    }

    if (b1)
        cout << "没有出现连续的字符串!" << endl;

    return ;
}

void Homework_5_24()
{
    cout << "请输入除数和被除数: ";
    int val1, val2;
    cin >> val1 >> val2;

    if (val2 == 0)
        throw std::runtime_error("除数为0");
    return ;
}

void Homework_5_25()
{
    int val1, val2;

    cout << "请输入除数和被除数: ";
    while (cin >> val1 >> val2)
    {
        try {
            if (val2 == 0)
                throw std::runtime_error("除数为0");
            cout << "结果是: " << val1 / val2 << endl;
        } catch (std::runtime_error e) {
            cout << e.what() << endl;
            cout << "继续(y/n)?";
            char ch;
            cin >> ch;
            if (ch != 'y' && ch != 'Y')
                break;
        }
    }

    return ;
}
