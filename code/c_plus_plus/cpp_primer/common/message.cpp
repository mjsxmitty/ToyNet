
#include <utility>

#include "message.h"
#include "folder.h"

using namespace std;

Message::Message(const Message &rhs) : 
                contents_(rhs.contents_) , 
                folders_(rhs.folders_)
{
    AddToFolders(rhs);
}

Message::Message(Message &&m) : contents_(std::move(m.contents_))
{
    MoveFolders(&m);
}

Message& Message::operator=(const Message &rhs)
{
    RemoveFormFolders();
    folders_ = rhs.folders_;
    contents_ = rhs.contents_;
    AddToFolders(rhs);
    return *this;
}

Message& Message::operator=(Message&& rhs)
{
    if (this != &rhs)
    {
        RemoveFormFolders();
        contents_ = std::move(rhs.contents_);
        MoveFolders(&rhs);
    }

    return *this;
}

Message::~Message()
{
    RemoveFormFolders();
}

void Message::Save(Folder &f)
{
    folders_.insert(&f);
    f.AddMsg(this);
}

void Message::Remove(Folder &f)
{
    folders_.erase(&f);
    f.RemMsg(this);
}

void Message::AddToFolders(const Message &m)
{
    for (auto &f : m.folders_)
        f->AddMsg(this);
}

void Message::RemoveFormFolders()
{
    for (auto &f : folders_)
        f->RemMsg(this);
}

void Message::MoveFolders(Message *m)
{
    folders_ = std::move(m->folders_);
    for (auto &f : folders_)
    {
        f->RemMsg(m);
        f->AddMsg(this);
    }
    m->folders_.clear();   
}

void Swap(Message &lhs, Message &rhs)
{
    using std::swap;

    for (auto &f : lhs.folders_)
        f->RemMsg(&lhs);
    
    for (auto &f : rhs.folders_)
        f->RemMsg(&rhs);

    swap(lhs.contents_, rhs.contents_);
    swap(lhs.folders_, rhs.folders_);

    for (auto &f : lhs.folders_)
        f->AddMsg(&lhs);
    
    for (auto &f : rhs.folders_)
        f->AddMsg(&rhs);
}
