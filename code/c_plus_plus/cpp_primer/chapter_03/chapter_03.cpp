
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

void ch_03()
{
    /* 3.2 标准库类型 string */
    ch_3_2();
}

/********************************************************************************/
/*****************************************3.2************************************/

void ch_3_2()
{
    /* 3.2.3 处理string对象中的字符 */
    ch_3_2_3();
}


void ch_3_2_3()
{
    string s("Hello World!!!");

    decltype(s.size()) punct_cnt = 0;
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

    /* 进制转换 */
    const string hex_digits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 an 15"
         << " sparated by spaces, Hit ENTER when finished: ";

    string result;
    string::size_type n;
    while (cin >> n)
        if (n < hex_digits.size())
            result += hex_digits[n];
    cout << "You hex number is: " << result;
}

void Homework_3_8()
{
    string s;
    cout << "please enter a series word, include space: ";
    getline(cin, s);

    int i = 0;
    while (s[i] != '\0')
    {
        if (!isspace(s[i]))
            s[i] = 'X';

        ++i;
    }
    cout << s << endl;
    return ;
}

void Homework_3_10()
{
    string s;
    cout << "please enter a series word, include character: ";
    getline(cin, s);

    for (auto c : s)
    {
        if (!ispunct(c))
            cout << c;
    }

    string ret;
    for (decltype(s.size()) i = 0; i != s.size(); ++i)
    {
        if (!ispunct(s[i]))
            ret += s[i];
    }
    cout << ret;
    return;
}

/* 列表初始值还是元素数量 */
void Practice_3_3_1()
{
    //使用了{},但是提供的值不能执行列表初始化-->构造
    vector<string>  v1{10};
    vector<string>  v2{5, "hi"};
    cout << v1.size() << ", " << v2.size() << endl;
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
    //int         iVal;

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
    cout << vInt.size() << endl;

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
    for (auto it = vInt.cbegin(); it <= vInt.cend() - 1; it++)
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
    for (auto it = beg; it != beg + (end - beg) / 2; ++it)
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

void Homework_3_22()
{
    vector<string>  s_vec;
    string          str;

    while (getline(cin, str))
    {
        s_vec.push_back(str);
    }

    for (auto it = s_vec.begin(); it != s_vec.end() && !it->empty(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
            *it2 = toupper(*it2);
        cout << *it << endl;
    }

    //return 0;
}

void Homework_2_23()
{
    vector<int> ivec;
    srand((unsigned)time(NULL));

    for (int i = 0; i != 10; ++i)
    {
        ivec.push_back(rand() % 100);
    }

    cout << "after input: " << endl;
    for (auto cit = ivec.cbegin(); cit != ivec.cend(); ++cit)
    {
        cout << *cit << ' ';
    }
    cout << endl;

    for (auto cit = ivec.cbegin(); cit != ivec.cend(); ++cit)
    {
        cout << *cit * *cit << ' ';
    }
}

void Practice_3_5_1()
{
    /* 字符数组的特殊性 */
    char a[] = "C++";   //最后一个\0
    cout << sizeof (a) / sizeof (*a) << endl;   //strlen

    /* 复杂声明 */
    int arr[10];
    int* parr[10];              //右-->左
    int (*parray)[10] = &arr;   //内-->外
    //int (*parray2)[10] = &arr2;
    int (&rarray)[10] = arr;
    //int (&rarray2)[100] = arr;

    int* (&rparr)[10] = parr;
}

/* 指针和数组 */
void Practice_3_5_3()
{
    int a[] = {10,1,2,3,4,5};
    auto a2(a);     //auto将数组名推断为指针
    cout << *a2 << endl;
    //a2 = 42;

    //decltype推断为数组
    decltype (a) a3 = {1,2,3,4,5,6};
    //a3 = a2;
    a3[1] = 100;
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

void Practice_3_5_5()
{
    string s("Hello");

    const char *str = s.c_str();    //指针赋值（以0结尾）
}

/* 多维数组 */
void Practice_3_6()
{
    //多维数组下标使用: 下标运算符与维度的的关系
    int arr[3][4] = {0};
    int (&rarr)[4] = arr[2];

    int (*parr)[4] = arr;   //数组名转换为指向第一个内层数组指针
    parr = &arr[1];

    int arr2[10][20][30];
    int (*parr2)[20][30] = &arr2[1];
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
    for (ArrayType *p = a; p != a + row; ++p)   //数组名转换为第一个内层数组指针
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


