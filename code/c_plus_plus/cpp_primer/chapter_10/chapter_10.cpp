
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
using std::placeholders::_1;
using std::placeholders::_2;

void Chapter_10()
{
    Homework_10_1();

    //Practice_10_2_1();
    //Practice_10_2_2();
    //Practice_10_3_1();
    //Practice_10_3_2();
    //Practice_10_3_3();
    //Practice_10_3_4();
    //Practice_10_4_1();
    //Practice_10_4_2();
    //Practice_10_4_3();
    //Practice_10_5_3();

    //Homework_10_5();
    //Homework_10_13();
    //Homework_10_20();
    //Homework_10_21();
    //Homework_10_27();
    //Homework_10_34_35();
    //Homework_10_36();
    //Homework_10_37();
}

/***************************************************************/
/***************************10.1********************************/

void Homework_10_1()
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

/* 10.2.1 只读算法 */
void Practice_10_2_1()
{
    list<const char *> roster1 = {"hello", "so long", "tata"};

    // 算法和元素类型
    string sum = accumulate(roster1.begin(), roster1.end(), string(""));
    //string sum1 = accumulate(roster1.begin(), roster1.end(), "");

    // 操作两个序列的算法
    vector<string> roster2 = {"hello", "so long"};
    auto b = equal(roster2.begin(), roster2.end(), roster1.begin());
    (b) ? cout << "true" : cout << "false";
}

void Homework_10_5()
{
    char* p[] = {(char*)"hello", (char *)"world", (char *)"1"};
    char* q[] = {strdup(p[0]), strdup(p[1]),strdup(p[2])};
    char* r[] = {p[0], p[1], p[2]};

    cout << p[0] << ", " << q[0] << ", " << r[0] << endl;
    cout << equal(begin(p), end(p), q) << endl; //
    cout << equal(begin(p), end(p), r) << endl;
}

#include <iterator>

/* 10.2.2 写容器元素算法 */
void Practice_10_2_2()
{
    vector<int> ivec = {1,2,3,4};
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

    // back_inserter
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
void Practice_10_2_3()
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

bool LT(const string &s1, const string &s2)
{
    return s1 < s2;
}

void Print(const vector<string> &vec)
{
    for_each(vec.begin(), vec.end(), [](string s){ cout << s << " "; });
    cout << endl;
}

/*向算法传递函数*/
void Practice_10_3_1()
{
    string          s;
    vector<string>  svec;
    while (cin >> s)
        svec.push_back(s);
    Print(svec);

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

void Homework_10_13()
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

    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;

    //auto wc = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() > sz;});
    //auto wc = find_if(words.begin(), words.end(), bind(CheckSize, _1, sz));
    auto wc = partition(words.begin(), words.end(), [sz](const string &s){return s.size() > sz;});
    //auto wc = partition(words.begin(), words.end(), bind(CheckSize, _1, sz));

    //auto wc = stable_partition(words.begin(), words.end(), bind(CheckSize, _1, sz));
    //cout << words.end() - wc << "(s) numbers of length: " << sz << " or longer." << endl;

    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

#include <sstream>

void Practice_10_3_2_1()
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

void Practice_10_3_2()
{
    size_t v1 = 42, v2 = 100;
//    auto f1 = [v1]{return v1;};
//    cout << "v1 = " << v1 << ", f1() = " << f1() << endl;
//    v1 = 0;
//    cout << "v1 = " << v1 << ", f1() = " << f1() << endl;

//    auto f2 = [&v2]{return v2;};
//    v2 = 0;
//    cout << "v2 = " << v2 << ", f2() = " << f2() << endl;

//    auto f3 = [v1] () mutable {return ++v1;};
//    v1 = 0;
//    cout << "v1 = " << v1 << ", f3() = " << f3() << endl;

//    auto f4 = [&v2]{return ++v2;};
//    v2 = 0;
//    cout << "v2 = " << v2 << ", f4() = " << f4() << endl;

    size_t* const p = &v1;
    auto f = [p](){return ++*p;};
    cout << "v1 = " << v1 << ", f() = " << f() << endl;
    v1 = 0;
    cout << "v1 = " << v1 << ", f() = " << f() << endl;
}

bool GT(const string &s, string::size_type sz)
{
    return s.size() > sz;
}

bool CheckSize(const string &s, string::size_type sz)
{
    return s.size() >= sz;
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
//
void Practice_10_3_3()
{
    vector<string>  words;
    string          next_word;

    while (cin >> next_word)
        words.push_back(next_word);

    Biggies(words, 5);
}

ostream& Print(ostream& os, const string &s, char c)
{
    return os << s << c;
}

/*参数绑定*/
void Practice_10_3_4()
{
    string          s;
    vector<string>  words;
//    while (cin >> s)
//        words.push_back(s);

//    for_each(words.begin(), words.end(), bind(Print, ref(cout), _1, ' '));
//    cout << endl;

//    ofstream os("../out_file1");
//    for_each(words.begin(), words.end(), bind(Print, ref(os), _1, ' '));
//    cout << endl;

//    ifstream in("../chapter_10/chapter_10.cpp");
//    istream_iterator<string> is(in), eof;
//    for_each(is, eof, bind(Print, ref(cout), _1, ' '));
//    cout << endl;
}

void Print(const string &label, const list<int> &lst)
{
    cout << label << ": ";
    for (auto iter : lst)
        cout << iter << " ";
    cout << endl;
}

/*插入迭代器*/
void Practice_10_4_1()
{
    list<int> lst = {1,2,3,4};
    Print("lst", lst);

    list<int> lst2, lst3;
    copy(lst.begin(), lst.end(), front_inserter(lst2)); //push_front
    Print("lst2", lst2);

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
    Print("lst3", lst3);

    vector<int> v = {6,7,8,9,0};
    copy(v.begin(), v.end(), inserter(lst, lst.begin()));
    Print("new lst", lst);

    copy(v.begin(), v.end(), inserter(lst3, lst3.end()));
    Print("new lst2", lst3);
}

/*iostream迭代器*/
void Practice_10_4_2()
{
//    istream_iterator<int>   in(cin), eof;
//    cout << "sum: " << accumulate(in, eof, 0) << endl;

    vector<int> vec;
    istream_iterator<int> in_iter(cin), eof;
    //vector<int> vec(in_iter, eof);
    while (in_iter != eof)
        vec.push_back(*in_iter++);

//    for (auto it : vec)
//        cout << it << " ";

    ostream_iterator<int> out_iter(cout, "\n");
    for (const auto& e : vec)
        //out_iter = e;
        *out_iter++ = e;
}

/*反向迭代器*/
void Practice_10_4_3()
{
    string s;
    getline(cin, s);
    cout << "s  = " << s << endl;
    cout << "s1 = " << string(s.begin(), find(s.begin(), s.end(), ',')) << endl;
    cout << "s2 = " << string(s.crbegin(), find(s.crbegin(), s.crend(), ',')) << endl;

    cout << "s3 = " << string(find(s.crbegin(), s.crend(), ',').base(), s.cend()) << endl;
}

void Practice_10_5_3()
{
//    vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
//    vector<int> cpy = v1;

//    reverse(v1.begin(), v1.end());
//    for_each(v1.begin(), v1.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    vector<int> v2;
//    v1 = cpy;
//    reverse_copy(v1.begin(), v1.end(), back_inserter(v2));
//    for_each(v2.begin(), v2.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    v1 = cpy;
//    auto it = remove_if(v1.begin(), v1.end(), [](int i){return i % 2;});//
//    for_each(v1.begin(), it, [](int i){cout << i << " ";});
//    cout << endl;

//    v1 = cpy;
//    v2.clear();
//    remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i){return i & 1;});
//    for_each(v1.begin(), v1.end(), [](int i){cout << i << " ";});
//    cout << endl;
//    for_each(v2.begin(), v2.end(), [](int i){cout << i << " ";});
//    cout << endl;

//    vector<int> vec;
//    istream_iterator<int>   in(cin), eof;
//    copy(in, eof, back_inserter(vec));
//    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});

//    sort(vec.begin(), vec.end());
//    ostream_iterator<int> out(cout, "\n");
//    copy(vec.begin(), vec.end(), out);

    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for (auto it = vec.crbegin(); it != vec.crend(); ++it)
        cout << *it << " ";
    cout << endl;
}



void Homework_10_20()
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

void Homework_10_21()
{
    int i = 5;
    auto f = [i]()mutable -> bool {if (i > 0){--i; return false;}else return true;};

    for (int i = 0; i < 6; ++i)
        cout << f() << endl;
}

void PrintList(int i)
{
    cout << i << "\n";
}

void Homework_10_27()
{
    vector<int> vec = {0,1,2,3,3,3,4,5,6,7,8,8,9};
    list<int>   ilst;

    unique_copy(vec.begin(), vec.end(), back_inserter(ilst));
    for_each(ilst.begin(), ilst.end(), bind(PrintList, _1));
}


void Homework_10_34_35()
{
    vector<int> vec = {0,1,2,3,3,3,4,5,6,7,8,8,9};
    for (auto it = vec.crbegin(); it != vec.crend(); ++it)
        cout << *it << " ";
    cout << endl;

    for (auto it = vec.end(); it != vec.begin(); )
        cout << *(--it) << " ";
    cout << endl;
}

//TODO 正向查找
void Homework_10_36()
{
    
    list<int> ilst = {0,1,2,3,4,0,6,7,8,9};
    
    auto last_it = find(ilst.crbegin(), ilst.crend(), 0);
    last_it++;
    int cnt = 1;

    for (auto iter = ilst.begin(); iter != last_it.base(); ++iter, ++cnt) ;

    if (cnt >= ilst.size())
        cout << "no o params." << endl;
    else
        cout << "the last 0 in: " << cnt << " position." << endl;
}

//TODO
void Homework_10_37()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};

    ostream_iterator<int> out_iter(cout, "\n");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    list<int> li;
    vector<int>::reverse_iterator re(vec.begin() + 2);
    vector<int>::reverse_iterator rb(vec.begin() + 7);
    copy(rb, re, back_inserter(li));
    copy(li.begin(), li.end(), out_iter);
}
