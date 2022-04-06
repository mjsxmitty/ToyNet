
#include "chapter_03.h"

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

const int NUM = 100;

void Chapter_03()
{
    //Practice_3_2_3();
    Practice_3_3_3();
    //Homework_20();
    //Practice_3_4_1();
    //Practice_3_5_4();
    //Homework43_44_45();
}

//处理string单个字符
void Practice_3_2_3()
{
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;

    //标点符号
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;

    cout << punct_cnt << " punctuation characters in " << s << endl;

    //转换大写
    string orig = s;
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

    s = orig;
    decltype(s.size()) index = 0;
    while (index != s.size() && !isspace(s[index]))
    {
        s[index] = toupper(s[index]);
        ++index;
    }
    cout << s << endl;
}

//计算索引
void Practice_3_3_3()
{
    vector<unsigned>    grades;
    unsigned            grade;
    unsigned            scores[11] = {};
    srand((unsigned)time(NULL));

    auto it = begin(scores);
    do
    {
        grade = rand() % 1000;
        if (grade < 101)
        {
            grades.push_back(grade);
            ++*(it + grade / 10);
        }
    } while (grades.size() != 11);
    
    // while (grades.size() != 11)
    // {
    //     grade = rand() % 1000;
    //     if (grade <= 100)
    //     {
    //         ++scores[grade / 10];
    //         grades.push_back(grade);
    //     }
    // }    
    cout << "grades size: " << grades.size() << endl;

    cout << "grades: ";
    for (auto g : grades)
        cout << g << " " ;
    cout << endl;

    cout << "scores: ";
    for (auto i : scores)
        cout << i << " ";
    cout << endl;
}

void Homework_20()
{
    vector<int> vInt;
    int         iVal;

    srand((unsigned) time(NULL));
    unsigned arr_size;
    cout << "请输入数组随即数组的大小: ";
    cin >> arr_size;

    unsigned index = 0; 
    while (index < arr_size)
    {
        vInt.push_back(rand() % NUM);
        index++;
    }

    if (vInt.empty())
    {
        cout << "容器内没有元素!" << endl;
        return;
    }

    cout << "随机数组元素为: " << endl;
    for (const auto &item : vInt)
    {
        cout << item << " ";
    }
    cout << endl;

    cout << "相邻两项的和依次是: " << endl;
    // for (decltype (vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    // {
    //     cout << vInt[i] + vInt[i + 1] << " ";
    //     if ((i + 2) % 10 == 0)
    //         cout << endl;
    // }
    for (auto it = vInt.begin(); it != vInt.end() - 1; ++it)
    {
        cout << (*it + *(++it)) << " ";
        if ((it - vInt.cbegin() + 1) % 10 == 0)
            cout << endl;
    }

    if (vInt.size() % 2 != 0)
        //cout << vInt[vInt.size() - 1];
        cout << *(vInt.cend() - 1);
    cout << endl;

    cout << "首尾和依次是: " << endl;
    // for (decltype (vInt.size()) i = 0; i < vInt.size() / 2; i++)
    // {
    //     cout << vInt[i] + vInt[vInt.size() - 1 - i] << " ";
    //     if ((i + 1) % 5 == 0)
    //         cout << endl;
    // }
    auto beg = vInt.begin();
    auto end = vInt.end();
    for (auto it = beg; it != end; ++it)
    {
        cout << (*it + *(beg + (end - it) - 1)) << " ";
        if ((it - beg + 1) % 5 == 0)
            cout << endl;
    }

    //奇数个
    if (vInt.size() % 2 != 0)
        //cout << vInt[vInt.size() / 2];
        cout << *(beg + (end - beg) / 2);
    cout << endl;

    return;
}

//使用迭代器
void Practice_3_4_1()
{
    string str("some string"), orig = str;
    if (!str.empty())
        cout << "the end character in str: " << str << " is " << str[str.size() -1] << endl;

    //使用索引
    if (!str.empty())
        str[0] = toupper(str[0]);
    cout << "assign a new value to the first character in str: " << str << " is " << str[0] << endl;

    str = orig;
    if (str.begin() != str.end())
    {
        auto it = str.begin();
        *it = toupper(*it);
    }
    cout << "assign a new value to the first character in str: " << str << " is " << str[0] << endl;

    str = orig;
    for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
            str[index] = toupper(str[index]);
    cout << "decltype for loop assign a new value to str: " << str  << endl;

    str = orig;
    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << "auto for loop assign a new value to str: " << str  << endl;

    str = orig;
    decltype(str.size()) index = 0;
    while (index != str.size() && !isspace(str[index]))
    {
        str[index] = toupper(str[index]);
        ++index;
    }
    cout << "decltype while loop assign a new value to str: " << str  << endl;

    auto beg = str.begin();
    while (beg != str.end() && !isspace(*beg))
    {
        *beg = toupper(*beg);
        ++beg;
    }
    cout << "auto while loop assign a new value to str: " << str  << endl;

    str = orig;
    cout << "range for loop print str: " << str  << endl;
    for (auto c : str)
        cout << c << endl;

    for (auto &c : str)
        c = '*';
    cout << "range for loop assign a new value to str: " << str  << endl;

    str = orig;
    cout << "decltype for loop print str: " << str  << endl;
    for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
        cout << str[ix] << endl;

    for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
        str[ix] = '*';
    cout << "decltype for loop assign a new value to str: " << str  << endl;

    str = orig;
    cout << "auto for loop print str: " << str  << endl;
    for (auto beg = str.begin(); beg != str.end(); ++beg)
        cout << *beg << endl;

    for (auto beg = str.begin(); beg != str.end(); ++beg)
        *beg = '*';
    cout << "auto for loop assign a new value to str: " << str  << endl;
}

//C风格字符串
void Practice_3_5_4()
{
    string s1 = "A string example";
    string s2 = "A different string";

    if (s1 < s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;
    string large_string = s1 + s2;
    cout << "change after str: " << large_string << endl;

    const char ca1[] = "A string example";
    const char ca2[] = "A different string";

    if (strcmp(ca1, ca2) < 0)
    {
        cout << ca1 << " " << strlen(ca1) << endl;
    }
    else
    {
        cout << ca2 << " " << strlen(ca2) << endl;
    }

    const unsigned sz = strlen(ca1) + strlen(ca2) + 2;
    char large_str[sz];
    strcpy(large_str, ca1);
    strcat(large_str, " ");
    strcat(large_str, ca2);
    cout << "change after str: " << large_str << endl;

    strncpy(large_str, ca1, sz);
    if (strlen(ca1) > sz)
        large_str[sz - 1] = '\0';
    strncat(large_str, " ", 2);
    strncat(large_str, ca2, sz - strlen(large_str));
    cout << "change after str: " << large_str << endl;
}

void Homework_43_44_45()
{
    constexpr size_t row = 3;
    constexpr size_t col = 4;
    int a[row][col];

    srand((unsigned) time(NULL));
    for (size_t i = 0; i != row; ++i)
    {
        for (size_t j = 0; j != col; ++j)
        {
            a[i][j] = rand() % NUM;
        }
    }

    // for (size_t i = 0; i < row; i++)
    // {
    //     for (size_t j = 0; j < col; j++)
    //     {
    //         a[i][j] = i * col + j;     
    //     }
    // }
    

    cout << "使用c11 for: " << endl;
    for (int (&ch1)[4] : a)
    {
        for (int &ch2 : ch1)
            cout << ch2 << " ";
        cout << endl;
    }

    cout << "使用普通for: " << endl;
    for (size_t i = 0; i != row; ++i)
    {
        for (size_t j = 0; j != col; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "使用普通for和指针: " << endl;
    for (int (*p)[4] = a; p != a + row; ++p)
    {
        for (int *q = *p; q != *p + col; ++q)
            cout << *q << " ";
        cout << endl;
    }

    //using ArrayType = int[4];
    typedef int ArrayType[4];

    cout << "使用类型别名和引用: " << endl;
    for (ArrayType &i : a)
    {
        for (int &j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << "使用类型别名和指针: " << endl;
    for (ArrayType *p = a; p != a + row; ++p)
    {
        for (int *q = *p; q != *p + col; ++q)
            cout << *q << " ";
        cout << endl;
    }

    cout << "使用auto和引用: " << endl;
    for (auto &i : a)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << "使用auto和指针: " << endl;
    for (auto p = a; p != a + row; ++p)
    {
        for (auto q = *p; q != *p + col; ++q)
            cout << *q << " ";
        cout << endl;
    }

    cout << "使用函数: " << endl;
    //for (ArrayType *p = begin(a); p != end(a); ++p)
    for (auto p = begin(a); p != end(a); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << " ";
        std::cout << std::endl;
    }
    
}
