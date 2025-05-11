
#ifndef __ACCELERATED_CPP_GRAMMAR_HPP__
#define __ACCELERATED_CPP_GRAMMAR_HPP__

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "str_util.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleCollection;
typedef std::map<std::string, RuleCollection> Grammar;

extern Grammar ReadGrammar(std::istream &in);

extern std::vector<std::string> GenSentence(const Grammar &g);
extern bool bracketed(const std::string &s);
extern void GenAux(const Grammar &g, const std::string &s, std::vector<std::string> &ret);
extern int Nrand(int n);

#endif //__ACCELERATED_CPP_GRAMMAR_HPP__
