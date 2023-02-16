

#ifndef __ESSENTIAL_CPP_CHAPTER_05_BOOK_H__
#define __ESSENTIAL_CPP_CHAPTER_05_BOOK_H__

#include <iostream>
#include <string>
#include "libmat.h"

namespace chapter_05
{

class Book : public LibMat
{
public:
    Book(const std::string &title, const std::string &author) :
        title_(title), author_(author)
    {
        std::cout << "Book::Book() ( " << title_ << ", "
                  << author_ << " ) constructor " << std::endl;
    }
    virtual ~Book() { std::cout << "Book::~Book() destructor!\n"; }
public:
    void Print() const override
    {
        std::cout << "Book::Print() i am Book object"
                  << ", My title is: " << title_
                  << ", My name is: " << author_
                  << std::endl;
    }

    const std::string& title() const { return title_; }
    const std::string& author() const { return author_; }
protected:
    std::string     title_;
    std::string     author_;
};

}
#endif // __ESSENTIAL_CPP_CHAPTER_03_BOOK_H__
