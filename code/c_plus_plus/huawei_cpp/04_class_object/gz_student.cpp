
#include <iostream>
#include "gz_student.h"

using namespace std;

GZStudent* GZStudent::head_ = NULL;

GZStudent::GZStudent(const std::string &name) : name_(name)
{
    if (head_ == NULL)
    {
        head_ = this;
        head_->next_ = NULL;
    }
    else
    {
        this->next_ = head_;
        head_ = this;
    }
}

void GZStudent::PrintStudentList()
{
    GZStudent* p = head_;
    while (p != NULL)
    {
        cout << "name: " << p -> name_ << endl;
        p = p -> next_;
    }
}

void GZStudent::DeleteStudentList()
{
    GZStudent* p = head_;
    while (head_)
    {
        head_ = head_ -> next_;
        delete p;
        p = head_;
    }
}
