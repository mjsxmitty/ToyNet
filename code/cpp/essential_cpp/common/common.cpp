
#include "common.h"
#include "num_sequence.h"

#include <ostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

namespace common
{

bool PrintFibon(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos << endl;
        return false;
    }

    cout << "the fibonacci sequence for " << pos << " positions: \n\t";

    switch (pos)
    {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
        val2 = val1;
        val1 = elem;
        cout << elem << (!(i % 10) ? "\n\t" : " ");
    }

    cout << endl;
    return true;
}

void Display(const vector<int> *vec, ostream *out)
{
    ostream &os = (out == 0) ? cout : *out;
    if (vec == 0)
    {
        os << "Display(): the vec point to 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); i++)
        os << (*vec)[i] << ' ';

    os << endl;
}

void Display(const vector<int> &vec, ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); i++) out << vec[i] << ' ';
    out << endl;
}

void Swap(int &val1, int &val2, ostream &out)
{
    out << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    out << "after swap: val1: " << val1 << ", val2: " << val2 << endl;
}

void Swap(int &val1, int &val2, ostream *out)
{
    if (out != 0)
        (*out) << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    if (out != 0)
        (*out) << "after swap: val1: " << val1 << ", val2: " << val2 << endl;
}

void BubbleSort(vector<int> &vec, ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                out << "call swap()! position : " << i << ", and position: " << j
                    << " swapping: " << vec[i] << ", with: " << vec[j] << endl;

                Swap(vec[i], vec[j], out);

                out << "after swap vector element: ";
                Display(vec, out);
            }
        }
    }
}

void BubbleSort(vector<int> *vec, ostream *out)
{
    if (vec == 0)
    {
        cout << "Bubble(): the point to vec is 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec->size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                if (out != 0)
                    *out << "call swap()! position : " << i
                        << ", and position: " << j << " swapping: "
                        << (*vec)[i] << ", with: " << (*vec)[j] << endl;


                Swap((*vec)[i], (*vec)[j], out);

                if (out != 0)
                {
                    *out << "after swap vector element: ";
                    Display(vec, out);
                }
            }
        }
    }
}

const vector<int>* FibonSeq(int size)
{
    static vector<int>  elems;

    if (!IsSizeOk(size))
        return 0;

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

bool FibonElem(int size, int &elem)
{
    const vector<int> *pseq = FibonSeq(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

void DisplayMsg(const string &msg)
{
    cerr << msg << endl;
}

void DisplayMsg(const string &msg, int size)
{
    cerr << msg << ", size: " << size << endl;
}

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; }

vector<int> FilterVer(const vector<int> &vec, int filter_val, bool (*pred)(int, int))
{
    vector<int> nvec;
    for (size_t ix = 0; ix < vec.size(); ++ix)
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

vector<int> FilterVer(const vector<int> &vec, int val, const less<int> &lt)
{
    vector<int> nvec;
    vector<int>::const_iterator it = vec.begin();

    while ((it = find_if(it, vec.end(), bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*it);
        ++it;
    }

    return nvec;
}

vector<int> SubVec(const vector<int> &vec, int val)
{
    //排序
    vector<int> local_vec(vec);
    sort(local_vec.begin(), local_vec.end());

    //找出第一满足要求值
    auto find_it = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));

    //删除元素
    local_vec.erase(find_it, local_vec.end());
    return local_vec;
}

void UserQuery(const map<string, int> &word_map)
{
    cout << " please enter a search word: ";
    string word;
    cin >> word;

    while (word.size() && word != "q")
    {
        auto it = word_map.find(word);
        if (it != word_map.end())
        {
            cout << "found " << it->first << " occurs " << it->second << " times.\n";
            cout << "anther search?(q to quit)";
        }
        else
        {
            cout << word << " was not found in text.\n" << " anther search?(q to quit) ";
            cin >> word;
        }
    }
}

void DisplayWordCount(const map<string, int> &word_map, ostream &out)
{
    auto it = word_map.begin();
    while (it != word_map.end())
    {
        out << "< " << it->first << ", " << it->second << " >\n";
        ++it;
    }
}

void ProcessFile(map<string, int> &word_map, const set<string> &exclude_set, ifstream &in)
{
    string word;
    while (in >> word)
    {
        if (exclude_set.count(word))
            continue;

        word_map[word]++;
    }
}

void InitExclusionSet(set<string> &exs)
{
    static string exclusion_words[26] = {
        "the","and","but","that","then","are","been",
        "can","a","could","did","for", "of",
        "had","have","him","his","her","its","is",
        "were","which","when","with","would"
    };

    //exs.insert(exclusion_words, exclusion_words + 26);
    exs.insert(begin(exclusion_words), end(exclusion_words));
}

void InitFamilyMap(ifstream &in, map<string, vstring> &family)
{
    string line;
    while (getline(in, line, '\n'))
    {
        string  fam_name;
        vstring childs;
#if 0
        //
        if (line.empty())
            continue;

        if (family.find(' ') == string::npos)
        {
            fam_name = line;
            contine;
        }

        ssize_type pos = 0, prev_pos = 0, line_size = line.size();
        while ((pos = line.find_first_of(' ', pos)) != string::npos)
        {
            if (!prev_pos)
                fam_name = line.substr(prev_pos, pos - prev_pos);
            else
                childs.push_back(line.substr(prev_pos, pos - prev_pos));

            prev_pos = ++pos;
        }

        //最后一个名字
        if (prev_pos < line_size)
            childs.push_back(line.substr(prev_pos, pos - prev_pos));
#endif
        stringstream ss(line);
        ss >> fam_name;

        string child_name;
        while (ss >> child_name)
            childs.push_back(child_name);

        cout << "family name: " << fam_name << ", childrens count: " << childs.size() << endl;

        if (!family.count(fam_name))
            family[fam_name] = childs;
        else
            cerr << "family: " << fam_name << " already in our map!\n";
    }
}

void DisplayMap(const map<string, vstring> &familes, ostream &out)
{
    auto it = familes.begin();
    while (it != familes.end())
    {
        out << "the family: " << it->first;
        if (it->second.empty())
            out << " has no children.\n";
        else
        {
            auto iter = it->second.begin();
            out << "\n";
            while (iter != it->second.end())
            {
                out << '\t'<< *iter << endl;
                ++iter;
            }
        }
        ++it;
    }
}

void QueryMap(const string &family, svec_map familes)
{
    svec_map::const_iterator cit = familes.find(family);
    if (cit == familes.cend())
    {
        cerr << "sorry, family: " << family << " is not occurs int current map\n";
        return ;
    }

    cout << "the " << family << " family: ";
    if (!cit->second.size())
        cout << "has no children!\n";

    else
    {
        cout << "has " << cit->second.size() << " childrens.\n";
        auto citer = cit->second.begin();
        while (citer != cit->second.end())
        {
            cout << "\t" << *citer << "\n";
            ++citer;
        }
    }
}

}