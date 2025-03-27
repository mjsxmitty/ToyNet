
#include "common.h"
#include "num_sequence.h"

#include <ostream>
#include <vector>
#include <iterator>
#include <sstream>
namespace common
{
#if 0
bool FibonElem(int pos, int &elem)
{
    // 无效位置
    if (pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos << std::endl;

        elem = 0;
        return false;
    }

    elem = 1;
    int val1 = 1, val2 = 1;

    for (int i = 3; i <= pos; i++)
    {
        elem = val2 + val1;
        val2 = val1;
        val1 = elem;
    }

    return true;
}
#endif

bool PrintFibon(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                    << std::endl;
        return false;
    }

    std::cout << "the fibonacci sequence for "
                << pos << " positions: \n\t";

    switch (pos)
    {
        default:
        case 2:
            std::cout << "1 ";
        case 1:
            std::cout << "1 ";
            break;
    }

    int elem;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
        val2 = val1;
        val1 = elem;
        std::cout << elem << (!(i % 10) ? "\n\t" : " ");
    }

    std::cout << std::endl;
    return true;
}

void Display(const std::vector<int> *vec, std::ostream *out)
{
    std::ostream &os = (out == 0) ? std::cout : *out;
    if (vec == 0)
    {
        os << "Display(): the vec point to 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); i++)
        os << (*vec)[i] << ' ';

    os << std::endl;
}

void Display(const std::vector<int> &vec, std::ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        out << vec[i] << ' ';

    out << std::endl;
}

void Swap(int &val1, int &val2, std::ostream &out)
{
    out << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    out << "after swap: val1: " << val1
        << ", val2: " << val2 << std::endl;
}

void Swap(int &val1, int &val2, std::ostream *out)
{
    if (out != 0)
        (*out) << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    if (out != 0)
        (*out) << "after swap: val1: " << val1
                << ", val2: " << val2 << std::endl;
}

void BubbleSort(std::vector<int> &vec, std::ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                out << "call swap()! position : " << i
                    << ", and position: " << j
                    << " swapping: " << vec[i]
                    << ", with: " << vec[j]
                    << std::endl;

                Swap(vec[i], vec[j], out);

                out << "after swap std::vector element: ";
                Display(vec, out);
            }
        }
    }
}

void BubbleSort(std::vector<int> *vec, std::ostream *out)
{
    if (vec == 0)
    {
        std::cout << "Bubble(): the point to vec is 0.\n";
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
                        << (*vec)[i] << ", with: " << (*vec)[j] << std::endl;


                Swap((*vec)[i], (*vec)[j], out);

                if (out != 0)
                {
                    *out << "after swap std::vector element: ";
                    Display(vec, out);
                }
            }
        }
    }
}

#if 0
const std::vector<int>* FibonSeq1(int size)
{
    static std::vector<int> elems;
    const int               max_elems = 1024;

    if (size <= 0 || size > max_elems)
    {
        std::cerr << "invalid size: " << size << std::endl;
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

#endif

const std::vector<int>* FibonSeq(int size)
{
    static std::vector<int>  elems;

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
    const std::vector<int> *pseq = FibonSeq(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

void DisplayMsg(const std::string &msg)
{
    std::cerr << msg << std::endl;
}

void DisplayMsg(const std::string &msg, int size)
{
    std::cerr << msg << ", size: " << size << std::endl;
}

#if 0
bool SeqElem(int size, int &elem, const std::vector<int>* (*seq_ptr)(int))
{
    const std::vector<int> *pseq = seq_ptr(size);
    if (!pseq)
    {
        elem = 0;
        DisplayMsg("oops: sequence ptr is point to null.");
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}
#endif

bool LessThan(int v1, int v2) { return v1 < v2 ? true : false; }
bool GreaterThan(int v1, int v2) { return v1 > v2 ? true : false; }

std::vector<int> FilterVer(const std::vector<int> &vec, int filter_val, bool (*pred)(int, int))
{
    std::vector<int> nvec;
    for (size_t ix = 0; ix < vec.size(); ++ix)
        if (pred(vec[ix], filter_val))
            nvec.push_back(vec[ix]);

    return nvec;
}

int CountOccurs(const std::vector<int> &vec, int val)
{
    std::vector<int>::const_iterator it = vec.begin();
    int occurs = 0;

    while ((it = find(it, vec.end(), val)) != vec.end())
    {
        ++occurs;
        ++it;
    }

    return occurs;
}

std::vector<int> FilterVer(const std::vector<int> &vec, int val, const std::less<int> &lt)
{
    std::vector<int> nvec;
    std::vector<int>::const_iterator it = vec.begin();

    while ((it = find_if(it, vec.end(), std::bind2nd(lt, val))) != vec.end())
    {
        nvec.push_back(*it);
        ++it;
    }

    return nvec;
}

std::vector<int> SubVec(const std::vector<int> &vec, int val)
{
    //排序
    std::vector<int> local_vec(vec);
    std::sort(local_vec.begin(), local_vec.end());

    //找出第一满足要求值
    auto find_it = find_if(local_vec.begin(), local_vec.end(),
                            std::bind2nd(std::greater<int>(), val));

    //删除元素
    local_vec.erase(find_it, local_vec.end());
    return local_vec;
}

void UserQuery(const std::map<std::string, int> &word_map)
{
    std::cout << " please enter a search word: ";
    std::string word;
    std::cin >> word;

    while (word.size() && word != "q")
    {
        auto it = word_map.find(word);
        if (it != word_map.end())
        {
            std::cout << "found " << it->first
                << " occurs " << it->second
                << " times.\n";
                std::cout << "anther search?(q to quit)";
        }
        else
        std::cout << word << " was not found in text.\n"
                << " anther search?(q to quit) ";
                std::cin >> word;
    }
}

void DisplayWordCount(const std::map<std::string, int> &word_map, std::ostream &out)
{
    auto it = word_map.begin();
    while (it != word_map.end())
    {
        out << "< " << it->first
            << ", "
            << it->second << " >\n";
        ++it;
    }
}

void ProcessFile(std::map<std::string, int> &word_map,
                const std::set<std::string> &exclude_set,
                std::ifstream &in)
{
    std::string word;
    while (in >> word)
    {
        if (exclude_set.count(word))
            continue;

        word_map[word]++;
    }
}

void InitExclusionSet(std::set<std::string> &exs)
{
    static std::string exclusion_words[26] = {
        "the","and","but","that","then","are","been",
        "can","a","could","did","for", "of",
        "had","have","him","his","her","its","is",
        "were","which","when","with","would"
    };

    //exs.insert(exclusion_words, exclusion_words + 26);
    exs.insert(begin(exclusion_words), end(exclusion_words));
}

void InitFamilyMap(std::ifstream &in, std::map<std::string, vstring> &family)
{
    std::string line;
    while (getline(in, line, '\n'))
    {
        std::string  fam_name;
        vstring childs;
#if 0
        //
        if (line.empty())
            continue;

        if (family.find(' ') == std::string::npos)
        {
            fam_name = line;
            contine;
        }

        ssize_type pos = 0, prev_pos = 0, line_size = line.size();
        while ((pos = line.find_first_of(' ', pos)) != std::string::npos)
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
        std::stringstream ss(line);
        ss >> fam_name;

        std::string child_name;
        while (ss >> child_name)
            childs.push_back(child_name);

        std::cout << "family name: " << fam_name
            << ", childrens count: " << childs.size()
            << std::endl;

        if (!family.count(fam_name))
            family[fam_name] = childs;
        else
        std::cerr << "family: " << fam_name
                << " already in our map!\n";
    }
}

void DisplayMap(const std::map<std::string, vstring> &familes, std::ostream &out)
{
    auto it = familes.begin();
    while (it != familes.end())
    {
        out << "the family " << it->first;
        if (it->second.empty())
            out << " has no children.\n";
        else
        {
            auto iter = it->second.begin();
            out << "\n";
            while (iter != it->second.end())
            {
                out << '\t'<< *iter << std::endl;
                ++iter;
            }
        }
        ++it;
    }
}

void QueryMap(const std::string &family, svec_map familes)
{
    svec_map::const_iterator cit = familes.find(family);
    if (cit == familes.cend())
    {
        std::cerr << "sorry, family: " << family
            << " is not occurs int current map\n";
        return ;
    }

    std::cout << "the " << family << " family ";
    if (!cit->second.size())
        std::cout << "has no children!\n";

    else
    {
        std::cout << "has " << cit->second.size() << " childrens.\n";
        auto citer = cit->second.begin();
        while (citer != cit->second.end())
        {
            std::cout << "\t" << *citer << "\n";
            ++citer;
        }
    }
}

}
