
#include "chapter_10.h"
#include "../chapter_14/chapter_14.h"

#include <numeric>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <list>
#include <string.h>
#include <time.h>

using namespace std;

void ch_10()
{
    //hw_10_1();

    ch_10_2();

    //ch_10_3_1();
    //hw_10_13();
    //ch_10_3_2();
    //ch_10_3_3();
    //hw_10_20();
    //hw_10_21();
    //ch_10_3_4();

    //ch_10_4_1();
    //hw_10_27();
    //ch_10_4_2();
    //hw_10_29();
    //hw_10_30();
    //ch_10_4_3();
    //hw_10_34();
    //hw_10_36();
    //hw_10_37();

    //ch_10_5_3();

    //ch_10_6();
}

/***************************************************************/
/***************************10.1********************************/

void hw_10_1()
{
    srand(time(NULL));

    vector<int> ivec;
    for (size_t i = 0; i != 10; ++i)
    {
        ivec.push_back(rand() % 10);
    }
    for_each(ivec.begin(), ivec.end(), [](int i){ cout << i << ' ';});
    cout << endl;

    cout << "input you need search num: ";
    int num;
    cin >> num;
    cout << "the array include " << count(ivec.begin(), ivec.end(), num) << " number(s) " << num << endl;
}

/***************************************************************/
/***************************10.2********************************/

void ch_10_2()
{
    /* 只读算法 */
    //ch_10_2_1();
    //hw_10_5();

    /* 写容器元素算法 */
    ch_10_2_2();
}

void ch_10_2_1()
{
    /* 算法和元素类型 */ 
    vector<int> vint = {0,1,2,3,4};
    int isum = accumulate(vint.begin(), vint.end(), 0);

    list<const char *> clist = {"hello", "so long", "tata"};
    string sum = accumulate(clist.begin(), clist.end(), string(""));
    //string sum1 = accumulate(clist.begin(), clist.end(), "");

    /* 操作两个序列的算法 */ 
    vector<string> roster2 = {"hello", "so long"};
    auto b = equal(roster2.begin(), roster2.end(), clist.begin());
    (b) ? cout << "true" : cout << "false";
}

void hw_10_5()
{
    char* p[] = {(char*)"hello", (char *)"world", (char *)"1"};
    char* q[] = {strdup(p[0]), strdup(p[1]),strdup(p[2])};  //会开辟空间
    char* r[] = {p[0], p[1], p[2]};

    cout << p[0] << ", " << q[0] << ", " << r[0] << endl;
    cout << equal(begin(p), end(p), q) << endl; //
    cout << equal(begin(p), end(p), r) << endl;
}

#include <iterator>

void ch_10_2_2()
{
    vector<int> ivec(5, 1024);
    for_each(ivec.begin(), ivec.end(), [](int i) { cout << i << ' ';});    //临时测试用...
    cout << endl;

    //fill
    vector<int> vec1(ivec);
    fill(vec1.begin(), vec1.end(), 0);
    for_each(vec1.begin(), vec1.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    fill(vec1.begin(), vec1.begin() + vec1.size() / 2, 1);
    for_each(vec1.begin(), vec1.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    // 算法不检查写操作
    fill_n(vec1.begin(), vec1.size(), 2);
    for_each(vec1.begin(), vec1.end(), [](int i) { cout << i << ' '; });
    cout << endl;

//    vector<int> vec2;
//    fill_n(vec2.begin(), 10, 1);
//    for_each(vec2.begin(), vec2.end(), [](int i) { cout << i << ' '; });
//    cout << endl;

    // 介绍back_inserter
    vector<int> vec3;
    auto it = back_inserter(vec3);
    *it = 100;
    for_each(vec3.begin(), vec3.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    vector<int> vec4;
    fill_n(back_inserter(vec4), 10, 10);
    for_each(vec4.begin(), vec4.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    // copy
    vector<int> vec5;
    copy(ivec.begin(), ivec.end(), back_inserter(vec5)); //返回拷贝之后的位置
    for_each(vec5.begin(), vec5.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    // replace
    list<int>   list1(ivec.begin(), ivec.end());
    replace(list1.begin(), list1.end(), 1, 100);
    for_each(begin(list1), end(list1), [](int i) { cout << i << ' '; });
    cout << endl;

    // replace_copy
    list<int>   list2;
    replace_copy(ivec.begin(), ivec.end(), back_inserter(list2), 4, 4000);
    for_each(list2.begin(), list2.end(), [](int i) { cout << i << ' '; });
    cout << endl;
}

void ElimDups(vector<string> &words)
{
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    sort(words.begin(), words.end());
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    auto end_unique = unique(words.begin(), words.end());
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    words.erase(end_unique, words.end());
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

/* 10.2.3 重排容器元素 */
void ch_10_2_3()
{
    vector<string>  svec;

    string str;
    while (cin >> str) {
        svec.push_back(str);
    }

    ElimDups(svec);
}

/***************************************************************/
/***************************10.3********************************/

bool IsShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void PrintVer0(const vector<string> &vec)
{
    for_each(vec.begin(), vec.end(), [](string s){ cout << s << " "; });
    cout << endl;
}

/* 10.3.1 向算法传递函数 */
void ch_10_3_1()
{
    string          s;
    vector<string>  svec;
    while (cin >> s)
        svec.push_back(s);

    PrintVer0(svec);

    ElimDups(svec);

//    stable_sort(svec.begin(), svec.end(), IsShorter);
//    Print(svec);

//    sort(svec.begin(), svec.end(), IsShorter);
//    Print(svec);

//    sort(svec.begin(), svec.end(), bind(IsShorter, _2, _1));
//    Print(svec);
}

bool NumMoreWords(const string &s)
{
    return s.size() > 5;
}

void hw_10_13()
{
    vector<string>  svec;
    string          s;

    istream_iterator<string> in(cin), eof;
    while (in != eof)
        svec.push_back(*in++);
    for_each(svec.begin(), svec.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    auto it = partition(svec.begin(), svec.end(), NumMoreWords);
    for_each(svec.begin(), it, [](const string &s){cout << s << " ";});
}

/* 10.3.3 lambada表达式 */
void Biggies(vector<string> &words, vector<string>::size_type sz)
{
    ElimDups(words);

    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    // 向lambda传递参数
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    // 使用捕获列表
    // 调用find_if
    //auto wc = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() > sz;});
    //auto wc = partition(words.begin(), words.end(), [sz](const string &s){return s.size() > sz;});
    auto wc = stable_partition(words.begin(), words.end(), [sz] (const string &s) { return s.size() > sz; });

    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

#include <sstream>

void ch_10_3_2()
{
    vector<string>  svec;
    string          line;

    while(getline(cin, line))
    {
        string s;
        istringstream in(line);
        while (in >> s)
        {
            svec.push_back(s);
        }
    }

    Biggies(svec, 3);
}

void Biggies(vector<string> &words, vector<string>::size_type sz,
             ostream &os = cout, char c = ' ')
{
    // 隐式捕获
    for_each(words.begin(), words.end(), [&, c] (const string &s){ os << s << c; });
    for_each(words.begin(), words.end(), [=, &os] (const string &s) { os << s << c; });

    for_each(words.begin(), words.end(), [&, c, sz] (const string &s) {os << s << c << sz << c; });
}

void ch_10_3_3()
{
    size_t v1 = 42, v2 = 100;
    // 值捕获
    auto f1 = [v1]{return v1;};     // lambda创建时拷贝
    cout << "v1 = " << v1 << ", f1() = " << f1() << endl;
    v1 = 0;
    cout << "v1 = " << v1 << ", f1() = " << f1() << endl  << endl;;

    // 引用捕获
    auto f2 = [&v2]{return v2;};
    v2 = 0;
    cout << "v2 = " << v2 << ", f2() = " << f2() << endl << endl;

    // 隐式捕获 ...

    // 可变lambda
    auto f3 = [v1] () mutable {return ++v1;};
    v1 = 0;
    cout << "v1 = " << v1 << ", f3() = " << f3() << endl;

    auto f4 = [&v2]{return ++v2;};
    v2 = 0;
    cout << "v2 = " << v2 << ", f4() = " << f4() << endl;

    // 是否可以更改,需要看指向的是否是const
    size_t* const p = &v1;
    auto f = [p](){return ++*p;};
    cout << "v1 = " << v1 << ", f() = " << f() << endl;
    v1 = 0;
    cout << "v1 = " << v1 << ", f() = " << f() << endl;

    // 指定lambda返回类型
    vector<int> ivec;
    // TODO ...
    transform(ivec.begin(), ivec.end(), ivec.begin(), [](int i) -> int { if (i < 0) return -i; else return i; });
}

void hw_10_20()
{
    vector<string>  svec;
    string          s;

    istream_iterator<string> in(cin), eof;
    while (in != eof)
        svec.push_back(*in++);

    for_each(svec.begin(), svec.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    auto it = count_if(svec.begin(), svec.end(), [](const string &s){return s.size() > 6;});
    cout << "more than 6 size words counts: " << it << endl;
}

void hw_10_21()
{
    int i = 5;
    auto f = [i] () mutable -> bool { if (i > 0) {--i; return false;} else return true; };

    for (int j = 0; j < 6; ++j)
    {
        cout << f() << ' ';
    }
    cout << endl;
}

bool CheckSize(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

ostream& PrintVer1(ostream& os, const string &s, char c)
{
    return os << s << c;
}

//using std::placeholders::_1;
//using std::placeholders::_2;
using namespace std::placeholders;

/* 10.3.4 参数绑定 */
void ch_10_3_4()
{
    // 绑定CheckSize的sz参数
    {
        vector<string>              words;
        vector<string>::size_type   sz;

        auto wc = find_if(words.begin(), words.end(), bind(CheckSize, _1, sz));
        cout << words.end() - wc << "(s) numbers of length: " << sz << " or longer." << endl;

        // hw_10_25
        //auto wc = partition(words.begin(), words.end(), bind(CheckSize, _1, sz));
        //auto wc = stable_partition(words.begin(), words.end(), bind(CheckSize, _1, sz));
    }

    // 使用 placeholders

    // 绑定引用参数
    {
        string          s;
        vector<string>  words;
        while (cin >> s)
            words.push_back(s);

        for_each(words.begin(), words.end(), bind(PrintVer1, ref(cout), _1, ' '));
        cout << endl;

//        ofstream os("../out_file1");
//        for_each(words.begin(), words.end(), bind(Print, ref(os), _1, ' '));
//        cout << endl;

//        ifstream in("../chapter_10/chapter_10.cpp");
//        istream_iterator<string> is(in), eof;
//        for_each(is, eof, bind(Print, ref(cout), _1, ' '));
//        cout << endl;
    }
}

/***************************************************************/
/***************************10.4********************************/

void PrintVer2(const string &label, const list<int> &lst)
{
    cout << label << ": ";
    for (auto iter : lst)
        cout << iter << " ";
    cout << endl;
}

/* 10.4.1 插入迭代器 */
void ch_10_4_1()
{
    list<int> lst = {1,2,3,4};
    PrintVer2("source list", lst);

    list<int> lst2, lst3;
    copy(lst.begin(), lst.end(), front_inserter(lst2));
    PrintVer2("front_inserter", lst2);

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
    PrintVer2("inserter", lst3);

    vector<int> v = {6,7,8,9,0};
    copy(v.begin(), v.end(), front_inserter(lst));
    PrintVer2("vector front_inserter list", lst);

    copy(v.begin(), v.end(), inserter(lst3, lst3.end()));
    PrintVer2("vector inserter list", lst3);
}

void PrintList(int i)
{
    cout << i << "\n";
}

void hw_10_27()
{
    vector<int> vec = {0,1,2,3,3,3,4,5,6,7,8,8,9};
    list<int>   ilst;

    unique_copy(vec.begin(), vec.end(), back_inserter(ilst));
    for_each(ilst.begin(), ilst.end(), bind(PrintList, _1));
}

/* 10.4.2 iostream迭代器 */
void ch_10_4_2()
{
//    vector<int> vec;
//    istream_iterator<int> in_iter(cin), eof;
//    while (in_iter != eof)
//        vec.push_back(*in_iter++);
//    for_each(vec.begin(), vec.end(), [](int i) { cout << i << ' '; });

    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    // 使用算法操作流迭代器
//    istream_iterator<int>   in(cin), eof;
//    cout << "stream sum = " << accumulate(in, eof, 0) << endl;
//    cout << count(in, eof, 1) << endl;

    // ostream_iterator 操作
    ostream_iterator<int> out_iter(cout, "\n");
//    for (const auto& e : vec)
//        //out_iter = e;
//        *out_iter++ = e;
    copy(vec.begin(), vec.end(), out_iter);
}

void hw_10_29()
{
    ifstream in("Makefile");    // 测试用的文件
    if (!in)
    {
        cout << "open file failed!" << endl;
        return ;
    }

    istream_iterator<string>    in_iter(in), eof;
    vector<string>              svec;

    while (in_iter != eof)
        svec.push_back(*in_iter++);
    for_each(svec.begin(), svec.end(), [](const string &s) { cout << s << '\n'; });
}

void hw_10_30()
{
    istream_iterator<int>    in_iter(cin), eof;
    vector<int>              ivec(in_iter, eof);

    sort(ivec.begin(), ivec.end());
    for_each(ivec.begin(), ivec.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    ostream_iterator<int>   out_iter(cout, "\n");
    //copy(ivec.begin(), ivec.end(), out_iter);
    unique_copy(ivec.begin(), ivec.end(), out_iter);
}

/* 10.4.3 反向迭代器 */
void ch_10_4_3()
{
    vector<int> ivec = {10, 1, 23, 3, 12, 34, 14, 9};
    for_each(ivec.begin(), ivec.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    sort(ivec.rbegin(), ivec.rend());
    for_each(ivec.begin(), ivec.end(), [](int i) { cout << i << ' '; });
    cout << endl;

    // 反向迭代器和其他迭代器之间的关系
    string s("FIRST,MIDDLE,LAST");
    //getline(cin, s);
    cout << "s  = " << s << endl;
    cout << "s1 = " << string(s.begin(), find(s.begin(), s.end(), ',')) << endl;
    cout << "s2 = " << string(s.crbegin(), find(s.crbegin(), s.crend(), ',')) << endl;
    cout << "s3 = " << string(find(s.crbegin(), s.crend(), ',').base(), s.cend()) << endl;
}

void hw_10_34()
{
    vector<int> vec = {0,1,2,3,3,3,4,5,6,7,8,8,9};
    for_each(vec.crbegin(), vec.crend(), [] (int i) { cout << i << ' '; });
    cout << endl;

    // 10.35
    for (auto it = vec.end(); it != vec.begin(); )
        cout << *(--it) << ' ';
    cout << endl;
}

void hw_10_36()
{
    list<int> ilst = {0,1,2,3,4,0,6,7,0,9};

    auto last_it = find(ilst.crbegin(), ilst.crend(), 0);
    last_it++;

    unsigned int cnt = 1;
    for (auto iter = ilst.begin(); iter != last_it.base(); iter++, cnt++) ; // 空语句

    if (cnt >= ilst.size())
        cout << "no value." << endl;
    else
        cout << "the last 0 in: " << cnt << " position." << endl;
}

void hw_10_37()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};

    ostream_iterator<int> out_iter(cout, "\n");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    list<int> li;
    vector<int>::reverse_iterator re(vec.begin() + 2);  //反向迭代器
    vector<int>::reverse_iterator rb(vec.begin() + 7);
    copy(rb, re, back_inserter(li));
    copy(li.begin(), li.end(), out_iter);
}

/***************************************************************/
/***************************10.5********************************/

void ch_10_5_3()
{
    vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> cpy = v1;

    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int i){cout << i << " ";});
    cout << endl;

    vector<int> v2;
    v1 = cpy;
    reverse_copy(v1.begin(), v1.end(), back_inserter(v2));
    for_each(v2.begin(), v2.end(), [](int i){cout << i << " ";});
    cout << endl;

    v1 = cpy;
    auto it = remove_if(v1.begin(), v1.end(), [](int i){return i % 2;});//
    for_each(v1.begin(), it, [](int i){cout << i << " ";});
    cout << endl;

    v1 = cpy;
    v2.clear();
    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i){return i & 1;});
    for_each(v1.begin(), v1.end(), [](int i){cout << i << " ";});
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int i){cout << i << " ";});
    cout << endl;

    vector<int> vec;
    istream_iterator<int>   in(cin), eof;
    copy(in, eof, back_inserter(vec));
    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});

    sort(vec.begin(), vec.end());
    ostream_iterator<int> out(cout, "\n");
    copy(vec.begin(), vec.end(), out);

//    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
//    for (auto it = vec.crbegin(); it != vec.crend(); ++it)
//        cout << *it << " ";
//    cout << endl;
}

/***************************************************************/
/***************************10.6********************************/

void ch_10_6()
{
    list<int>   ilist1 = {0, 1, 2, 3};
    list<int>   ilist2 = {6, 7, 8, 9};

//    ilist1.merge(ilist2);
//    for_each(ilist1.begin(), ilist1.end(), [](int i){cout << i << " ";});
//    cout << endl;
//    for_each(ilist2.begin(), ilist2.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    ilist1.reverse();
//    for_each(ilist1.begin(), ilist1.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    ilist1.remove(0);
//    for_each(ilist1.begin(), ilist1.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    ilist1.insert(ilist1.end(), 1);
//    for_each(ilist1.begin(), ilist1.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    ilist1.unique();
//    for_each(ilist1.begin(), ilist1.end(), [](int i){cout << i << " ";});
//    cout << endl;

    list<int>   ilist3 = {0, 1, 2, 3};
    list<int>   ilist4 = {6, 7, 8, 9};

//    ilist3.splice(--ilist3.end(), ilist4);
//    for_each(ilist3.begin(), ilist3.end(), [](int i){cout << i << " ";});
//    cout << endl;
//    for_each(ilist4.begin(), ilist4.end(), [](int i){cout << i << " ";});
//    cout << endl;

    ilist3.splice(--ilist3.end(), ilist4, ilist4.begin(), ilist4.end());
    for_each(ilist3.begin(), ilist3.end(), [](int i){cout << i << " ";});
    cout << endl;
}

bool LT(const string &s1, const string &s2)
{
    return s1 < s2;
}

bool GT(const string &s, string::size_type sz)
{
    return s.size() > sz;
}

void Biggies2(vector<string> &words, vector<string>::size_type sz)
{
    ShorterString ss;
    stable_sort(words.begin(), words.end(), ss);
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    SzieComp sc(sz);
    auto wc = stable_partition(words.begin(), words.end(), sc);
    cout << words.end() - wc << "(s) numbers of length: " << sz << " or longer." << endl;

    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}
