
#include <exception>
#include <cstdlib>

#include "chapter_07.h"

namespace chapter_07 {

std::map<std::string, std::vector<int>> Xref(std::istream &in,
                std::vector<std::string> (*FindWords)(const std::string &str))
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

Grammer ReadGrammer(std::istream &in)
{
    Grammer ret;
    std::string line;

    while (std::getline(in, line))
    {
        std::vector<std::string> entry = chapter_06::Split(line);
        if (!entry.empty())
        {
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }

    return ret;
}

std::vector<std::string> GenSentence(const Grammer &g)
{
    std::vector<std::string> ret;
    GenAux(g, "<sentence>", ret);
    return ret;
}

bool bracteted(const std::string &s)
{
    return (s.size() > 0 && s[0] == '<' && s[s.size() - 1] == '>');
}

void GenAux(const Grammer &g, const std::string &s, std::vector<std::string> &ret)
{
    if (!bracteted(s))
    {
        ret.push_back(s);
        return ;
    }

    Grammer::const_iterator citer = g.find(s);
    if (citer == g.end())
        throw std::logic_error("empty rule.");

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

}
