
#include <algorithm>
#include <exception>
#include <cstdlib>

#include "str_util.h"

using namespace std;

vector<string> Split(const string &s)
{
#if 0
    vector<string> ret;
    typedef string::size_type StrSz;

    StrSz i = 0;
    while (i != s.size())
    {
        while (i != s.size() && isspace(s[i]))
            ++i;

        StrSz j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j)
        {
            ret.push_back(s.substr(i, j - i));
            //ret.push_back(string(i, j - i));
            i = j;
        }
    }

    return ret;
#endif
    typedef string::const_iterator iter;
    vector<string>  ret;

    iter i = s.begin();
    while (i != s.end())
    {
        i = find_if(i, s.end(), NotSpace);

        iter j = find_if(i, s.end(), IsSpace);

        if (i != s.end())
            ret.push_back(string(i, j));

        i = j;
    }

    return ret;
}

string::size_type Width(const vector<string> &v)
{
    string::size_type max_len = 0;
    for (vector<string>::size_type i = 0; i != v.size(); i++)
        max_len = max(max_len, v[i].size());

    return max_len;
}

vector<string> Frame(const vector<string> &v)
{
    vector<string> ret;
    string::size_type max_len = Width(v);

    string border(max_len + 4, '*');
    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); i++)
        ret.push_back("* " + v[i] + string(max_len - v[i].size(), ' ') + " *");

    ret.push_back(border);

    return ret;
}

vector<string> Vcat(const vector<string> &top, const vector<string> &bottom)
{
    vector<string> ret = top;
#if 0
    for (vector<string>::size_type i = 0; i != bottom.size(); i++) {
        ret.push_back(bottom[i]);
    }
#endif
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> Hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> ret;
    string::size_type width = Width(left) + 1;

    vector<string>::size_type i = 0, j = 0;
    while (i != left.size() || j != right.size())
    {
        string s;
        if (i != left.size())
            s = left[i++];

        s += string(width - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }

    return ret;
}

bool IsPalindrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

bool NotUrlChar(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator UrlEnd(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, NotUrlChar);
}

string::const_iterator UrlBeg(string::const_iterator b, string::const_iterator e)
{
    static const string seq = "://";
    typedef string::const_iterator iter;

    iter i = b;
    while ((i = search(i, e, seq.begin(), seq.end())) != e)
    {
        if (i != b && i + seq.size() != e)
        {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            if (beg != i && i + seq.size() != e && !NotUrlChar(i[seq.size()]))
                return beg;
        }

        if (i != e)
            i += seq.size();
    }

    return e;
}

vector<string> FindUrls(const string &s)
{
    vector<string> ret;
    typedef string::const_iterator iter;

    iter b = s.begin(), e = s.end();
    while (b != e)
    {
        b = UrlBeg(b, e);
        if (b != e)
        {
            iter after = UrlEnd(b, e);
            ret.push_back(string(b, e));
            b = after;
        }
    }

    return ret;
}

std::map<std::string, std::vector<int>> Xref(std::istream &in, std::vector<std::string> (*FindWords)(const std::string &str))
{
    std::string line;
    std::map<std::string, std::vector<int>> ret;
    int line_number = 0;

    while (std::getline(in, line))
    {
        ++line_number;

        std::vector<std::string> words = FindWords(line);
        for (auto &word : words)
        {
            ret[word].push_back(line_number);
        }
    }

    return ret;
}
