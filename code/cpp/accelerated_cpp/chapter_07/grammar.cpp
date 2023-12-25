
#include <exception>
#include <cstdlib>
#include <iostream>

#include "str_util.h"
#include "grammar.h"

Grammar ReadGrammar(std::istream &in)
{
    Grammar ret;
    std::string line;

    while (std::getline(in, line))
    {
        std::vector<std::string> entry = Split(line);
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end())); 
    }
    
    return ret;
}

std::vector<std::string> GenSentence(const Grammar &g)
{
    std::vector<std::string> ret;
    GenAux(g, "<sentences>", ret);
    return ret;
}

bool bracketed(const std::string &s)
{
    return (s.size() > 0 && s[0] == '<' && s[s.size() - 1] == '>');
}

void GenAux(const Grammar &g, const std::string &s, std::vector<std::string> &ret)
{
    if (!bracketed(s))
    {
        ret.push_back(s);
        return ;
    }

    Grammar::const_iterator citer = g.find(s);
    if (citer == g.end())
    {
        std::cout << "can not find: " << s << std::endl;
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
        throw std::domain_error("out of range.");

    const int bucket_size = RAND_MAX / n;

    int r = 0;
    do
        r = rand() / bucket_size;
    while (r >= n);

    return r;
}
