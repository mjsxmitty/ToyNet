

#include <algorithm>
#include "chapter06_str.h"

using std::vector;
using std::string;
using std::find_if;
using std::equal;
using std::find;
using std::search;

namespace Chapter06
{
    bool IsSpace(char c){
        return isspace(c);
    }

    bool NotSpace(char c) {
        return !IsSpace(c);
    }

    vector<string> Split(const string& str)
    {
        typedef string::const_iterator Iter;
        vector<string>  ret;

        Iter i = str.begin();
        while (i != str.end()) {
            i = find_if(i, str.end(), NotSpace);

            Iter j = find_if(i, str.end(), IsSpace);

            if (i != str.end()) {
                ret.push_back(string(i, j));
            }
            i = j;
        }
        
        return ret;
    }

    bool IsPalindram(const string &s)
    {
        return equal(s.begin(), s.end(), s.rbegin());
    }

    bool NotUrlChar(char c){
        static const string url_ch = "~;/?:@=&$-_.+!*'(),";
        return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
    }

    string::const_iterator UrlEnd(string::const_iterator b, string::const_iterator e)
    {
        return find_if(b, e, NotUrlChar);
    }

    string::const_iterator UrlBeg(string::const_iterator b, string::const_iterator e)
    {
        static const string sep = "://";
        typedef string::const_iterator Iter;

        Iter i = b;
        while ((i = search(i, e, sep.begin(), sep.end())) != e) {
            //不是单独
            if (i != b && i + sep.size() != e) {
                Iter beg = i;
                while (beg != b && isalpha(beg[-1])) {
                    --beg;
                }
                
                if (beg != i && !NotUrlChar(i[sep.size()]) && i + sep.size() != e) {
                    return beg;
                }
            }
            
            i += sep.size();
        }
        return e;
    }

    vector<string> FindUrls(const string& s)
    {
        vector<string> ret;
        typedef string::const_iterator Iter;
        Iter b = s.begin(), e = s.end();

        while (b != e) {
            b = UrlBeg(b, e);

            if (b != e) {
                Iter after = UrlEnd(b, e);
                ret.push_back(string(b, after));

                b = after;
            }
        }
        
        return ret;
    }
} // namespace Chapter06
