

#ifndef __ESSENTIAL_CPP_AUDIO_BOOK_H__
#define __ESSENTIAL_CPP_AUDIO_BOOK_H__

#include <string>
#include "book.h"

namespace common
{

class AudioBook : public Book
{
public:
    AudioBook(const std::string &title, const std::string &author,
              const std::string &narrator) : Book(title, author),
                narrator_(narrator)
    {
        std::cout << "AudioBook::AudioBook() ( "
                  << title_ << ", "
                  << author_ << ", "
                  << narrator_ << " ) constructor"
                  << std::endl;
    }

    ~AudioBook()
    {
        std::cout << "AudioBook::~AudioBook() destructor\n";
    }

    void Print() const override;
private:
    std::string narrator_;
};

}
#endif // __ESSENTIAL_CPP_AUDIO_BOOK_H__
