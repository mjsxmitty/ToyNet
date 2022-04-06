
#include "quote.h"

#include <iostream>

using namespace std;

std::string Quote::isbn() const
{
    return book_no_;
}

double Quote::NetPrice(std::size_t n) const
{
    return n * price_;
}

void Quote::Debug() const
{
    cout << " book: " << book_no_
         << ", price: " << price_;
}