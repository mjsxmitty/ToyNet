
#ifndef __CPP_PRIMER_CHAPTER_12_QUERY_RESULT_H__
#define __CPP_PRIMER_CHAPTER_12_QUERY_RESULT_H__

#include <set>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include "../chapter_13/str_vec.h"

class QueryResult
{
    friend std::ostream& PrintQueryResult(std::ostream &os, const QueryResult &result);
    typedef std::vector<std::string>::size_type line_no;
public:
    // QueryResult(const std::string &s,
    //             std::shared_ptr<std::set<line_no>> p,
    //             std::shared_ptr<std::vector<std::string>> f) :
    //     sought_word_(s), lines_(p), file_(f) {}
    QueryResult(const std::string &s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<StrVec> f) :
                sought_word_(s), lines_(p), file_(f) {}

private:
    std::string sought_word_;
    std::shared_ptr<std::set<line_no>>   lines_;
    //std::shared_ptr<std::vector<std::string>> file_;
    std::shared_ptr<StrVec> file_;
};

std::ostream& PrintQueryResult(std::ostream &os, const QueryResult &result);

#endif // __CPP_PRIMER_CHAPTER_12_QUERY_RESULT_H__
