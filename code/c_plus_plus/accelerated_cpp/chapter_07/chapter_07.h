
#ifndef __ACCELERATED_CPP_CHAPTER_07_HPP__
#define __ACCELERATED_CPP_CHAPTER_07_HPP__

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "../chapter_06/str.h"

namespace chapter_07 {
std::map<std::string, std::vector<int>> Xref(std::istream &in,
        std::vector<std::string> (*FindWords)(const std::string &str) = chapter_06::Split);


typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleCollection;
typedef std::map<std::string, RuleCollection> Grammer;

Grammer ReadGrammer(std::istream &in);

std::vector<std::string> GenSentence(const Grammer &g);
bool bracteted(const std::string &s);
void GenAux(const Grammer &g, const std::string &s, std::vector<std::string> &ret);
int Nrand(int n);

}

#endif //__ACCELERATED_CPP_CHAPTER_07_HPP__
