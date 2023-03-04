

#include <algorithm>
#include "str.h"

using std::vector;
using std::string;
using std::find_if;
using std::equal;
using std::find;
using std::search;

namespace chapter_06
{

vector<string> Split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string>  ret;

    iter i = str.begin();
    while (i != str.end()) 
    {
        i = find_if(i, str.end(), NotSpace);

        iter j = find_if(i, str.end(), IsSpace);

        if (i != str.end()) 
            ret.push_back(string(i, j));

        i = j;
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
    static const string sep = "://";
    typedef string::const_iterator iter;

    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) 
    {
        if (i != b && i + sep.size() != e)      //不是单独的seq
        {
            iter beg = i;
            while (beg != b && isalpha(beg[-1])) 
                --beg;
            
            if (beg != i && !NotUrlChar(i[sep.size()]) && i + sep.size() != e)  // 前边有一个字符兵器后边有一个字符
                return beg;
        }
        
        i += sep.size();
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
            ret.push_back(string(b, after));

            b = after;
        }
    }
    
    return ret;
}

} // namespace chapter_06
