
#include "folder_message.h"

using namespace std;


Message::Message(const Message &rhs) : contents_(rhs.contents_) , folders_(rhs.folders_)
{
    AddToFolder(rhs);
}

Message::Message(Message &&m) : contents_(std::move(m.contents_))
{
    MoveFolders(&m);
}

Message& Message::operator=(const Message &rhs)
{
    RemoveFormFolder();
    folders_ = rhs.folders_;
    contents_ = rhs.contents_;
    AddToFolder(rhs);
    return *this;
}

Message::~Message()
{
    RemoveFormFolder();
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

void Message::AddToFolder(const Message &m)
{
    for (auto &f : m.folders_)
        f->AddMsg(this);
}

void Message::RemoveFormFolder()
{
    for (auto &f : folders_)
       f->RemMsg(this);

    folders_.clear();
    //TODO delete指针？ NULL
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

Folder::Folder(const Folder &f) : messages_(f.messages_)
{
    AddToMessage(f);
}

Folder::Folder(Folder &&f)
{
    MoveMessage(&f);
}

Folder& Folder::operator=(const Folder &f)
{
    RemoveFromMessage();
    messages_ = f.messages_;
    AddToMessage(f);
    return *this;
}

Folder& Folder::operator=(Folder &&f)
{
    if (this != &f)
    {
        RemoveFromMessage();
        MoveMessage(&f);
    }
    return *this;
}

void Folder::AddToMessage(const Folder &f)
{
    for (auto msg : f.messages_)
        msg->AddFolder(this);
}

void Folder::RemoveFromMessage()
{
    while (!messages_.empty())
        (*messages_.begin())->Remove(*this);
}

void Folder::Save(Message &m)
{
    messages_.insert(&m);
    m.AddFolder(this);
}

void Folder::Remove(Message &m)
{
    messages_.erase(&m);
    m.RemFolder(this);
}

void Folder::MoveMessage(Folder *f)
{
    messages_ = std::move(f->messages_);
    f->messages_.clear();

    for (auto m : messages_)
    {
        m->RemFolder(f);
        m->AddFolder(this);
    }
}

