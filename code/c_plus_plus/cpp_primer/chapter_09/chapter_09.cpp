

#include "chapter_09.h"
#include "../lib_util/sales_data.h"

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

void Chapter_09()
{
    //Practice_9_2();
    //Practice_9_3_1();
    //Practice_9_3_3();
    //Practice_9_3_6();
    //Homework_9_31();

    Practice_9_4();
    //Practice_9_5_1();
    //Practice_9_5_2();
    //Practice_9_5_3();
    //Practice_9_5_5();
    //Practice_9_6();

    //Homework_9_4_5();
    //Homework_9_16();
    //Homework_9_28();

    //Homework_9_43();
    //Homework47_48();
    //Homework_9_50();
}

void Practice_9_2()
{
    /* 内置数组不可以copy */
    int sou[10] = {1,2,3,4};
//    int cpy[10] = sou;

    /* 标准库数组可以copy */
    array<int, 10> digits = {1,2,3,4,5};
    //array<int, 5>   copy = digits;  //error大小不同
    array<int, 10> copy = digits;
    copy = digits;

    /* 类型必须相同 */
    array<string, 10> copy2;
//    copy2 = digits;

    /* assgin */
    //类型转化
    list<string>        names;
    vector<const char*> old_style;
    //names = old_style;
    names.assign(old_style.begin(), old_style.end());
    names.assign(10, "yyy");

//    vector<int> temp_vec(10);
//    old_style.assign(temp_vec.begin(), temp_vec.end());

    /* swap */
    //相同类型
    //交换之后,指针/迭代器还有效,指向发生变化
    vector<string> svec1(10, "hi");
    vector<string> svec2(22, "nihao");
    auto it1 = svec1.begin(), it2 = svec2.begin();
    cout << svec1.size() << ", " << svec2.size() << endl;
    cout << *it1 << ", " << *it2 << endl;
    swap(svec1, svec2);
    cout << svec1.size() << ", " << svec2.size() << endl;
    auto it3 = svec1.begin(), it4 = svec2.begin();
    cout << *it3 << ", " << *it4 << endl;
    cout << *it1 << ", " << *it2 << endl;       //
}

void PrintVec(const vector<int> &vi)
{
    auto iter = vi.begin();
    while (iter != vi.end())
        cout << *iter++ <<  " ";
}

//vector, list, deque, forward_list, array, string
//push_back     --->    vector, list, deque, string
//push_front    --->    list, deque, forward_list
//insert        --->    vector, list, deque, string

//front         --->    all
//back          --->    vector, list, deque, array, string
//[]
//at()

//pop_back
//pop_front
//erase

/*改变容器大小*/
void Practice_9_3_1()
{
    /* insert范围元素 */
    list<int> slist = {1,2,3,4,5};
    vector<int> v;
    v.insert(v.begin(), slist.begin(), slist.end());
    PrintVec(v);
    cout << endl;
    v.insert(v.begin(), 10, 0);
    PrintVec(v);
    cout << endl;
    v.insert(v.begin(), {7,8,9});
    PrintVec(v);
    cout << endl;

    //访问返回的是引用
    v.front() = 100;
    auto &elem1 = v.back();
    elem1 = 1222;
    auto elem2 = v.back();
    elem2 = 2222;
    PrintVec(v);
    cout << endl;

    cout << v[5] << endl;
//    cout << v[20] << endl;
//    cout << v.at(20) << endl;

    auto iter1 = v.begin() + 3, iter2 = v.begin() + 13;
//    v.erase(iter1, iter2);
//    v.erase(iter1, v.end());
    v.erase(v.end(), v.end());
    PrintVec(v);
    cout << endl;

    vector<SalesData> c;
    c.emplace_back("11", 2, 2);
    auto iii = c.begin();
    c.emplace(iii, "11", 2, 2);


    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    PrintVec(vi);
    cout << endl;

    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
            iter = vi.erase(iter);
    }
    PrintVec(vi);
}

/*删除元素*/
void Practice_9_3_3()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    cout << "initial list: ";
    for (const auto &c: lst)
        cout << c << " ";
    cout << endl;

    auto it = lst.begin();
    while (it != lst.end())
    {
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;
    }
    cout << "after erasing odd elements from lst: ";
    for (auto it : lst)
        cout << it << " ";
    cout << endl;

    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};

    cout << "initial list: ";
    for (auto it : flst)
        cout << it << " ";
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
    for (auto it : flst)
        cout << it << " ";
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
    for (curr = iflist.begin(); curr != iflist.end(); ++curr)
    {

    }
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
    FLInsert(sflist, "!", "?");
    for (auto it = sflist.cbegin(); it != sflist.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}

/*****************************************************************/
/***************************9.3.6*********************************/
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

    //for_each(ivec.begin(), ivec.end(), [](int i){cout << i << endl;});

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

    ivec.reserve(25);
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

/*****************************************************************/
/***************************9.4*********************************/
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
    string s6(s, 3, 3);
    cout << s1 << ", "
         << s2 << ", "
         << s3 << ", "
//         << s4 << ", "
         << s5 << ", "
         << s6 << endl;

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

/*改变string*/
void Practice_9_5_2()
{
//    list<string>    slist;
//    string          s;

//    cout << "please input some strings: ";
//    while (cin >> s)
//        slist.push_back(s);
//    cout << "slist size: " << slist.size() << endl;

//    auto iter = find(slist.begin(), slist.end(), "aaa");
//    if (iter != slist.end())
//        slist.erase(iter);
//    cout << "slist size: " << slist.size() << endl;

//    auto orig = slist;
//    orig.clear();
//    cout << "slist size: " << orig.size() << endl;

//    orig = slist;
//    orig.erase(orig.begin(), orig.end());
//    cout << "slist size: " << orig.size() << endl;

            //
//    string s1 = "some string", s2 = "some other string";
//    s1.insert(s1.begin(), s2.begin(), s2.end());
//    cout << "insert iterators version: " << s1 << endl;

//    s1 = "some string";
//    s1.insert(0, s2);
//    cout << "insert string at given position: " << s1 << endl;

//    s1 = "some thing";
//    s1.insert(0, s2, 0, s2.size() - 1);
//    cout << "insert positional version: " << s1 << endl;

    //下标
    string s = "";
    vector<char> cvec(1, 'a');
    s.insert(s.begin(), cvec.begin(), cvec.end());
    cout << s << endl;
    s.insert(s.size(), 5, '!');
    cout << s << endl;
    s.erase(s.size() - 5, 2);
    cout << s << endl;

    s = "";
    string s1 ="hello";
    const char *cp = "Stately, plump Buck";
    s.assign(s1);
    cout << s << endl;
    s.assign(cp, 7);
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
    s.replace(11, 2, "ooo");
    cout << s << endl;

    s2 = "C++ Primer 5th Ed.";
    auto pos = s2.find("5th");
    if (pos != string::npos)
        s2.replace(11, 3, string("Fifth"));
    else
        cout << "no find appoint strings." << endl;
    cout << s2 << endl;
}

/*string的find操作*/
void Practice_9_5_3()
{
    string numbers("0123456789"), name("r9d2");
    auto pos = name.find_first_of(numbers);
    if (pos != string::npos)
        cout << "found number at index: " << pos
             << " element is " << name[pos] << endl;
    else
        cout << "no number in: " << name << endl;

    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        cout << "found number at index: " << pos
             << " element is " << name[pos] << endl;
        ++pos;
    }

    string river("Mississippi");
    auto first_pos = river.find("is");
    auto rfirst_pos = river.rfind("is");
    cout << "find returned: " << first_pos
         << " rfind returned: " << rfirst_pos << endl;

    string dept("03714prol3");
    pos = dept.find_first_not_of(numbers);
    cout << "first_not returned: " << pos <<" element is " << dept[pos] << endl;
    pos = dept.find_last_not_of(numbers);
    cout << "first_not returned: " << pos << " element is " << dept[pos] << endl;
}

/*数值转换*/
void Practice_9_5_5()
{
    double i = 4.3;
    cout << "i = " << i << " s = " << to_string(i) << " d is: " << stod(to_string(i)) << endl;

    string s2 = "pi = 3.14";
    cout << s2.find_first_of("+-.0123456789") << endl;
    cout << s2.substr(s2.find_first_of("+-.0123456789")) << endl;
    cout << stod(s2.substr(s2.find_first_of("+-.0123456789"))) << endl;
}

/*容器适配器*/
void Practice_9_6()
{
    deque<int>  deq;
    vector<int> vec;
    stack<int>  stk(deq);
    //stack<int>  stk(vec);

    stack<string, vector<string>>   str_stk;
    stack<string, vector<string>>   str_stk2(str_stk);

    stack<int> istack;

    for (size_t ix = 0; ix != 10; ++ix)
        istack.push(ix);

    while (!istack.empty())
    {
        cout << istack.top() << " ";
        istack.pop();
    }

    queue<int> que(deq);
    //queue<int, vector<int>> que2;
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
    auto lb = l.begin(), le = l.end();
    for (; vb != ve; ++vb, ++lb)
        if (*vb != *lb)
            return false;
    return true;
}

void Homework_9_16()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilist2 = {0,1,2,3,4,5,6,7};
    list<int> ilist3 = {0,1,2,3,4,5,6,7,7,9};

    cout << VLEqual(ivec, ilist) << ", "
         << VLEqual(ivec, ilist2) << ", "
         << VLEqual(ivec, ilist3)
         << endl;
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

    auto p = 0;
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
    int     max_length = 0;

    while (cin >> s)
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

void Homework47_48()
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
void Homework_9_50()
{
    vector<string> vs = {"123", "+456", "-789"};
    int sum = 0;

    for (auto iter = vs.begin(); iter != vs.end(); ++iter)
        sum += stoi(*iter);

    cout << "sum: " << sum << endl;
}
