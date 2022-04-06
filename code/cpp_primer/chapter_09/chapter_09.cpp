

#include "chapter_09.h"

#include <forward_list>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <fstream>

using namespace std;

void Chapter_09()
{
    //Practice_9_3_1();
    //Practice_9_3_3();
    //Practice_9_4();
    //Practice_9_5_1();
    //Practice_9_5_2();
    //Practice_9_5_3();
    //Practice_9_5_5();
    //Practice_9_6();

    //Homework_9_4_5();
    //Homework_9_31();
    //Homework_9_43();
    //Homework_9_50();
}

void PrintVec(const vector<int> &vi)
{
    auto iter = vi.begin();
    while (iter != vi.end())
        cout << *iter++ <<  " ";
}

/*改变容器大小*/
void Practice_9_3_1()
{
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



/*容器对象是如何增长的()*/
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

void Practice_9_5_1()
{
    string s("hello world");
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

    //
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
    stack<int> istack;

    for (size_t ix = 0; ix != 10; ++ix)
        istack.push(ix);

    while (!istack.empty())
    {
        cout << istack.top() << " ";
        istack.pop();
    }
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

void Homework_9_31()
{
    forward_list<int> iflist = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflist.before_begin();
    auto curr = iflist.begin();

    while (curr != iflist.end())
    {
        if (*curr & 1)
        {
            curr = iflist.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        }
        else
            curr = iflist.erase_after(prev);
    }

    for (curr = iflist.begin(); curr != iflist.end(); ++curr)
        cout << *curr << " ";
    cout << endl;
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
        cout << "pos = " << pos << ", char: " << chars[pos] << endl;
        ++pos;
    }
}

void FindNotChar(string &s, const string &chars)
{
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(chars, pos)) != string::npos)
    {
        cout << "pos = " << pos << ", char: " << chars[pos] << endl;
        ++pos;
    }
}

void FindLongestWord(ifstream &in)
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


void Homework_9_50()
{
    vector<string> vs = {"123", "+456", "-789"};
    int sum = 0;

    for (auto iter = vs.begin(); iter != vs.end(); ++iter)
        sum += stoi(*iter);

    cout << "sum: " << sum << endl;
}