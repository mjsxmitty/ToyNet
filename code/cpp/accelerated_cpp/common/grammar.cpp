
#include <exception>
#include <cstdlib>
#include <iostream>

#include "str_util.h"
#include "grammar.h"

using namespace std;

Grammar ReadGrammar(istream &in)
{
    Grammar ret;
    string line;

    while (getline(in, line))
    {
        vector<string> entry = Split(line);
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }

    return ret;
}

vector<string> GenSentence(const Grammar &g)
{
    vector<string> ret;
    GenAux(g, "<sentences>", ret);
    return ret;
}

bool bracketed(const string &s)
{
    return (s.size() > 0 && s[0] == '<' && s[s.size() - 1] == '>');
}

void GenAux(const Grammar &g, const string &s, vector<string> &ret)
{
    if (!bracketed(s))
    {
        ret.push_back(s);
        return ;
    }

    Grammar::const_iterator citer = g.find(s);
    if (citer == g.end())
    {
        cout << "can not find: " << s << endl;
        return ;
    }

    const RuleCollection rc = citer->second;
    const Rule &r = rc[Nrand(rc.size())];
    for (Rule::const_iterator cit = r.begin(); cit != r.end(); ++cit)
    {
        GenAux(g, *cit, ret);
    }
}

int Nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("out of range.");

    const int bucket_size = RAND_MAX / n;

    int r = 0;
    do
        r = rand() / bucket_size;
    while (r >= n);

    return r;
}
