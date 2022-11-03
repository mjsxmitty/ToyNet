
#include "chapter_11.h"

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <set>
#include <list>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_set>
#include <unordered_map>

#include "../chapter_07/gz_sales_data.h"

using namespace std;

void ch_11()
{
    /* 使用关联容器 */
    //ch_11_1();

    /* 关联容器概述 */
    ch_11_2();
}

/***************************************************************/
/***************************11.1********************************/

// hw 11.4
string& Trans(string &s)
{
    for (size_t i = 0; i != s.size(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= ('A' - 'a');
        else if (s[i] == ',' || s[i] == '.')
            s.erase(i, 1);
    }

    return s;
}

void ch_11_1()
{
    map<string, int>    word_count;
    string              word;
    set<string>         exclude = {"the", "The", "But", "but"};

    cout << "please input a series string words: ";
    while (cin >> word)
        ++word_count[Trans(word)];

    for (const auto &w : word_count)
        if (exclude.find(w.first) == exclude.end())
            cout << w.first << " occurs " << w.second <<
                    ((w.second > 1) ? " times" : " time") << endl;
}

/***************************************************************/
/***************************11.2********************************/

void ch_11_2()
{
    /* 定义关联容器 */
    //ch_11_2_1();

    /* 关键字类型要求 */
    //ch_11_2_2();
    //hw_11_8();
    hw_11_9();

    /* pair类型 */
    //ch_11_2_3();
}

void ch_11_2_1()
{
    vector<int> v;
    for (auto i = 0; i != 10; ++i)
    {
        v.push_back(i);
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int i){cout << i << ' ';});
    cout << endl;

    set<int>        iset(v.begin(), v.end());
    multiset<int>   miset(v.begin(), v.end());
    cout << "iset size: "       << iset.size()      << ", miset: size: "    << miset.size() << endl;
    cout << "iset find 1: "     << iset.count(1)    << ", miset find 1: "   << miset.count(1) << endl;
    cout << "iset find 11: "    << iset.count(11)   << ", miset find 11: "  << miset.count(11) << endl;
}

void AddFamily(map<string, vector<string>> &families, const string &family)
{
    if (families.find(family) == families.end())
        families[family] = vector<string>();
}

void AddChild(map<string, vector<string>> &families,
              const string &family, const string &child)
{
    families[family].push_back(child);
}

void hw_11_8()
{
    map<string, vector<string>> families;

    AddFamily(families, "zhang");
    AddChild(families, "zhang", "san");
    AddChild(families, "zhang", "sansan");
    AddChild(families, "wang", "wu");
    AddFamily(families, "wang");

    for(auto &f : families)
    {
        cout << "family: " << f.first << ": ";
        for (auto &c : f.second)
            cout << c << ' ';
        cout << endl;
    }
    cout << endl;
}

void hw_11_9()
{
    string file("Makefile");
    ifstream in(file);
    if (!in)
    {
        cerr << "open file failed!" << endl;
        return ;
    }

    map<string, list<int>>  word_line;
    string  line;
    string  word;
    int lineno = 0;
    while (getline(in, line))
    {
        lineno++;
        istringstream l_in(line);
        while (l_in >> word)
        {
            Trans(word);
            word_line[word].push_back(lineno);
        }
    }
    cout << "test" << endl;
    for (const auto &w : word_line)
    {
        cout << w.first << " line: " << endl;
        for (const auto &i : w.second)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

bool CompareIsbn(const GZSalesData &lhs, const GZSalesData &rhs)
{
    return lhs.Isbn().size() < rhs.Isbn().size();
}

void ch_11_2_2()
{
    //multiset<string, decltype(GZSalesData)*> bookstore(CompareIsbn);
}

typedef pair<string, string> Author;
Author proust("Marcel", "Proust");
Author joyce{"James", "Joyce"};
Author austen = make_pair("Jane", "Austen");

pair<string, int> Process(const vector<string> &vec)
{
    if (!vec.empty())
        //return {vec.back(), vec.back().size()};
        //return make_pair(vec.back(), vec.back().size());
        return pair<string, int>(vec.back(), vec.back().size());
    else
        return pair<string, int>();
}

void ch_11_2_3()
{
    vector<string>  v;

    /* 创建 pair 对象 */ 
    istream_iterator<string>    in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(v));
    sort(v.begin(), v.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size();});

    auto biggest = Process(v);
    cout << biggest.first << " " << biggest.second << endl;
}

void AddFamily(map<string, vector<pair<string, string>>> &families, const string &family)
{
    families[family];
}

void AddChild(map<string, vector<pair<string, string>>> &families,
              const string &family, const string &child,
              const string &birth)
{
    families[family].push_back({child, birth});
}

void hw_11_14()
{
    map<string, vector<pair<string, string>>> families;

    AddFamily(families, "zhang");
    AddChild(families, "zhang", "san", "1991");
    AddChild(families, "zhang", "sansan", "2001");
    AddChild(families, "wang", "wu", "1990");
    AddFamily(families, "wang");

    for(auto &f : families)
    {
        cout << "family: " << f.first << ", ";
        for (auto &c : f.second)
            cout << c.first << ',' << c.second;
        cout << endl;
    }
}

/***************************************************************/
/***************************11.3********************************/

/* 11.3.2 添加元素 */
void ch_11_3_2()
{
    // insert
    vector<int> v = {2,4,6,8,2,4,6,8};
    set<int> set2;
    set2.insert(v.begin(), v.end());
    set2.insert({1,3,5,7,1,3,5,7});
    cout << "set2 size: " << set2.size() << endl;

    // 检测insert返回值
    map<string, size_t> word_count;
    string              word;
    while (cin >> word)
    {
        // insert
        auto ret = word_count.insert({word, 1});
//        ret = word_count.insert(make_pair(word, 1));
//        ret = word_count.insert(pair<string, size_t>(word, 1));
//        ret = word_count.insert(map<string, size_t>::value_type(word, 1));
        if (!ret.second)
            ++ret.first->second;
    }

    for (auto iter = word_count.begin(); iter != word_count.end(); ++iter)
        cout << "elem: " << iter->first << ", count: " << iter->second << endl;

    // 向 multimap 或者 multiset添加元素
    multimap<string, string> authors;
    authors.insert({"test_key", "test_val1"});
    authors.insert(pair<string, string>("test_key", "test_val2"));
}

void hw_11_20()
{
    map<string, int>    word_count;
    string              word;

    cout << "please input a series string words: ";
    while (cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second <<
                ((w.second > 1) ? " times" : " time") <<
                endl;
}

void AddChild(multimap<string, string> &families,
              const string &family, const string &child)
{
    families.insert({family, child});
}

void hw_11_23()
{
    multimap<string, string> families;

    AddChild(families, "zhang", "san");
    AddChild(families, "zhang", "sansan");
    AddChild(families, "wang", "wu");

    for(auto &f : families)
    {
        cout << f.first << " : " << f.second << endl;
    }

    //cout << families.erase("zhang") << endl;
}

/* 11.3.3 删除元素 */
void ch_11_3_3()
{
    string                  s;
    map<string, size_t>     word_count;

    while (cin >> s)
        ++word_count[s];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time")
             << endl;

    string erase_word = "the";
    if (word_count.erase(erase_word))
        cout << "removed " << erase_word << " ok." << endl;
    else
        cout << "oops: " << erase_word << " not found." << endl;

    string erase = "The";
    map<string, size_t>::iterator where = word_count.find(erase);
    if (where != word_count.end())
    {
        word_count.erase(erase);
        cout << "removed " << erase << " ok." << endl;
    }
    else
    {
        cout << "oops: " << erase << " not found." << endl;
    }
        
}

void RemoveAuthor(multimap<string, string>  &authors, const string &author)
{
    auto pos = authors.equal_range(author);
    if (pos.first == pos.second)
    {
        cout << "authors map can't include: " << author << endl;
    }

    authors.erase(pos.first, pos.second);
}

void PrintAuthor(multimap<string, string>  &authors)
{
    for (const auto &a : authors)
    {
        cout << a.first << "<<" << a.second << ">>" << endl;
    }
    cout << endl;
}

/* 11.3.5 访问元素 */
void ch_11_3_5()
{
    multimap<string, string>    authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    string  search_item("Alain de Botton");
    // 在 multimap 或 multiset 查找元素
//    auto entries = authors.count(search_item);
//    auto iter = authors.find(search_item);
//    while (entries)
//    {
//        cout << iter->second << endl;
//        ++iter;
//        --entries;
//    }
//    cout << endl;

    // 一种不同的，面相迭代器的解决办法
//    for (auto beg = authors.lower_bound(search_item),
//              end = authors.upper_bound(search_item);
//         beg != end; ++beg)
//        cout << beg->second << endl;
//    cout << endl;

    // equal_range 函数
//    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
//        cout << pos.first->second << endl;

    // hw 11.31
    authors.insert({"Alain de Botton2", "Architecture of Happiness"});
    authors.insert({"Alain de Botton2", "Architecture of Happiness"});

//    auto count = authors.count("Alain de Botton2");
//    auto iter2 = authors.find("Alain de Botton2");
//    if (count)
//    {
//        cout << "authors size: " << authors.size() << endl;
//        authors.erase(iter2->first);
//        cout << "after erase authors size: " << authors.size() << endl;
//        ++iter2;
//        --count;
//    }

    // hw 11.32
    PrintAuthor(authors);
    RemoveAuthor(authors, "Alain de Botton");
    PrintAuthor(authors);
}

map<string, string> BuildRuleMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string  key;
    string  val;

    while (map_file >> key && getline(map_file, val))   //
    {
        if (val.size() > 1)
            trans_map[key] = val.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string& Transform(const string &s, const map<string, string> &m)
{
    auto it = m.find(s);
    if (it != m.end())
        return it->second;
    else
        return s;
}

void WordTransform(ifstream &map_file, ifstream &input)
{
    auto trans_map = BuildRuleMap(map_file);
    cout << "Here is our trans rule: \n";
    for (const auto &entry : trans_map)
        cout << "key: " << entry.first << "\tvalue: " << entry.second << endl;
    cout << endl;

    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while (stream >> word)
        {
            if (first_word)
                first_word = false;
            else
            {
                cout << " ";
                cout << Transform(word, trans_map);
            }
        }
        cout << endl;
    }
}

// TODO ...
void ch_11_3_6()
{

}

/***************************************************************/
/***************************11.4********************************/

size_t Hasher(const GZSalesData &sd)
{
    return hash<string>()(sd.Isbn());
}

bool EqualOption(const GZSalesData &lhs, const GZSalesData &rhs)
{
    return lhs.Isbn() == rhs.Isbn();
}

//using SDMultiset = unordered_multiset<GZSalesData, decltype(Hasher)*, decltype(EqualOption)*>;
typedef unordered_multiset<GZSalesData, decltype(Hasher)*, decltype(EqualOption)*> SDMultiset;
typedef unordered_multimap<GZSalesData, decltype(Hasher)*, decltype(EqualOption)*> SDMultimap;
SDMultiset book(100, Hasher, EqualOption);

//TODO ...
void hw_11_38()
{
    unordered_map<string, size_t>    word_count;
    string              word;

    cout << "please input a series string words: ";
    while (cin >> word)
        ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second <<
                ((w.second > 1) ? " times" : " time") << endl;

}
