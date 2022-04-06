

#include <algorithm>
#include "chapter05_str.h"

using std::vector;
using std::string;
using std::max;

namespace Chapter05
{
    vector<string> Split(const string &s)
    {
        vector<string> ret;
        typedef string::size_type StrSz;

        StrSz i = 0;
        while (i != s.size()) {
            while (i != s.size() && isspace(s[i])) 
                ++i;

            StrSz j = i;
            while (j != s.size() && !isspace(s[j])) 
                ++j;
            
            if (i != j) {
                ret.push_back(string(i, j - i));
            }
            i = j;
        }
        return ret;
    }

    string::size_type Width(const vector<string>& v)
    {
        string::size_type max_len = 0;
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            max_len = max(max_len, v[i].size());
        }
        
        return max_len;
    }

    vector<string> Frame(const vector<string>& v)
    {
        vector<string> ret;
        string::size_type max_len = Width(v);

        string border(max_len + 4, '*');
        ret.push_back(border);

        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            ret.push_back("* " + v[i] + string(max_len - v[i].size(), ' ') + " *");
        }
        ret.push_back(border);

        return ret;
    }

    vector<string> Vcat(const vector<string>& top, const vector<string>& bottom)
    {
        vector<string> ret = top;

        // for (vector<string>::size_type i = 0; i != bottom.size(); i++) {
        //     ret.push_back(bottom[i]);
        // }

        ret.insert(ret.end(), bottom.begin(), bottom.end());
        return ret;
    }

    vector<string> Hcat(const vector<string>& left, const vector<string>& right)
    {
        vector<string> ret;
        string::size_type width = Width(left) + 1;

        vector<string>::size_type i = 0, j = 0;
        while (i != left.size() || j != right.size()) {
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
} // namespace Chapter05

