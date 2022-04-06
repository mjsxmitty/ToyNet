


#ifndef __CPP_PRIMER_CHAPTER_14_H__
#define __CPP_PRIMER_CHAPTER_14_H__

#include <iostream>
#include <string>

void Chapter_14();

void Partice_14_8_2();
void Partice_14_8_3();
void Partice_14_9_1();

void Homework_14_35();
void Homework_14_37();
void Homework_14_38();
void Homework_14_39();

class IfElseThen
{
public:
    IfElseThen() = default;
    IfElseThen(int i1, int i2, int i3) : v1(i1), v2(i2), v3(i3) {}

    int operator()(int i1, int i2, int i3) { return v1 ? v2 : v3; }
    //~IfElseThen();
private:
    int v1, v2, v3;
};

class ReadString
{
public:
    ReadString(std::istream &in = std::cin) : in_(in) { std::cout << "Read construct." << std::endl;}
    std::string operator()()
    {
        std::string line;

        if (!getline(in_, line))
            line = "";
        return line;
    }
    //~PrintString();
private:
    std::istream& in_;
};

class PrintString
{
public:
    PrintString(std::ostream &os = std::cout, char c = ' ') : os_(os), c_(c) {}

    void operator()(const std::string &s) const { os_ << s << c_; }
private:
    std::ostream&   os_;
    char            c_;
};

class IntCompare
{
public:
    IntCompare(int v) : val(v) {}
    bool operator()(int v) { return v < val; }
    //~IntCompare();
private:
    int val;
};

class ShorterString
{
public:
    // ShorterString(/* args */);
    // ~ShorterString();
    bool operator()(const std::string &lhs, const std::string &rhs)
    {
        return lhs.size() < rhs.size();
    }
};

class SzieComp
{
public:
    // SzieComp(/* args */);
    // ~SzieComp();
    SzieComp(std::size_t n) : sz_(n) {}
    bool operator()(const std::string &s) const { return s.size() >= sz_; }
private:
    std::size_t sz_;
};

class StrLenIs
{
public:
    StrLenIs(int l) : len(l) {}
    bool operator()(const std::string &s) { return s.size() == len; }
    //~StrLenIs();
private:
    int len;
};

class StrLenBetween
{
public:
    StrLenBetween(int v1, int v2) : min_len_(v1), max_len_(v2) {}
    bool operator()(const std::string &str)
    {
        return str.length() >= min_len_ && str.length() <= max_len_;
    }
    //~StrLenBetween();
private:
    int min_len_;
    int max_len_;
};

class StrLongerThan
{
public:
    StrLongerThan(int len) : min_len(len) {}
    bool operator()(const std::string &s) { return s.length() >= min_len; }
    //~StrLongerThan();
private:
    int     min_len;
};

class SmallInt
{
public:
    SmallInt(std::size_t v) : val(v) {}
    explicit operator int() const { return val; }
    //~SmallInt();
private:
    std::size_t val;
};


#endif //