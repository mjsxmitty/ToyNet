
#include "chapter_03.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <fstream>
#include <set>

using namespace std;

const int s_int_size = 12;
const int s_string_size = 4;

int     s_ia[s_int_size] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
string  s_sa[s_string_size] = { "pooh", "piglet", "eeyore", "tigger" };

vector<int>     s_ivec(s_ia, s_ia + s_int_size);
vector<string>  s_svec(s_sa, s_sa + s_string_size);

const int* FindVer(const vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val)
            return &vec[i];

    return 0;
}

void Chapter_03()
{
    //Practice_3_1();
    //Practice_3_6();
    //Practice_3_9();

    Homework_3_1();
    // Homework_3_2();
    // Homework_3_3();
    // Homework_3_4();
}

void Practice_3_1()
{
    const int       *iptr = nullptr;
    const string    *sptr = nullptr;

    iptr = FindVer(s_ivec, s_ivec[5]);
    if (iptr == &s_ivec[5])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;

    iptr = FindVer1(s_ivec, s_ivec[6]);
    if (iptr == &s_ivec[6])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;

    sptr = FindVer1(s_svec, s_svec[0]);
    if (sptr == &s_svec[0])
        cout << *sptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *sptr << endl;

    iptr = FindVer2(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;
    
    sptr = FindVer2(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        cout << *sptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *sptr << endl;

    iptr = FindVer3(s_ia, s_int_size, s_ia[7]);
    if (iptr == &s_ia[7])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;
    
    sptr = FindVer3(s_sa, s_string_size, s_sa[2]);
    if (sptr == &s_sa[2])
        cout << *sptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *sptr << endl;

    iptr = FindVer4(s_ia, s_ia + s_int_size, s_ia[8]);
    if (iptr == &s_ia[8])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;
    
    sptr = FindVer4(s_sa, s_sa + s_string_size, s_sa[3]);
    if (sptr == &s_sa[3])
        cout << *sptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *sptr << endl;

    iptr = FindVer4(Begin(s_ivec), End(s_ivec), s_ivec[9]);
    if (iptr == &s_ivec[9])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;
    
    sptr = FindVer4(Begin(s_svec), End(s_svec), s_svec[3]);
    if (sptr == &s_svec[3])
        cout << *sptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *sptr << endl;

    iptr = FindVer5(s_ia, s_ia + s_int_size, s_ia[10]);
    if (iptr == &s_ivec[10])
        cout << *iptr << endl;
    else
        cout << "test no template func failed, ret: " 
             << *iptr << endl;

    list<int>    slist(s_ia, s_ia + s_int_size);
    list<int>::iterator it = FindVer5(slist.begin(), slist.end(), 1024);
    if (it != slist.end())
        cout << *it << endl;
    else
        cout << "not find 1024" 
             << endl;
}

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; } 

vector<int> FilterVer1(const vector<int> &vec, int filter_val, bool (*pred)(int, int))
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix)
        if (pred(vec[ix], filter_val))
            nvec.push_back(vec[ix]);

    return nvec;
}

int CountOccurs(const vector<int> &vec, int val)
{
    vector<int>::const_iterator it = vec.begin();
    int occurs = 0;

    while ((it = find(it, vec.end(), val)) != vec.end())
    {
        ++occurs;
        ++it;
    }
    
    return occurs;
}

vector<int> FilterVer2(const vector<int> &vec, int val, const less<int> &lt)
{
    vector<int> nvec;
    // for (int ix = 0; ix < vec.size(); ++ix)
    //     if (pred(vec[ix], filter_val))
    //         nvec.push_back(vec[ix]);

    vector<int>::const_iterator it = vec.begin();
    while ((it = find_if(it, vec.end(), bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*it);
        ++it;
    }
    
    return nvec;
}

void Practice_3_6()
{
    const int ret_size = 6;
    const int part_val = 10;

    vector<int> local_vec = FilterVer1(s_ivec, part_val, GreaterThan);
    if (local_vec.size() != ret_size)
        cout << "test filter ver1 failed. ret size: " << local_vec.size() << endl;
    else
        cout << "test filter ver1 ok." << endl;
    
    local_vec = FilterVer2(s_ivec, part_val, less<int>());
    cout << "less than 10 vector size: " << local_vec.size() << endl;

    int ia2[s_int_size];
    cout << *FilterVer3(s_ia, s_ia + s_int_size, ia2, part_val, less<int>()) << endl;
    cout << ia2 << endl;

    //FilterVer4(s_ia, s_ia + s_int_size, ia2, part_val, less<int>());

    vector<int> local_vec2;
    FilterVer3(s_ia, s_ia + s_int_size, back_inserter(local_vec2), part_val, less<int>());
    cout << local_vec2.size() << endl;
}

void Practice_3_9()
{
    // istream_iterator<string>    is(cin);
    // istream_iterator<string>    eof;

    // vector<string>  local_vec;
    // copy(is, eof, back_inserter(local_vec));
    // sort(local_vec.begin(), local_vec.end());

    // ostream_iterator<string>    os(cout, "\t");
    // copy(local_vec.begin(), local_vec.end(), os);
    // cout <<endl;

    fstream     in_file("../CMakeLists.txt");
    ofstream    out_file("test.txt");    
    
    if (!in_file || !out_file)
    {
        cout << "open input/output file failed." << endl;
        return ;
    }
    
    istream_iterator<string>    is(in_file);
    istream_iterator<string>    eof;

    vector<string>  vec;
    copy(is, eof, back_inserter(vec));

    sort(vec.begin(), vec.end());

    ostream_iterator<string>    os(out_file, "\n");
    copy(vec.begin(), vec.end(), os);
}

/************************************************************/

void InitExclusionSet()
{

}

void Homework_3_1()
{
    ifstream    in_file("moo_cat.txt");
    ofstream    out_file("moo_cat.map");

    if (!in_file || !out_file)
    {
        cerr << "unalbe to open file!" << endl;
        return ;
    }
    

}
// void Homework_3_2();
// void Homework_3_3();
// void Homework_3_4();
