
#ifndef __CPP_PRIMER_PERSON_H__
#define __CPP_PRIMER_PERSON_H__

#include <string>
#include <iostream>

class Person
{
public:
    friend std::istream& Read(std::istream &in, Person &lhs);
    friend std::ostream& Print(std::ostream &out, const Person &lhs);
public:
    Person() = default;
    Person(const std::string &name, const std::string &addr) :
        name_(name), address_(addr) {}
    Person(std::istream &in);
public:
    std::string GetName() const { return name_; }
    std::string GetAddress() const { return  address_; }
private:
    std::string     name_;
    std::string     address_;
};

std::istream& Read(std::istream &in, Person &lhs);
std::ostream& Print(std::ostream &out, const Person &lhs);

#endif // __CPP_PRIMER_PERSON_H__
