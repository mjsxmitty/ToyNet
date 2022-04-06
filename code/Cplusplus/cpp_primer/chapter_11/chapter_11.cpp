

#include "chapter_11.h"

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <set>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

void Chapter_11()
{
    //Practice_11_2_1();
    //Practice_11_2_3();
    //Practice_11_3_2();
	Practice_11_3_3();
    //Practice_11_3_5();
}

void Practice_11_2_1()
{
    vector<int> v;
    for (auto i = 0; i != 10; ++i)
    {
        v.push_back(i);
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    cout << endl;

    set<int>    iset(v.begin(), v.end());
    multiset<int>   miset(v.begin(), v.end());
    cout << "iset size: " << iset.size() << ", miset: size: " << miset.size() << endl;
    cout << "iset find 1: " << iset.count(1) << ", miset find 1: " << miset.count(1) << endl;
    cout << "iset find 11: " << iset.count(11) << ", miset find 11: " << miset.count(11) << endl;

    v = {2,4,6,8,2,4,6,8};
    set<int> set2;
    set2.insert(v.begin(), v.end());
    set2.insert({1,3,5,7,1,3,5,7});
    cout << "set2 size: " << set2.size() << endl;
}

typedef pair<string, string> Author;
Author proust("Marcel", "Proust");
Author joyce{"James", "Joyce"};
Author austen = make_pair("Jane", "Austen");

pair<string, int>
Process(const vector<string> &vec)
{
    if (!vec.empty())
        //return {vec.back(), vec.back().size()};
        //return make_pair(vec.back(), vec.back().size());
        return pair<string, int>(vec.back(), vec.back().size());
    else
        return pair<string, int>();
}

/*pair类型*/
void Practice_11_2_3()
{
    vector<string>  v;

    istream_iterator<string>    in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(v));
    sort(v.begin(), v.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size();});

    auto biggest = Process(v);
    cout << biggest.first << " " << biggest.second << endl;
}

/*添加元素*/
void Practice_11_3_2()
{
    map<string, size_t> word_count;
    string              word;
    while (cin >> word)
        ++word_count.insert({word, 0}).first->second;

    for (auto iter = word_count.begin(); iter != word_count.end(); ++iter)
        cout << "elem: " << iter->first << ", count: " << iter->second << endl;
}

void Practice_11_3_3()
{
    string                  s;
    map<string, size_t>     word_count;

    while (cin >> s)
        ++word_count[s];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time")
             << endl;
    //删除元素
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

/*访问元素*/
void Practice_11_3_5()
{
    multimap<string, string>    authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    string  search_item("Alain de Botton");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries)
    {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
    cout << endl;

    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end; ++beg)
        cout << beg->second << endl;
    cout << endl;

    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;
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

void Practice_11_3_6()
{

}
