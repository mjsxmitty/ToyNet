
#ifndef __ACCELERATED_CPP_GRAMMAR_HPP__
#define __ACCELERATED_CPP_GRAMMAR_HPP__

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "str.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleCollection;
typedef std::map<std::string, RuleCollection> Grammar;

Grammar ReadGrammar(std::istream &in);

std::vector<std::string> GenSentence(const Grammar &g);
bool bracketed(const std::string &s);
void GenAux(const Grammar &g, const std::string &s, std::vector<std::string> &ret);
int Nrand(int n);


#endif //__ACCELERATED_CPP_GRAMMAR_HPP__
