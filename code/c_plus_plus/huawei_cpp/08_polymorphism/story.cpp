
#include <iostream>

#include "story.h"

using namespace std;

std::string Book::GetContent()
{
    return "read content from book";
}

std::string Newspaper::GetContent()
{
    return "read content from newspaper";
}

void Person::TellStory(Reader *r)
{
    cout << r->GetContent() << endl;
}
