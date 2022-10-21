

#include "chapter_08.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include <ifstream>
//#include <ofstream>

using namespace std;

void ch_08()
{
    /* IO 类 */
    ch_8_1();

    /* string 流 */
    ch_8_3();
}

void ch_8_1()
{
    /* 条件状态 */
    //ch_8_1_2();

    hw_8_1();
}

//条件状态
void Read()
{
    cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}

void Off()
{
    // clear带参数版本表示设置新的标志位
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}

void ch_8_1_2()
{
    cout << "before read: " << endl;
    if (cin.good()) cout << "cin's good"    << endl;
    if (cin.bad())  cout << "cin's bad"     << endl;
    if (cin.fail()) cout << "cin's fail"    << endl;
    if (cin.eof())  cout << "cin's eof"     << endl;
    cout << cin.rdstate() << endl;
//    cout << cout.rdstate() << endl;
    cout << endl;

    Read();
    cout << "after read: " << endl;
    if (cin.good()) cout << "cin's good"    << endl;
    if (cin.bad())  cout << "cin's bad"     << endl;
    if (cin.fail()) cout << "cin's fail"    << endl;
    if (cin.eof())  cout << "cin's eof"     << endl;
    cout << cin.rdstate() << endl;
//    cout << cout.rdstate() << endl;
    cout << endl;

    Off();
    cout << "after off: " << endl;
    if (cin.good()) cout << "cin's good"    << endl;
    if (cin.bad())  cout << "cin's bad"     << endl;
    if (cin.fail()) cout << "cin's fail"    << endl;
    if (cin.eof())  cout << "cin's eof"     << endl;
    cout << cin.rdstate() << endl;
//    cout << cout.rdstate() << endl;
}

istream& ReadData(istream &in)
{
    int ival;
    while (in >> ival, !in.eof())
    {
        try
        {
            if (in.bad())
                throw runtime_error("IO error!");

            if (in.fail())
            {
                cerr << "read num error, please try again!" << endl;
                in.clear();
                in.ignore(1024, '\n');
                continue;
            }

            cout << ival << ' ';
        } catch (runtime_error &e) {
            cout << e.what() << endl;
            in.clear();
        }

    }

    in.clear();
    return in;
}

void hw_8_1()
{
    ReadData(cin);
}

void ch_8_3()
{
    ch_8_3_2();

    hw_8_2();
}

struct PersonInfo
{
    string          name;   
    vector<string>  phones;   
};

string Format(const string &s)
{
    //TODO
    return s;
}

bool Valid(const string &s)
{
    //TODO
    return true;
}

vector<PersonInfo> GetData(ifstream &is)
{
    string  line, word;
    vector<PersonInfo> people;

    while (std::getline(is, line))
    {
        istringstream   record(line);
        PersonInfo      info;

        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        
        people.push_back(info);
    }

    return people;   
}

ostream& Process(ostream &os, vector<PersonInfo> peoples)
{
    for (const auto &entry: peoples)
    {
        ostringstream formatted, bad_nums;
        for (const auto &nums : entry.phones)
            if (!Valid(nums))
                bad_nums << " " << nums;
            else
                formatted << " " << Format(nums);
        
        if (bad_nums.str().empty())
            os << entry.name << " "
               << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s): " << bad_nums.str() << endl;
    }
    
    return os;
}

void ch_8_3_2()
{
    ifstream input("../chapter_08/sstream");
    vector<PersonInfo> peoples;
    if (input)
    {
        peoples = GetData(input);
        Process(cout, peoples);
    }
    else
        cout << "read file failed." << endl;
}

void hw_8_2()
{
    fstream in("Makefile");
    fstream out;
    out.open("Makefile.temp", ofstream::out | ofstream::trunc);
    if (!in || !out.is_open())
    {
        cout << "open file failed.\n";
        return ;
    }


    string words;
    while (getline(in, words))
    {
        ostringstream os;
        out << words << "\n";
        string word;
        istringstream line(words);
        while (line >> word)
            os << word << " --- ";
            //cout << word << endl;
        cout << os.str() << endl;
    }


    in.close();
    out.close();
}
