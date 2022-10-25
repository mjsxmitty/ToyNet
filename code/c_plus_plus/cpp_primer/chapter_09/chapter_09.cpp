

#include "chapter_09.h"
#include "../lib_util/sales_data.h"
#include "../chapter_07/gz_sales_data.h"

#include <forward_list>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <fstream>
#include <array>
#include <queue>

using namespace std;

void ch_09()
{
    /* 容器库概览 */
    ch_9_2();
    //Practice_9_2();
    //Homework_9_2();
    //Homework_9_4_5();
    //Homework_9_16();

    //Practice_9_3_1();
    //Practice_9_3_2();
    //Practice_9_3_3();
    //Practice_9_3_4();
    //Practice_9_3_6();
    //Homework_9_27();
    //Homework_9_28();
    //Practice_9_3_5();
    //Homework_9_31();

    //Practice_9_4();
    //Homework_9_39();

    //Practice_9_5_1();
    //Practice_9_5_2();
    //Practice_9_5_3();
    //Practice_9_5_5();
    //Homework_9_43();
    //Homework_9_47_48_49();

    //Practice_9_6();
    //Homework_9_50();
}

void ch_9_2()
{
    /* 容器定义和初始化 */
    //ch_9_2_4();

    /* 赋值和swap */
    ch_9_2_5();
}

void ch_9_2_4()
{
    // 将一个容器初始化为另一个容器的拷贝
    vector<const char *> cstr = {"aaa", "bbb", "c"};        // 列表初始化
    forward_list<string> flstr(cstr.begin(), cstr.end());   // 传递范围

    for_each(cstr.begin(), cstr.end(), [](const string &s){ cout << s << ' ';});
    cout << endl;
    for_each(flstr.begin(), flstr.end(), [](const string &s){ cout << s << ' ';});
    cout << endl << endl;

    // 标准array具有固定大小
    int arr[10] = {1,2,3,4};
    for_each(begin(arr), end(arr), [](int i){ cout << i << ' ';});
    cout << endl << endl;
    //int cpy[10] = arr;

    array<int, 10> digits = {1,2,3,4,5};
    //array<int, 5>   copy = digits;  //error大小不同
    array<int, 10> copy = digits;
    copy = digits;
//    copy = {0,1,2,3,4,5,6,7,8};
//    for_each(copy.begin(), copy.end(), [](int i){ cout << i << ' ';});
//    cout << endl << endl;

    array<string, 10> copy2;
    //copy2 = digits;
}

void ch_9_2_5()
{
    list<string>        names;
    vector<const char*> old_style;
    //names = old_style;
    names.assign(old_style.begin(), old_style.end());   // 类型相容
    names.assign(10, "yyy");                            // 第二个版本

//    vector<int> temp_vec(10);
//    old_style.assign(temp_vec.begin(), temp_vec.end());

    vector<string> svec1(5, "hi");
    vector<string> svec2(10, "Hello");
    auto it1 = svec1.begin() + 2, it2 = svec2.begin() + 2;
    cout << svec1.size() << ", " << svec2.size() << endl;
    cout << *it1 << ", " << *it2 << endl;
    swap(svec1, svec2);
    cout << svec1.size() << ", " << svec2.size() << endl;
    cout << *it1 << ", " << *it2 << endl;           // 指向交换之后的容器

}

bool SearchVec(vector<int>::iterator beg,
               vector<int>::iterator end,
               int val)
{
    for (; beg != end; ++beg)
        if (*beg == val)
            return true;

    return false;
}

vector<int>::iterator SearchVec2(vector<int>::iterator beg,
                                 vector<int>::iterator end,
                                 int val)
{
    for (;beg != end; ++beg)
        if (*beg == val)
            return beg;

    return end;
}

void Homework_9_2()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    cout << SearchVec(ivec.begin(), ivec.end(), 0) << endl;
    cout << SearchVec(ivec.begin(), ivec.end(), 3) << endl;

    cout << (SearchVec2(ivec.begin(), ivec.end(), 0) == ivec.end()) << endl;
    cout << (SearchVec2(ivec.begin(), ivec.end(), 8) == ivec.end()) << endl;
}

void Homework_9_4_5()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    cout << SearchVec(ivec.begin(), ivec.end(), 3) << endl;
    cout << SearchVec(ivec.begin(), ivec.end(), 10) << endl;

    cout << SearchVec2(ivec.begin(), ivec.end(), 6) - ivec.begin() << endl;
    cout << SearchVec2(ivec.begin(), ivec.end(), 10) - ivec.begin() << endl;
}

bool VLEqual(const vector<int> &v, const list<int> &l)
{
    if (v.size() != l.size())
        return false;

    auto vb = v.begin(), ve = v.end();
    auto lb = l.begin();
    for (; vb != ve; ++vb, ++lb)
        if (*vb != *lb)
            return false;

    return true;
}

void Homework_9_16()
{
    vector<int> ivec    = {0,1,2,3,4,5,6,7,8,9};
    list<int>   ilist   = {0,1,2,3,4,5,6,7,8,9};
    list<int>   ilist2  = {0,1,2,3,4,5,6,7};
    list<int>   ilist3  = {0,1,2,3,4,5,6,7,7,9};

    cout << VLEqual(ivec, ilist) << ", "
         << VLEqual(ivec, ilist2) << ", "
         << VLEqual(ivec, ilist3)
         << endl;
}

/***************************************************************/
/***************************9.3*********************************/

/*
 * vector, list, deque, forward_list, array, string
 *
 * push_back     --->    vector,    list,       deque,      string
 * push_front    --->    list,      deque,      forward_list
 * insert        --->    vector,    list,       deque,      string
 */

void ch_9_3()
{
    /* 向容器中添加元素 */
    Practice_9_3_1();

    /* 访问元素 */
    Practice_9_3_2();
}

void PrintVec(const vector<int> &vi)
{
    auto iter = vi.begin();
    while (iter != vi.end())
        cout << *iter++ <<  " ";
}

void Practice_9_3_1()
{
    // 容器中特定位置添加元素
    list<int>   ilist = {1,2,3,4,5};
    vector<int> ivec;

    ivec.insert(ivec.begin(), ilist.begin(), ilist.end());
    PrintVec(ivec);
    cout << endl;
    //ivec.push_front(1);

    // 插入范围元素
    ivec.insert(ivec.begin(), 3, 0);
    PrintVec(ivec);
    cout << endl;
    // 初始化列表
    ivec.insert(ivec.begin(), {7,8,9});
    PrintVec(ivec);
    cout << endl;

//    ivec.insert(ivec.begin(), ivec.begin(), ivec.end());  // error
//    PrintVec(ivec);
//    cout << endl;

    // 使用insert返回值
    int num = 3;
    auto iter = ivec.begin();
    while (num)
    {
        iter = ivec.insert(iter, num);
        --num;
    }
    PrintVec(ivec);
    cout << endl;

    // 使用emplace操作
    list<GZSalesData> sales_data_list;
    sales_data_list.emplace_front("test", 1, 2);
    sales_data_list.emplace_back("test1", 2, 3);
    sales_data_list.emplace(sales_data_list.begin(), "test2", 2, 3);

    vector<GZSalesData> sales_data_vec;
    sales_data_vec.push_back(GZSalesData("test1", 2, 3));
}

/* 9.3.2 访问元素 */
void Practice_9_3_2()
{
    list<string>   slist = {"aaa", "abc", "123"};
    if (!slist.empty()) // 确保非空
    {
        auto val = *slist.begin(), val2 = slist.front();

        auto last = slist.end();
        auto val3 = *(--last);
        auto val4 = slist.back();
    }

    // 访问成员函数返回的是引用
    if (!slist.empty())
    {
        slist.front() = "zzz";
        for_each(slist.begin(), slist.end(), [](const string &s){ cout << s << ' ';});
        cout << endl;

        auto &v1 = slist.back();
        v1 = "456";
        for_each(slist.begin(), slist.end(), [](const string &s){ cout << s << ' ';});
        cout << endl;

        auto v2 = slist.back();
        v2 = "789";
        for_each(slist.begin(), slist.end(), [](const string &s){ cout << s << ' ';});
        cout << endl;
    }

    // 下标操作和安全的随机访问
    vector<int> ivec;
    //cout << ivec[0] << endl;
    try {
        cout << ivec.at(0) << endl;
    } catch (out_of_range &s) {
        cout << "exception!!!" << endl;
        cout << s.what() << endl;
    }

}

/* 9.3.3 删除元素*/
void Practice_9_3_3()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    cout << "init elements from lst: ";
    for_each(lst.begin(), lst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    // 从容器内部删除一个元素
    auto it = lst.begin();
    while (it != lst.end())
    {
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;
    }
    cout << "after erasing odd elements from lst: ";
    for_each(lst.begin(), lst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    /* 删除多个元素 */
    lst.erase(++(++lst.begin()), lst.end());
    cout << "after erasing from lst: ";
    for_each(lst.begin(), lst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    //lst.erase(lst.begin(), lst.end());
    lst.clear();
    cout << "after clear elems from lst: ";
    for_each(lst.begin(), lst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;
}

/* 9.3.4 特殊的forward_list操作 */
void Practice_9_3_4()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};

    cout << "initial list: ";
    for_each(flst.begin(), flst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2 == 0)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    cout << "after erasing elements from flst: ";
    for_each(flst.begin(), flst.end(), [](int &i){ cout << i << ' ';});
    cout << endl;
}

void Homework_9_27()
{
    forward_list<int> iflist = {1,2,3,4,5,6,7,8,9};
    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while (curr != iflist.end())
    {
        if (*curr & 1)
            curr = iflist.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    cout << "after erasing elements from flst: ";
    for_each(iflist.begin(), iflist.end(), [](int &i){ cout << i << ' ';});
    cout << endl;
}

void FLInsert(forward_list<string> &sflist,
              const string &s1, const string &s2)
{
    auto prev = sflist.before_begin();
    auto curr = sflist.begin();
    bool insert = false;

    while (curr != sflist.end())
    {
        if (*curr == s1)
        {
            curr = sflist.insert_after(curr, s2);
            insert = true;
        }

        prev = curr;
        ++curr;
    }

    if (!insert)
        sflist.insert_after(prev, s2);
}


void Homework_9_28()
{
    forward_list<string> sflist = {"hello", "!", "world", "!"};
    FLInsert(sflist, "!", "***");

    for_each(sflist.begin(), sflist.end(), [](const string &s){ cout << s << ' ';});
    cout << endl;
}

/* 9.3.5 改变容器大小 */
void Practice_9_3_5()
{
    list<int> ilist(10, 42);
    for_each(ilist.begin(), ilist.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    ilist.resize(15);
    for_each(ilist.begin(), ilist.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    ilist.resize(20, 100);
    for_each(ilist.begin(), ilist.end(), [](int &i){ cout << i << ' ';});
    cout << endl;

    ilist.resize(3);
    for_each(ilist.begin(), ilist.end(), [](int &i){ cout << i << ' ';});
    cout << endl;
}

/* 9.3.6 容器操作可能使迭代器失效 */
void Practice_9_3_6()
{
    // 编写改变容器的循环程序
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};

    auto iter = ivec.begin();
    while (iter != ivec.end())
    {
        if (*iter % 2)
        {
            iter = ivec.insert(iter, *iter);
            iter += 2;
        }
        else
        {
            iter = ivec.erase(iter);
        }
    }

    for_each(ivec.begin(), ivec.end(), [](int i){cout << i << endl;});

    // 不要保存end() 返回的迭代器
    auto begin = ivec.begin();
    //auto end = ivec.end();
    while (begin != ivec.end())
    {
        ++begin;
        begin = ivec.insert(begin, 42);
        ++begin;
        //++begin;
    }
    for_each(ivec.begin(), ivec.end(), [](int i){cout << i << endl;});
}


// 删除偶数元素,复制奇数元素
void Homework_9_31()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};

    list<int> ilist(ivec.begin(), ivec.end());
    auto iter = ilist.begin();
    while (iter != ilist.end())
    {
        if (*iter & 1)
        {
            iter = ilist.insert(iter, *iter);
            //iter += 2;
            ++iter;
            ++iter;
        }
        else
        {
            iter = ilist.erase(iter);
        }
    }
    cout << "============list=================" << endl;
    for_each(ilist.begin(), ilist.end(), [](int i){cout << i << endl;});

    forward_list<int> iflist(ivec.begin(), ivec.end());
    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while (curr != iflist.end())
    {
        if (*curr & 1)
        {
            curr = iflist.insert_after(curr, *curr);
            prev = curr;
            curr++;
        }
        else
        {
            curr = iflist.erase_after(prev);
        }
    }
    cout << "============forward list=================" << endl;
    for_each(iflist.begin(), iflist.end(), [](int i){cout << i << endl;});
}

/*****************************************************************/
/***************************9.4*********************************/

//vector对象是如何增长的
void Practice_9_4()
{
    vector<int> ivec;
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    for (vector<int>::size_type ix = 0; ix != 10; ++ix)
        ivec.push_back(ix);
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    //ivec.reserve(25);
    ivec.reserve(5);
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    //判断条件
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    ivec.push_back(1);
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    ivec.shrink_to_fit();
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;
}

void Homework_9_39()
{
    vector<int> ivec;
    ivec.reserve(100);
    size_t num = 101;
    for (size_t i = 0; i != num; ++i)
        ivec.push_back(i);

    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;

    ivec.resize(ivec.size() + ivec.size() / 2);
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity()
         << endl;
}

/***************************************************************/
/***************************9.5*********************************/

/* 9.5.1 构造string的其他方法 */
void Practice_9_5_1()
{
    string s("hello world");
    const char *sp = "nihao!!!!";
    const char ssp[] = {'n', 'i'};

    string s1(sp);
    string s2(sp, 2);
    string s3(ssp, 1);
//    string s4(ssp);
    string s5(s, 3);
    string s6(s, 3, 5);
    cout << "s1 = " << s1 << endl
         << "s2 = " << s2 << endl
         << "s3 = " << s3 << endl
//         << s4 << endl
         << "s5 = " << s5 << endl
         << "s6 = " << s6 << endl;

    try {
        cout << s.substr(1,6) << endl;
        cout << s.substr(6) << endl;
        cout << s.substr(6, 11) << endl;
//        cout << s.substr(12) << endl;
//        cout << s.substr(7,100) << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
        cout << "out of range." << endl;
    }
}

/* 9.5.2 改变string的其他方法 */
void Practice_9_5_2()
{
    string s = "Hello World";

    //insert 下标操作
    s.insert(s.size(), 3, '!');
    cout << s << endl;
    s.insert(5, 1, '*');
    cout << s << endl;

    // erase
    s.erase(s.size() - 5, 2);
    cout << s << endl;
    s.erase(0, 1);
    cout << s << endl;

    // assgin
    string s1 ="hello";
    const char *cp = "Stately, plump Buck";
    s.assign(cp + 7, 7);
    cout << s << endl;

    s = "C++ Primer";
    string s2 = s;
    s.insert(s.size(), " 4th Ed.");
    cout << s << endl;
    s2.append(" 4th Ed.");
    cout << s << endl;
    s.erase(11, 3);
    cout << s << endl;
    s.insert(11, "5th");
    cout << s << endl;
    s.replace(11, 3, "ooo");
    cout << s << endl;

    s2 = "C++ Primer 5th Ed.";
    auto pos = s2.find("5th");
    if (pos != string::npos)
        s2.replace(11, 3, string("Fifth"));
    else
        cout << "no find appoint strings." << endl;
    cout << s2 << endl;
}

void ReplaceStr(string &s, const string &old_val, const string &new_val)
{
//    if (s.empty())
//        return;

//    auto iter = s.begin();
//    while (iter != s.end())
//    {
//        auto iter1 = iter;
//        auto iter2 = old_val.begin();

//        while (iter2 != old_val.end() && *iter1 == *iter2)
//        {
//            ++iter1;
//            ++iter2;
//        }

//        if (iter2 == old_val.end())
//        {
//            iter = s.erase(iter, iter1);
//            if (!new_val.empty())
//            {
//                iter2 = new_val.end();
//                do
//                {
//                    --iter2;
//                    iter = s.insert(iter, *iter2);
//                } while (iter2 > new_val.begin());

//                iter += new_val.size();
//            }
//        }
//        else
//            ++iter;
//    }

    size_t p = 0;
    while ((p = s.find(old_val, p)) != string::npos)
    {
        s.replace(p, old_val.size(), new_val);
        p += new_val.size();
    }
}


void Homework_9_43()
{
    string s = "tho thru tho";
    ReplaceStr(s, "tho", "thought");
    cout << s << endl;

    s = "tho thru tho";
    ReplaceStr(s, "thru", "thought");
    cout << s << endl;

    ReplaceStr(s, "thought", "");
    cout << s << endl;
}

/* 9.5.3 string的搜索操作 */
void Practice_9_5_3()
{
    string numbers("0123456789"), name("r9d2");
    auto pos = name.find_first_of(numbers);
    if (pos != string::npos)
        cout << "found number at index: " << pos
             << " element is " << name[pos] << endl;
    else
        cout << "no number in: " << name << endl;

    //pos = name.find_first_not_of(numbers);
    pos = name.find_last_not_of(numbers);
    if (pos != string::npos)
        cout << "found elem at index: " << pos
             << " element is " << name[pos] << endl;
    else
        cout << "no number in: " << name << endl;

    // 指定哪里搜索
    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        cout << "found number at index: " << pos
             << " element is " << name[pos] << endl;
        ++pos;
    }

    // 逆向搜索
    string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");
    cout << "find returned: " << first_pos
         << ", rfind returned: " << last_pos << endl;

    string dept("03714prol3");
    pos = dept.find_first_not_of(numbers);
    cout << "first_not returned: " << pos <<" element is " << dept[pos] << endl;
    pos = dept.find_last_not_of(numbers);
    cout << "first_not returned: " << pos << " element is " << dept[pos] << endl;
}

void FindChar(const string &s, const string &chars)
{
    string::size_type pos = 0;
    while ((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        cout << "pos = " << pos << ", char: " << s[pos] << endl;
        ++pos;
    }
}

void FindNotChar(string &s, const string &chars)
{
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(chars, pos)) != string::npos)
    {
        cout << "pos = " << pos << ", char: " << s[pos] << endl;
        ++pos;
    }
}

void FindLongestWord(istream &in)
{
    string  s, longest_word;
    size_t     max_length = 0;

    while (in >> s)
    {
        if (s.find_first_of("bdfghjklpqty") != string::npos)
            continue;
        cout << s << endl;

        if (max_length < s.size())
        {
            max_length = s.size();
            longest_word = s;
        }
    }

    cout << "the longest word: " << longest_word << endl;
}

void Homework_9_47_48_49()
{
    string s("ab2c3d7R4E6");
    FindChar(s, "0123456789");
    cout << endl;
    FindChar(s, "abcdefghijklmnopqrstuvwxyz");
    cout << endl;

    FindNotChar(s, "0123456789");
    cout << endl;
    FindNotChar(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    FindLongestWord(cin);
}

/* 9.5.5 数值转换*/
void Practice_9_5_5()
{
    double i = 4.3;
    cout << "i = " << i << " s = " << to_string(i) << " d is: " << stod(to_string(i)) << endl;

    string s2 = "pi = 3.14";
    cout << s2.find_first_of("+-.0123456789") << endl;
    cout << s2.substr(s2.find_first_of("+-.0123456789")) << endl;
    cout << stod(s2.substr(s2.find_first_of("+-.0123456789"))) << endl;
}

void Homework_9_50()
{
    vector<string> vs = {"123", "+456", "-789"};
    int sum = 0;

    for (auto iter = vs.begin(); iter != vs.end(); ++iter)
        sum += stoi(*iter);

    cout << "sum: " << sum << endl;
}

// TODO...
// Homework_9_51

/***************************************************************/
/***************************9.6*********************************/

/* 9.6 容器适配器 */
void Practice_9_6()
{
    // 定义适配器
    deque<int>  deq;
    stack<int>  stk(deq);
    queue<int>  que;

    // 使用指定容器构造
    stack<string, vector<string>>   str_stk;

    vector<string> svec;
    stack<string, vector<string>>   str_stk2(svec);

    stack<int> istack;

    for (size_t ix = 0; ix != 10; ++ix)
        istack.push(ix);

    while (!istack.empty())
    {
        cout << istack.top() << " ";
        istack.pop();
    }
}

//TODO ...
// Homework_9_52()






