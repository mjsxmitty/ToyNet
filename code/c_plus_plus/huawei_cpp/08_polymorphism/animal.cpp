
#include <iostream>

#include "animal.h"

using namespace std;

Animal::Animal()
{
    cout << "Animal::Animal() ... " << endl;
}

Animal::~Animal()
{
    cout << "Animal::~Animal() ... " << endl;
}


Dog::Dog()
{
    cout << "Dog::Dog() ... " << endl;
}

Dog::~Dog()
{
    cout << "Dog::~Dog() ... " << endl;
}

void Dog::Voice()
{
    cout << "wang wang ... " << endl;
}

Cat::Cat()
{
    cout << "Cat::Cat() ... " << endl;
}

Cat::~Cat()
{
    cout << "Cat::~Cat() ... " << endl;
}

void Cat::Voice()
{
    cout << "miao miao ... " << endl;
}
