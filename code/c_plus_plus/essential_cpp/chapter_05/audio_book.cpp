#include "audio_book.h"



void AudioBook::Print() const
{
    std::cout << "AudioBook::Print() -- i am AudioBook object\n"
              << "My title is: " << title_
              << ", My name is: " << author_
              << ", My narrator is: " << narrator_
              << std::endl;
}
