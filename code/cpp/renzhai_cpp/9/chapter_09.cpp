

#include "chapter_09.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>//char
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <forward_list>
#include <array>
#include <string.h>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace chapter_09
{

int s_iarry[] = {1,123,33,45,5,621,77,44,33,33,44,128,9,10};
string s_sarry[] = {"1","123","33","45","5","621","77","44","33","33","44","128","9","10"};

void TestVector()
{
    /* vector 初始化 */
    {
        vector<int> v(10);
        vector<int> v1(10, 1);
        vector<int> v2(v);
        vector<int> v3(v.begin(), v.end());
        vector<int> v4(v.begin(), v.begin() + 10);
        int array[10] = {1,2,3,4};
        vector<int> v5(array, array + 10);
    }

    /* vector内置函数 */
    {
        vector<int> v = {0,1,2,3,4,5,6,7,8,9}, t;
        //Print(v.begin(), v.end());

        t.assign(10, 0);
        Print(t.begin(), t.end());
        t.assign(v.begin(), v.begin() + 10);
        Print(t.begin(), t.end());

        t.push_back(1024);
        Print(t.begin(), t.end());
        cout << "front: "<< t.front() << endl;
        cout << "back: "<< t.back()  << endl;
        cout << "t[1]: "<< t[1]  << endl;

        t.clear();
        cout << t.empty() << endl;

        t.assign(v.begin(), v.begin() + 10);
        t.pop_back();
        Print(t.begin(), t.end());

        t.erase(t.begin(), t.begin() + 2);  //
        Print(t.begin(), t.end());

        t.insert(t.begin() + 2, 1);         //
        Print(t.begin(), t.end());

        cout << "size: " << t.size() << endl;
        cout << "capacity: " << t.capacity() << endl;

        t.resize(15);
        Print(t.begin(), t.end());

        t.resize(20, 1);
        Print(t.begin(), t.end());
        t.reserve(5);
        Print(t.begin(), t.end());

        t.swap(v);
        Print(t.begin(), t.end());

        //v.erase(v.begin());
    }

    /* vector访问 */
    {
        vector<int> v = {0,1,2,3,4,5,6,7,8,9};

        //访问方式1
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;

        //访问方式2
        for (size_t i = 0; i < v.size() ;i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        //访问方式3
        for (auto &tmp : v)
        {
            cout << tmp << " ";
        }
        cout << endl;
    }

    /* vector常见算法 */
    {
        vector<int> v = {10,1,23,3,24,5,56,7,18,9};

        // sort 从小到大
        sort(v.begin(), v.end());
        Print(v.begin(), v.end());

        // reverse 倒置 不排序
        reverse(v.begin(), v.end());
        Print(v.begin(), v.end());

        // copy 复制
        vector<int> b;
        b.resize(v.size());
        copy(v.begin(), v.end(), b.begin());
        Print(b.begin(), b.end());

        //寻找
        auto pos = find(v.begin(), v.end(), 23);
        cout << *pos << endl;
    }
}

void TestString()
{
    /* string 常见api */
    {
        string str = "hello world";

        for (string::iterator it = str.begin(); it != str.end(); ++it)
            cout << *it << " ";
        cout << endl;

        cout << "size: " << str.size() << endl;
        cout << "length: " << str.length() << endl;
        cout << "str empty: " << str.empty() << endl;

        cout << "c_str: " << str.c_str() << endl;   // const char*
        cout << "data: " << str.data() << endl;     // 内存地址

        str.reserve(100);
        string s = "hello";
        str.swap(s);
        cout << str << endl;

        str.insert(2, str);
        cout << str << endl;

        str.append("hello");
        cout << str << endl;

        str.push_back('A');
        cout << str << endl;

        str.erase(3);
        cout << str << endl;

        str.clear();

        char tmp[] = "hello world";
        str.assign(tmp);
        cout << str << endl;

        str.replace(1, 2, "AAAAAA");
        cout << str << endl;

        char tmp2[] = "nihao";
        str.copy(tmp2, strlen(tmp2) - 3);
        cout << tmp2 << endl;

        str.assign("llo wolldoooo");
        cout << str.find("ll") << endl;
        cout << str.rfind("ll") << endl;

        cout << str.find_first_of("ll") << endl;
        cout << str.find_last_of("ll") << endl;         //

        cout << str.find_first_not_of("ll") << endl;
        cout << str.find_last_not_of("ll") << endl;     // 反向找

        cout << str.substr(2, 3) << endl;
        str.compare(tmp);
    }
}

void TestMap()
{
    map<int, string> m0{{1, "a"}, {2, "b"}};
    map<int, string> m;

    m[0] = "hello";
    m.insert(make_pair(1, "nihao"));
    m.insert(pair<int, string>(2, "hi"));
    m.insert(map<int, string>::value_type(3, "oooo"));
    m.insert({{4, "a"}, {5, "b"}});
    m.insert({6, "aaa"});

    //m.swap(m0);
    for (auto &tmp : m)
    {
        cout << tmp.first << ":" << tmp.second << endl;
    }

    for (map<int, string>::iterator it = m.begin();
         it != m.end(); ++it)
    {
        cout << it->first << "->" << it->second << endl;
    }

    cout << m.at(6) << endl;
    cout << m[6] << endl;

    cout << "m size: " << m.size() << endl;
    cout << m.count(6) << endl;

    auto pos = m.find(6);
    cout << pos->first << ":" << pos->second << endl;

    auto flag = m.equal_range(1);
    cout << flag.first->first << "-" << flag.first->second << endl;
    cout << flag.second->first << "-" << flag.second->second << endl;

    auto flag1 = m.lower_bound(1);
    cout << flag1->first << ":" << flag1->second << endl;

    auto flag2 = m.upper_bound(1);
    cout << flag2->first << "->" << flag2->second << endl;


    multimap<int, string> immap;
    immap.insert(make_pair(1, "asd"));
    immap.insert(make_pair(1, "a1sd"));
    immap.insert(make_pair(1, "a2sd"));

    unordered_map<int, string> isumap;
    isumap.insert(make_pair(1, "asd"));
    isumap.count(1);
    isumap.hash_function();

    auto bucket = isumap.bucket(1);
    isumap.rehash(bucket);
    isumap.load_factor();

    unordered_multimap<int, int> iiummap;
    iiummap.key_eq()(iiummap.find(1)->first,1);
}

void TestList()
{
    Node<string> node;

    auto Init = [&]()
    {
        node.data_ = "hello";

        node.next_ = new Node<string>();
        node.next_->data_ = "hello1";
        node.next_->previous_ = &node;

        node.next_->next_ = new Node<string>();
        node.next_->next_->data_ = "hello2";
        node.next_->next_->previous_ = node.next_;

        node.next_->next_->next_ = new Node<string>();
        node.next_->next_->next_->data_ = "hello3";
        node.next_->next_->next_->previous_ = node.next_->next_;
    };

    auto PrintNodeList = [&]()
    {
        Node<string> *p = &node;
        while (p)
        {
            cout << p->data_ << endl;
            p = p->next_;
        }
    };

    auto RemoveNodeList = [&](const string &elem)
    {
        Node<string> *p = &node;

        while (p)
        {
            if (p->data_ != elem)
            {
                p = p->next_;
                continue;
            }

            if (p->previous_ == nullptr)
            {
                Node<string> *p1 = p;
                p = p->next_;
                p->previous_ = nullptr;
                delete p1;
                p1 = nullptr;
            }
            else if (p->next_ == nullptr)
            {
                p->previous_->next_ = nullptr;
                p->previous_ = nullptr;
                delete p;
                p = nullptr;
            }
            else
            {
                p->previous_->next_ = p->next_;
                p->next_->previous_ = p->previous_;
                delete p;
                p = nullptr;
            }
        }
    };

    Init();
    PrintNodeList();
    string node_name;
    cout << "please enter erase node name:";
    cin >> node_name;
    RemoveNodeList(node_name);
    cout << "after remove node ..." << endl;
    PrintNodeList();
}

void test_list()
{
    list<string> node_list;
    list<string> node_list1({"aa", "bb", "cc"});
    list<string> node_list2 = {"aa", "bb", "cc"};
    list<string> node_list3 = node_list1;
    list<string> node_list4(node_list1);

    string a[] = {"aa", "bb", "cc"};
    list<string> node_list5(a, a + 3);


    node_list.push_back("111");
    node_list.push_front("22");

    node_list.pop_back();
    node_list.pop_front();

    node_list.emplace_back("123");
    node_list.emplace_front("134");

    node_list.assign({"aa", "bb", "cc"});
    node_list.assign({});
    node_list.assign(node_list1.begin(), node_list1.end());
    node_list.assign(10, "asd");

    node_list.size();
    node_list.clear();
    node_list.swap(node_list);

    node_list.insert(node_list.begin(), "123");
    node_list.insert(node_list.end(), {"aa", "bb", "cc"});
    node_list.insert(node_list.end(), node_list1.begin(), node_list1.end());

    node_list.sort();
    node_list.sort(greater<string>());

    node_list.remove("aa");
    node_list1.remove_if([](const string &s) {return s.size() > 2;});

    node_list.unique();

    list<Hello> hlist;
    hlist.push_back(Hello());
    hlist.push_back(Hello(1));
    hlist.push_back(Hello(12));
    hlist.push_back(Hello(3));
    hlist.push_back(Hello(3));
    hlist.push_back(Hello(3));
    hlist.push_back(Hello(56));

    hlist.unique();
    //cout << hlist.size() << endl;

    node_list.insert(node_list.end(), node_list1.begin(), node_list1.end());
    node_list.insert(node_list.end(), node_list1.begin(), node_list1.end());

    auto ilist = { 1,2,3,4,5,65,67 };
    auto it = ilist.begin();
    for (advance(it, 2);it != ilist.end();++it)
    {
        cout << *it << " ";
        //advance(it, 2);
    }
    cout << endl;
}

void TestQueue()
{
    queue<int> q;
    queue<int> q1({ 1,2,3,4,5,65,67 });
    queue<int> q2(q1);

    q.push(1);
    q.push(34);
    q.push(15);
    q.push(17);
    q.push(18);
    q.push(91);
    q.push(10);

    cout << "queue size: " << q.size() << endl;
    cout << "queue front: " << q.front() << endl;
    cout << "queue back: " << q.back() << endl;

    q.emplace(100);
    cout << "queue size: " << q.size() << endl;

    queue<int> q0;
    q0.swap(q);
    cout << "queue size: " << q.size() << endl;
    swap(q,q0);
    cout << "queue size: " << q.size() << endl;

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void TestStack()
{
    stack<int> s({ 1,2,3,4,5,65,67 });
    stack<int> s1;
    stack<int> s2(s1);

    vector<int> v;
    stack<int, vector<int>> s3(v);

    s.push(3633);
    s.emplace(3123633);
    cout << "stack size: " << s.size() << endl;
    s1.swap(s);
    cout << "stack size: " << s.size() << endl;
    swap(s, s1);
    cout << "stack size: " << s.size() << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void TestSet()
{
    set<int> s({ 1,2,3,4,5,65,67 });
    set<int> s1(s);
    set<int> s2(s.begin(), s.end());

    int a[] = { 1,2,3,4,5,65,67 };
    set<int> s3(a, a+4);

    s.insert(100);
    s1.swap(s);

    s.emplace(11);
    s.emplace_hint(s.end(), 100);
    s.max_size();
    s.find(1);
    s.erase(s.find(1));
    s.erase(1);
    auto pair = s.equal_range(6);

    multiset<int> imset;
    imset.insert(100);
    imset.insert(100);

    imset.erase(imset.find(100));

    unordered_set<int> iuset;
    iuset.erase(1);
    iuset.find(1);

    unordered_multiset<int> iumset = {1,2};
    iumset.bucket(1);
    iumset.load_factor();
}

void TestForwardList()
{
    forward_list<int> fl(10, 1024);
    fl.assign(15, 1);
    fl.remove(1);
    fl.remove_if([](int i) {return i == 10;});
    fl.push_front(12);
    fl.emplace_after(fl.begin(), 1000);
    fl.emplace_front(1024);
    fl.front();
    fl.pop_front();
    fl.erase_after(fl.begin());

    forward_list<int> f2({ 1,2,3,4,5,65,67 });
    fl.splice_after(fl.before_begin(), f2);
}

void TestPriorityQueue()
{
    priority_queue<int> pq;
    pq.emplace(111);
    pq.push(312312);
    pq.push(3123);
    pq.push(323);
    pq.push(23);
    pq.push(3);

    pq.empty();
    pq.size();
    pq.top();
    pq.pop();

    priority_queue<Hello> hpq;
    hpq.emplace(Hello(100));
    hpq.emplace(Hello(130));
    hpq.emplace(Hello(10));
}

void TestHash()
{
    hash<string> sh;
    cout << sh(s_sarry[1]) << endl;
}

void TestArray()
{
    array<int, 10> iarray({1,2,3,4,5});
    iarray.fill(1024);
    auto p = iarray.data();
    iarray[1];
    iarray.at(1);
    iarray.back();
    iarray.front();
    iarray.size();

    for (array<int, 10>::iterator it = iarray.begin();
         it != iarray.end(); ++it)
    {
        cout << *it << endl;
    }
}
}
